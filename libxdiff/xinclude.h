/*
 *  LibXDiff by Davide Libenzi ( File Differential Library )
 *  Copyright (C) 2003  Davide Libenzi
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Davide Libenzi <davidel@xmailserver.org>
 *  autoconf removal and code simplification 2024 olikraus@gmail.com
 *
 */

#if !defined(XINCLUDE_H)
#define XINCLUDE_H

/* Name of package */
#define PACKAGE "libxdiff"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "libxdiff"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "libxdiff 0.23"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "libxdiff"

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.23"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#include "xmacros.h"
#include "xdiff.h"
#include "xtypes.h"
#include "xutils.h"
#include "xadler32.h"
#include "xprepare.h"
#include "xdiffi.h"
#include "xemit.h"
#include "xbdiff.h"

#endif /* #if !defined(XINCLUDE_H) */

