#ifndef _PPCINLINE_XPKMASTER_H
#define _PPCINLINE_XPKMASTER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif

#ifndef XPKMASTER_BASE_NAME
#define XPKMASTER_BASE_NAME XpkBase
#endif

#define XpkExamine(fib, tags) \
	LP2(0x24, LONG, XpkExamine, struct XpkFib *, fib, a0, struct TagItem *, tags, a1, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkExamineTags(fib, tags...) \
	({ULONG _tags[] = {tags}; XpkExamine((fib), (struct TagItem *) _tags);})

#define XpkPack(tags) \
	LP1(0x2a, LONG, XpkPack, struct TagItem *, tags, a0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkPackTags(tags...) \
	({ULONG _tags[] = {tags}; XpkPack((struct TagItem *) _tags);})

#define XpkUnpack(tags) \
	LP1(0x30, LONG, XpkUnpack, struct TagItem *, tags, a0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkUnpackTags(tags...) \
	({ULONG _tags[] = {tags}; XpkUnpack((struct TagItem *) _tags);})


#define XpkOpen(xbuf, tags) \
	LP2(0x36, LONG, XpkOpen, struct XpkFib **, xbuf, a0, struct TagItem *, tags, a1, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkOpenTags(xbuf, tags...) \
	({ULONG _tags[] = {tags}; XpkOpen((xbuf), (struct TagItem *) _tags);})


#define XpkRead(xbuf, buf, len) \
	LP3(0x3c, LONG, XpkRead, struct XpkFib *, xbuf, a0, STRPTR, buf, a1, ULONG, len, d0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkWrite(xbuf, buf, len) \
	LP3(0x42, LONG, XpkWrite, struct XpkFib *, xbuf, a0, STRPTR, buf, a1, LONG, len, d0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkSeek(xbuf, len, mode) \
	LP3(0x48, LONG, XpkSeek, struct XpkFib *, xbuf, a0, LONG, len, d0, LONG, mode, d1, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkClose(xbuf) \
	LP1(0x4e, LONG, XpkClose, struct XpkFib *, xbuf, a0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkQuery(tags) \
	LP1(0x54, LONG, XpkQuery, struct TagItem *, tags, a0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkQueryTags(tags...) \
	({ULONG _tags[] = {tags}; XpkQuery((struct TagItem *) _tags);})


#define XpkAllocObject(type, tags) \
	LP2(0x5a, APTR, XpkAllocObject, ULONG, type, d0, struct TagItem *, tags, a0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkAllocObjectTags(type, tags...) \
	({ULONG _tags[] = {tags}; XpkAllocObject((type), (struct TagItem *) _tags);})

#define XpkFreeObject(type, object) \
	LP2NR(0x60, XpkFreeObject, ULONG, type, d0, APTR, object, a0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkPrintFault(code, header) \
	LP2(0x66, BOOL, XpkPrintFault, LONG, code, d0, STRPTR, header, a0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkFault(code, header, buffer, size) \
	LP4(0x6c, ULONG, XpkFault, LONG, code, d0, STRPTR, header, a0, STRPTR, buffer, a1, ULONG, size, d1, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkPassRequest(tags) \
	LP1(0x72, LONG, XpkPassRequest, struct TagItem *, tags, a0, \
	, XPKMASTER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpkPassRequestTags(tags...) \
	({ULONG _tags[] = {tags}; XpkPassRequest((struct TagItem *) _tags);})

#endif /*  _PPCINLINE_XPKMASTER_H  */
