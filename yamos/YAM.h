#ifndef MAIN_YAM_H
#define MAIN_YAM_H

/***************************************************************************

 YAM - Yet Another Mailer
 Copyright (C) 1995-2000 by Marcel Beck <mbeck@yam.ch>
 Copyright (C) 2000-2004 by YAM Open Source Team

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 YAM Official Support Site :  http://www.yam.ch
 YAM OpenSource project    :  http://sourceforge.net/projects/yamos/

 $Id$

***************************************************************************/

#include <dos/notify.h>
#include <exec/types.h>
#include <libraries/asl.h>
#include <libraries/mui.h>
#include <proto/bsdsocket.h>

#include "YAM_rexx_rxif.h"   /* struct RuleResult */
#include "YAM_stringsizes.h"
#include "YAM_transfer.h"    /* struct DownloadResult */
#include "YAM_userlist.h"    /* struct Users */

/**************************************************************************/

enum GlobalDispatcherJob { ID_CLOSEALL=1000, ID_RESTART, ID_ICONIFY, ID_LOGIN };

// all the different timerIOs YAM is using
enum TimerIO { TIO_WRINDEX=0,
               TIO_CHECKMAIL,
               TIO_AUTOSAVE,
               TIO_READPANEUPDATE,
               TIO_READSTATUSUPDATE
             };

/*** Global Structure ***/
struct Global 
{
   /* pointers first */
   Object *                 App;
   Object *                 WI_SEARCH;
   Object *                 NewMailSound_Obj;
   Object *                 SplashWinObject;
   Object *                 AboutWinObject;
   char *                   ER_Message[MAXERR];
   struct DiskObject *      HideIcon;
   struct AppIcon *         AppIcon;
   struct MsgPort *         AppPort;
   struct RexxHost *        RexxHost;
   struct DiskObject *      DiskObj[MAXICONS];
   struct BodyChunkData *   BImage[MAXIMAGES];
   struct FileRequester *   ASLReq[MAXASL];
   struct Locale *          Locale;
   struct TranslationTable *TTin;
   struct TranslationTable *TTout;
   struct MA_ClassData *    MA;
   struct CO_ClassData *    CO;
   struct AB_ClassData *    AB;
   struct EA_ClassData *    EA[MAXEA];
   struct WR_ClassData *    WR[MAXWR+1];
   struct TR_ClassData *    TR;
   struct ER_ClassData *    ER;
   struct FI_ClassData *    FI;
   struct FO_ClassData *    FO;
   struct DI_ClassData *    DI;
   struct US_ClassData *    US;
   struct ReadMailData *    ActiveRexxRMData;

   LONG                     EdColMap[16];
   LONG                     Weights[12];
   LONG                     TR_Socket;

   int                      PGPVersion;
   int                      CO_DST;
   int                      ER_NumErr;
   int                      ActiveWriteWin;

   BOOL                     Error;
   BOOL                     PGP5;
   BOOL                     AppIconQuiet;
   BOOL                     PGPPassVolatile;
   BOOL                     CO_Valid;
   BOOL                     TR_Debug;
   BOOL                     TR_Allow;
   BOOL                     TR_Exchange;
   BOOL                     TR_UseableTLS;
   BOOL                     TR_UseTLS;
   BOOL                     CO_AutoTranslateIn;
   BOOL                     InStartupPhase;
   BOOL                     NoImageWarning;

   struct DateStamp         StartDate;
   struct Users             Users;
   struct RuleResult        RRs;
   struct DownloadResult    LastDL;
   struct NotifyRequest     WR_NRequest[MAXWR+1];
   struct sockaddr_in       TR_INetSocketAddr;

   struct MinList           readMailDataList;

   char                     ProgDir[SIZE_PATH];
   char                     ProgName[SIZE_FILE];
   char                     PGPPassPhrase[SIZE_DEFAULT];
   char                     MA_MailDir[SIZE_PATH];
   char                     AB_Filename[SIZE_PATHFILE];
   char                     CO_PrefsFile[SIZE_PATHFILE];
   char                     WR_Filename[MAXWR+1][SIZE_PATHFILE];
   char                     DI_Filename[SIZE_PATHFILE];
};

extern struct Global *G;

void TC_Start(enum TimerIO tio, int seconds, int micros);
void TC_Stop(enum TimerIO tio);
void PopUp(void);
void SetupAppIcons(void);

#endif /* MAIN_YAM_H */
