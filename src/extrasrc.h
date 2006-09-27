#ifndef EXTRASRC_H
#define EXTRASRC_H

/***************************************************************************

 YAM - Yet Another Mailer
 Copyright (C) 1995-2000 by Marcel Beck <mbeck@yam.ch>
 Copyright (C) 2000-2006 by YAM Open Source Team

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

#include <proto/intuition.h>

#include "SDI_compiler.h"

/*
 * Differentations between runtime libs and operating system
 */
#if (defined(__mc68000) && (defined(__ixemul) || defined(__libnix))) || defined(__SASC)

#if !defined(HAVE_STRLCPY)
#define NEED_STRLCPY
#endif

#if !defined(HAVE_STRLCAT)
#define NEED_STRLCAT
#endif

#if !defined(HAVE_STRTOK_R)
#define NEED_STRTOK_R
#endif

#endif /* m68k && !clib2 || __SASC */

#if !defined(__MORPHOS__) || !defined(__libnix)

#if !defined(HAVE_STCGFE)
#define NEED_STCGFE
#endif

#if !defined(HAVE_STRMFP)
#define NEED_STRMFP
#endif

#if !defined(HAVE_DOSUPERNEW)
#define NEED_DOSUPERNEW
#endif

#endif /* !__MORPHOS__ || !__libnix */

/*
 * Differentations between compilers
 */
#if defined(__VBCC__)

#if !defined(HAVE_STRDUP)
#define NEED_STRDUP
#endif

#if !defined(HAVE_STRTOK_R)
#define NEED_STRTOK_R
#endif

#endif /* __VBCC__ */

#if !defined(__SASC)

#if !defined(HAVE_VASTUBS)
#define NEED_VASTUBS
#endif

#endif /* !__SASC */


#if !defined(__GNUC__)

#if !defined(HAVE_XGET)
#define NEED_XGET
#endif

#endif /* !__GNUC__ */

/*
 * Stuff we always require
 */
#if !defined(HAVE_NEWREADARGS)
#define NEED_NEWREADARGS
#endif

/*
 * Function prototypes
 */
#if defined(NEED_STRLCPY)
size_t strlcpy(char *, const char *, size_t);
#endif

#if defined(NEED_STRLCAT)
size_t strlcat(char *, const char *, size_t);
#endif

#if defined(NEED_STRTOK_R)
char *strtok_r(char *, const char *, char **);
#endif

#if defined(NEED_STCGFE)
int stcgfe(char *, const char *);
#endif

#if defined(NEED_STRMFP)
void strmfp(char *, const char *, const char *);
#endif

#if defined(NEED_STRDUP)
char *strdup(const char *);
#endif

#if defined(NEED_XGET)
ULONG xget(Object *obj, const ULONG attr);
#endif

#if defined(NEED_DOSUPERNEW)
Object * VARARGS68K DoSuperNew(struct IClass *cl, Object *obj, ...);
#endif


/*
 * Additional defines
 */
#if defined(__VBCC__)

  #define isascii(c) (((c) & ~0177) == 0)
  #define stricmp(s1, s2) strcasecmp((s1), (s2))
  #define strnicmp(s1, s2, len) strncasecmp((s1), (s2), (len))

#endif /* __VBCC__ */

#endif /* EXTRASRC_H */
