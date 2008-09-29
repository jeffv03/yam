/***************************************************************************

 YAM - Yet Another Mailer
 Copyright (C) 1995-2000 by Marcel Beck <mbeck@yam.ch>
 Copyright (C) 2000-2008 by YAM Open Source Team

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 YAM Official Support Site : http://www.yam.ch
 YAM OpenSource project    : http://sourceforge.net/projects/yamos/

 $Id$

 Superclass:  MUIC_Group
 Description: Provides GUI elements and routines for showing the currently
              available themes for YAM.

***************************************************************************/

#include "ThemeListGroup_cl.h"

#include "extrasrc.h"

#include "MUIObjects.h"
#include "Requesters.h"

#include "Debug.h"

/* CLASSDATA
struct Data
{
  Object *NL_THEMELIST;
  Object *TX_THEMELABEL;
  Object *GR_PREVIEW;
  Object *IM_PREVIEW;
  Object *BT_ACTIVATE;
  Object *TX_AUTHOR;
  Object *TX_URL;
};
*/

/* Hooks */
/// ConstructHook
HOOKPROTONHNO(ConstructFunc, struct Theme *, struct Theme *e)
{
  struct Theme *entry;

  ENTER();

  entry = _memdup(e, sizeof(*e));

  RETURN(entry);
  return entry;
}
MakeStaticHook(ConstructHook, ConstructFunc);

///
/// DestructHook
//  destruction hook
HOOKPROTONHNO(DestructFunc, LONG, struct Theme *entry)
{
  FreeTheme(entry);
  return 0;
}
MakeStaticHook(DestructHook, DestructFunc);

///
/// DisplayHook
HOOKPROTONHNO(DisplayFunc, LONG, struct NList_DisplayMessage *msg)
{
  struct Theme *entry;
  char **array;

  if(!msg)
    return 0;

  // now we set our local variables to the DisplayMessage structure ones
  entry = (struct Theme *)msg->entry;
  array = msg->strings;

  if(entry)
  {
    array[0] = FilePart(entry->directory);

    if(stricmp(array[0], CE->ThemeName) == 0)
      msg->preparses[0] = (char *)"\033b";
  }

  return 0;
}
MakeStaticHook(DisplayHook, DisplayFunc);

///
/// CompareHook
HOOKPROTONHNO(CompareFunc, LONG, struct NList_CompareMessage *msg)
{
  struct Theme *theme1 = (struct Theme *)msg->entry1;
  struct Theme *theme2 = (struct Theme *)msg->entry2;

  return stricmp(FilePart(theme1->directory), FilePart(theme2->directory));
}
MakeStaticHook(CompareHook, CompareFunc);

///

/* Private Functions */

