/*
 * This file was generated automatically by xsubpp version 1.9508 from the
 * contents of Gestalt.xs. Do not edit this file, edit Gestalt.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Gestalt.xs"
/* $Header: /cvsroot/macperl/perl/macos/ext/Mac/Gestalt/Gestalt.xs,v 1.3 2002/11/13 02:04:51 pudge Exp $
 *
 *    Copyright (c) 1996 Matthias Neeracher
 *
 *    You may distribute under the terms of the Perl Artistic License,
 *    as specified in the README file.
 *
 * $Log: Gestalt.xs,v $
 * Revision 1.3  2002/11/13 02:04:51  pudge
 * Aieeeeee!  Big ol' Carbon update.
 *
 * Revision 1.2  2000/09/09 22:18:26  neeri
 * Dynamic libraries compile under 5.6
 *
 * Revision 1.1  2000/08/14 03:39:30  neeri
 * Checked into Sourceforge
 *
 * Revision 1.2  1997/11/18 00:52:26  neeri
 * MacPerl 5.1.5
 *
 * Revision 1.1  1997/04/07 20:49:45  neeri
 * Synchronized with MacPerl 5.1.4a1
 *
 */

#define MAC_CONTEXT

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#ifndef MACOS_TRADITIONAL
#include "../Carbon.h"
#endif
#include <Gestalt.h>

#line 46 "Gestalt.c"
XS(XS_Mac__Gestalt_Gestalt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Gestalt_Gestalt)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Gestalt::Gestalt(selector)");
    {
	OSType	selector;
	long	RETVAL;
	dXSTARG;

	memcpy(&selector, SvPV_nolen(ST(0)), sizeof(OSType));
	selector = ntohl(selector);
#line 52 "Gestalt.xs"
	if (gMacPerl_OSErr = Gestalt(selector, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 64 "Gestalt.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Mac__Gestalt); /* prototype to pass -Wmissing-prototypes */
XS(boot_Mac__Gestalt)
{
    dXSARGS;
    char* file = __FILE__;

    XS_VERSION_BOOTCHECK ;

        newXS("Mac::Gestalt::Gestalt", XS_Mac__Gestalt_Gestalt, file);
    XSRETURN_YES;
}
