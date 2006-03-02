#ifndef YAM_MIME_H
#define YAM_MIME_H

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

#include <stdio.h>

#include <proto/codesets.h>

#include "YAM_stringsizes.h"

// codesets.library helper functions
char *strippedCharsetName(const struct codeset* codeset);

// base64 encoding/decoding routines
int base64encode(char *to, const unsigned char *from, unsigned int len);
int base64decode(char *to, const unsigned char *from, unsigned int len);
long base64encode_file(FILE *in, FILE *out, BOOL convLF);
long base64decode_file(FILE *in, FILE *out,
                       struct codeset *srcCodeset, BOOL convCRLF);

// quoted-printable encoding/decoding routines
long qpencode_file(FILE *in, FILE *out);
long qpdecode_file(FILE *in, FILE *out, struct codeset *srcCodeset);

// uucode encoding/decoding routines
long uuencode_file(FILE *in, FILE *out);
long uudecode_file(FILE *in, FILE *out, struct codeset *srcCodeset);

// rfc2047 decoding routines
int rfc2047_encode_file(FILE *fh, const char *str);
int rfc2047_decode(char *dst, const char *src, unsigned int maxlen);

#endif /* YAM_MIME_H */