/* Overloaded Methods */
/// OVERLOAD(OM_NEW)
OVERLOAD(OM_NEW)
{
  Object *themeListObject;
  Object *themeTextObject;
  Object *previewImageObject;
  Object *imageGroupObject;
  Object *activateButtonObject;
  Object *authorTextObject;
  Object *urlTextObject;

  ENTER();

  obj = DoSuperNew(cl, obj,
          MUIA_Group_Horiz,       TRUE,
          MUIA_ContextMenu,       FALSE,

          Child, VGroup,
            MUIA_FixWidth, 100,

            Child, NListviewObject,
              MUIA_CycleChain, TRUE,
              MUIA_NListview_NList, themeListObject = NListObject,
                InputListFrame,
                MUIA_NList_Format,        "",
                MUIA_NList_Title,         FALSE,
                MUIA_NList_DragType,      MUIV_NList_DragType_None,
                MUIA_NList_ConstructHook, &ConstructHook,
                MUIA_NList_DestructHook,  &DestructHook,
                MUIA_NList_DisplayHook2,  &DisplayHook,
                MUIA_NList_CompareHook2,  &CompareHook,
              End,
            End,

            Child, activateButtonObject = MakeButton(tr(MSG_CO_THEME_ACTIVATE)),
          End,

          Child, VGroup,
            Child, themeTextObject = TextObject,
              MUIA_Text_PreParse, "\033b\033c",
            End,

            Child, RectangleObject,
              MUIA_Rectangle_HBar, TRUE,
              MUIA_FixHeight,      4,
            End,

            Child, HGroup,
              Child, HSpace(0),
              Child, TextObject,
                MUIA_Text_Contents, tr(MSG_CO_THEME_PREVIEW),
                MUIA_Font,          MUIV_Font_Tiny,
                MUIA_HorizWeight,   0,
              End,
              Child, HSpace(0),
            End,

            Child, HVSpace,

            Child, HGroup,
              Child, HSpace(0),

              Child, imageGroupObject = VGroup,
                Child, previewImageObject = ImageAreaObject,
                  MUIA_ImageArea_ShowLabel,   FALSE,
                  MUIA_ImageArea_MaxWidth,    300,
                  MUIA_ImageArea_MaxHeight,   200,
                  MUIA_ImageArea_NoMinHeight, FALSE,
                End,
              End,

              Child, HSpace(0),
            End,

            Child, HVSpace,

            Child, RectangleObject,
              MUIA_Rectangle_HBar, TRUE,
              MUIA_FixHeight,      4,
            End,

            Child, ColGroup(2),
              Child, Label2(tr(MSG_CO_THEME_AUTHOR)),
              Child, authorTextObject = TextObject,
                TextFrame,
                MUIA_Background,  MUII_TextBack,
                MUIA_Text_SetMin, TRUE,
              End,

              Child, Label2(tr(MSG_CO_THEME_URL)),
              Child, urlTextObject = TextObject,
                TextFrame,
                MUIA_Background,  MUII_TextBack,
                MUIA_Text_SetMin, TRUE,
              End,
            End,
          End,

        TAG_MORE, inittags(msg));

  if(obj != NULL)
  {
    GETDATA;

    data->NL_THEMELIST = themeListObject;
    data->TX_THEMELABEL = themeTextObject;
    data->GR_PREVIEW = imageGroupObject;
    data->IM_PREVIEW = previewImageObject;
    data->BT_ACTIVATE = activateButtonObject;
    data->TX_AUTHOR = authorTextObject;
    data->TX_URL = urlTextObject;

    // set notifies
    DoMethod(themeListObject,      MUIM_Notify, MUIA_NList_SelectChange, TRUE, obj, 1, MUIM_ThemeListGroup_SelectionChanged);
    DoMethod(themeListObject,      MUIM_Notify, MUIA_NList_DoubleClick, MUIV_EveryTime, obj, 1, MUIM_ThemeListGroup_ActivateTheme);
    DoMethod(activateButtonObject, MUIM_Notify, MUIA_Pressed, FALSE, obj, 1, MUIM_ThemeListGroup_ActivateTheme);
  }

  RETURN((ULONG)obj);
  return (ULONG)obj;
}
///

