#ifndef CODESETS_INTERFACE_DEF_H
#define CODESETS_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 51.8.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef LIBRARIES_CODESETS_H
#include <libraries/codesets.h>
#endif

struct CodesetsIFace
{
  struct InterfaceData Data;

  ULONG APICALL (*Obtain)(struct CodesetsIFace *Self);
  ULONG APICALL (*Release)(struct CodesetsIFace *Self);
  void APICALL (*Expunge)(struct CodesetsIFace *Self);
  struct Interface * APICALL (*Clone)(struct CodesetsIFace *Self);
  void APICALL (*Reserved1)(struct CodesetsIFace *Self);
  ULONG APICALL (*CodesetsConvertUTF32toUTF16)(struct CodesetsIFace *Self, const UTF32 ** sourceStart, const UTF32 * sourceEnd, UTF16 ** targetStart, UTF16 * targetEnd, ULONG flags);
  ULONG APICALL (*CodesetsConvertUTF16toUTF32)(struct CodesetsIFace *Self, const UTF16 ** sourceStart, const UTF16 * sourceEnd, UTF32 ** targetStart, UTF32 * targetEnd, ULONG flags);
  ULONG APICALL (*CodesetsConvertUTF16toUTF8)(struct CodesetsIFace *Self, const UTF16 ** sourceStart, const UTF16 * sourceEnd, UTF8 ** targetStart, UTF8 * targetEnd, ULONG flags);
  BOOL APICALL (*CodesetsIsLegalUTF8)(struct CodesetsIFace *Self, const UTF8 * source, ULONG length);
  BOOL APICALL (*CodesetsIsLegalUTF8Sequence)(struct CodesetsIFace *Self, const UTF8 * source, const UTF8 * sourceEnd);
  ULONG APICALL (*CodesetsConvertUTF8toUTF16)(struct CodesetsIFace *Self, const UTF8 ** sourceStart, const UTF8 * sourceEnd, UTF16 ** targetStart, UTF16 * targetEnd, ULONG flags);
  ULONG APICALL (*CodesetsConvertUTF32toUTF8)(struct CodesetsIFace *Self, const UTF32 ** sourceStart, const UTF32 * sourceEnd, UTF8 ** targetStart, UTF8 * targetEnd, ULONG flags);
  ULONG APICALL (*CodesetsConvertUTF8toUTF32)(struct CodesetsIFace *Self, const UTF8 ** sourceStart, const UTF8 * sourceEnd, UTF32 ** targetStart, UTF32 * targetEnd, ULONG flags);
  struct codeset * APICALL (*CodesetsSetDefaultA)(struct CodesetsIFace *Self, STRPTR name, struct TagItem * attrs);
  struct codeset * APICALL (*CodesetsSetDefault)(struct CodesetsIFace *Self, STRPTR name, ...);
  void APICALL (*CodesetsFreeA)(struct CodesetsIFace *Self, APTR obj, struct TagItem * attrs);
  void APICALL (*CodesetsFree)(struct CodesetsIFace *Self, APTR obj, ...);
  STRPTR * APICALL (*CodesetsSupportedA)(struct CodesetsIFace *Self, struct TagItem * attrs);
  STRPTR * APICALL (*CodesetsSupported)(struct CodesetsIFace *Self, ...);
  struct codeset * APICALL (*CodesetsFindA)(struct CodesetsIFace *Self, STRPTR name, struct TagItem * attrs);
  struct codeset * APICALL (*CodesetsFind)(struct CodesetsIFace *Self, STRPTR name, ...);
  struct codeset * APICALL (*CodesetsFindBestA)(struct CodesetsIFace *Self, struct TagItem * attrs);
  struct codeset * APICALL (*CodesetsFindBest)(struct CodesetsIFace *Self, ...);
  ULONG APICALL (*CodesetsUTF8Len)(struct CodesetsIFace *Self, const UTF8 * str);
  STRPTR APICALL (*CodesetsUTF8ToStrA)(struct CodesetsIFace *Self, struct TagItem * attrs);
  STRPTR APICALL (*CodesetsUTF8ToStr)(struct CodesetsIFace *Self, ...);
  UTF8 * APICALL (*CodesetsUTF8CreateA)(struct CodesetsIFace *Self, struct TagItem * attrs);
  UTF8 * APICALL (*CodesetsUTF8Create)(struct CodesetsIFace *Self, ...);
  ULONG APICALL (*CodesetsEncodeB64A)(struct CodesetsIFace *Self, struct TagItem * attrs);
  ULONG APICALL (*CodesetsEncodeB64)(struct CodesetsIFace *Self, ...);
  ULONG APICALL (*CodesetsDecodeB64A)(struct CodesetsIFace *Self, struct TagItem * attrs);
  ULONG APICALL (*CodesetsDecodeB64)(struct CodesetsIFace *Self, ...);
  ULONG APICALL (*CodesetsStrLenA)(struct CodesetsIFace *Self, STRPTR str, struct TagItem * attrs);
  ULONG APICALL (*CodesetsStrLen)(struct CodesetsIFace *Self, STRPTR str, ...);
  BOOL APICALL (*CodesetsIsValidUTF8)(struct CodesetsIFace *Self, STRPTR str);
  void APICALL (*CodesetsFreeVecPooledA)(struct CodesetsIFace *Self, APTR pool, APTR mem, struct TagItem * attrs);
  void APICALL (*CodesetsFreeVecPooled)(struct CodesetsIFace *Self, APTR pool, APTR mem, ...);
  STRPTR APICALL (*CodesetsConvertStrA)(struct CodesetsIFace *Self, struct TagItem * attrs);
  STRPTR APICALL (*CodesetsConvertStr)(struct CodesetsIFace *Self, ...);
  struct codesetList * APICALL (*CodesetsListCreateA)(struct CodesetsIFace *Self, struct TagItem * attrs);
  struct codesetList * APICALL (*CodesetsListCreate)(struct CodesetsIFace *Self, ...);
  BOOL APICALL (*CodesetsListDeleteA)(struct CodesetsIFace *Self, struct TagItem * attrs);
  BOOL APICALL (*CodesetsListDelete)(struct CodesetsIFace *Self, ...);
  BOOL APICALL (*CodesetsListAddA)(struct CodesetsIFace *Self, struct codesetList * codesetsList, struct TagItem * attrs);
  BOOL APICALL (*CodesetsListAdd)(struct CodesetsIFace *Self, struct codesetList * codesetsList, ...);
  BOOL APICALL (*CodesetsListRemoveA)(struct CodesetsIFace *Self, struct TagItem * attrs);
  BOOL APICALL (*CodesetsListRemove)(struct CodesetsIFace *Self, ...);
};

#endif /* CODESETS_INTERFACE_DEF_H */