/* Public Methods */
/// DECLARE(Update)
DECLARE(Update)
{
  GETDATA;
  BOOL result = FALSE;
  char themesDir[SIZE_PATH];
  APTR context;

  ENTER();

  // clear the NList
  DoMethod(data->NL_THEMELIST, MUIM_NList_Clear);

  // construct the themes directory path
  AddPath(themesDir, G->ProgDir, "Themes", sizeof(themesDir));

  // prepare for an ExamineDir()
  if((context = ObtainDirContextTags(EX_StringName, (ULONG)themesDir, TAG_DONE)) != NULL)
  {
    struct ExamineData *ed;

    // iterate through the entries of the Themes directory
    while((ed = ExamineDir(context)) != NULL)
    {
      // check that this entry is a drawer
      // because we don't accept any file here
      if(EXD_IS_DIRECTORY(ed))
      {
        struct Theme theme;
        char filename[SIZE_PATHFILE];

        D(DBF_CONFIG, "found dir '%s' in themes drawer", ed->Name);

        // clear our temporary themes structure
        memset(&theme, 0, sizeof(struct Theme));

        // now we check whether this is a drawer which contains a
        // ".theme" file which should be a sign that this is a YAM theme
        AddPath(theme.directory, themesDir, ed->Name, sizeof(theme.directory));
        AddPath(filename, theme.directory, ".theme", sizeof(filename));

        // parse the .theme file to check wheter this
        // is a valid theme or not.
        if(ParseThemeFile(filename, &theme) > 0)
        {
          D(DBF_CONFIG, "found valid .theme file '%s'", filename);

          // add the theme to our NList which in fact will allocate/free everything the
          // ParseThemeFile() function did allocate previously.
          DoMethod(data->NL_THEMELIST, MUIM_NList_InsertSingle, &theme, MUIV_NList_Insert_Sorted);

          result = TRUE;
        }
        else
        {
          W(DBF_CONFIG, "couldn't parse .theme file '%s'", filename);
          FreeTheme(&theme);
        }
      }
      else
        W(DBF_CONFIG, "unknown file '%s' in themes directory ignored", ed->Name);
    }

    if(IoErr() != ERROR_NO_MORE_ENTRIES)
      E(DBF_CONFIG, "ExamineDir() failed");

    // now we have to check which item we should set active
    if(xget(data->NL_THEMELIST, MUIA_NList_Entries) > 1)
    {
      // walk through our list and check if the theme is the currently
      // active one, and if so we go and make it the currently selected one.
      ULONG pos;
      BOOL found = FALSE;
      for(pos=0;;pos++)
      {
        struct Theme *theme = NULL;

        DoMethod(data->NL_THEMELIST, MUIM_NList_GetEntry, pos, &theme);
        if(theme == NULL)
          break;

        if(stricmp(FilePart(theme->directory), CE->ThemeName) == 0)
        {
          set(data->NL_THEMELIST, MUIA_NList_Active, pos);
          found = TRUE;
          break;
        }
      }

      if(found == FALSE)
        set(data->NL_THEMELIST, MUIA_NList_Active, MUIV_NList_Active_Top);
    }
    else
      set(data->NL_THEMELIST, MUIA_NList_Active, MUIV_NList_Active_Top);

    ReleaseDirContext(context);
  }
  else
    E(DBF_CONFIG, "No themes directory found!");

  RETURN(result);
  return result;
}
///
/// DECLARE(SelectionChanged)
DECLARE(SelectionChanged)
{
  GETDATA;
  struct Theme *theme = NULL;

  ENTER();

  // get the currently selected entry
  DoMethod(data->NL_THEMELIST, MUIM_NList_GetEntry, MUIV_NList_GetEntry_Active, &theme);
  if(theme != NULL)
  {
    char buf[SIZE_DEFAULT];

    if(DoMethod(data->GR_PREVIEW, MUIM_Group_InitChange))
    {
      char filename[SIZE_PATHFILE];

      AddPath(filename, theme->directory, "preview", sizeof(filename));

      // set the new attributes, the old image will be deleted from the cache
      xset(data->IM_PREVIEW, MUIA_ImageArea_ID,       filename,
                             MUIA_ImageArea_Filename, filename);

      // and force a cleanup/setup pair
      DoMethod(data->GR_PREVIEW, OM_REMMEMBER, data->IM_PREVIEW);
      DoMethod(data->GR_PREVIEW, OM_ADDMEMBER, data->IM_PREVIEW);

      DoMethod(data->GR_PREVIEW, MUIM_Group_ExitChange);
    }

    snprintf(buf, sizeof(buf), "%s - %s", theme->name, theme->version);
    set(data->TX_THEMELABEL, MUIA_Text_Contents, buf);
    set(data->TX_AUTHOR, MUIA_Text_Contents, theme->author);
    set(data->TX_URL, MUIA_Text_Contents, theme->url);
  }

  RETURN(0);
  return 0;
}
///
/// DECLARE(ActivateTheme)
DECLARE(ActivateTheme)
{
  GETDATA;
  struct Theme *theme = NULL;

  ENTER();

  // get the currently selected entry
  DoMethod(data->NL_THEMELIST, MUIM_NList_GetEntry, MUIV_NList_GetEntry_Active, &theme);
  if(theme != NULL)
  {
    char *themeName = FilePart(theme->directory);

    // check that this theme isn't already the
    // active one.
    if(stricmp(themeName, CE->ThemeName) != 0)
    {
      // now we activate the theme and we warn the user about
      // the fact that a restart is required for the new theme to
      // be activated.
      strlcpy(CE->ThemeName, themeName, sizeof(CE->ThemeName));

      // redraw the NList.
      DoMethod(data->NL_THEMELIST, MUIM_NList_Redraw, MUIV_NList_Redraw_All);

      // remind the users to save the configuration and
      // restart yam.
      MUI_Request(G->App, G->CO->GUI.WI, 0, tr(MSG_ER_THEME_ACTIVATED_TITLE),
                                            tr(MSG_Okay),
                                            tr(MSG_ER_THEME_ACTIVATED));
    }
    else
      W(DBF_THEME, "theme '%s' is already the currently active one!", themeName);
  }

  RETURN(0);
  return 0;
}
///
