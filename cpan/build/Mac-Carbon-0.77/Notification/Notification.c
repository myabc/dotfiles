/*
 * This file was generated automatically by xsubpp version 1.9508 from the
 * contents of Notification.xs. Do not edit this file, edit Notification.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Notification.xs"
/* $Header: /home/neeri/MacCVS/MacPerl/perl/ext/Mac/ExtUtils/MakeToolboxModule,v 1.2 1997/11/18 00:52:19 neeri Exp 
 *    Copyright (c) 1997 Matthias Neeracher
 *
 *    You may distribute under the terms of the Perl Artistic License,
 *    as specified in the README file.
 *
 * $Log: MakeToolboxModule,v  Revision 1.2  1997/11/18 00:52:19  neeri
 * MacPerl 5.1.5
 * 
 * Revision 1.1  1997/04/07 20:49:35  neeri
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
#include <Types.h>
#include <Notification.h>
#include <Quickdraw.h>
#include <Resources.h>
#include <Icons.h>

typedef struct {
	NMRec	nm;
	int		posted;
	Str255	text;
} PerlNMRec, *PerlNMPtr;

#define NMRec	NMRecPtr

static Handle GetOurIcon()
{
	Handle	 icon;

 	return GetIconSuite(&icon, 128, kSelectorAllSmallData) ? nil : icon;
}

#line 54 "Notification.c"
XS(XS_Mac__Notification_NMRec)
{
    dXSARGS;
    dXSI32;
    if (items < 1 || items > 2)
       croak("Usage: %s(STRUCT [, VALUE])", GvNAME(CvGV(cv)));
    SP -= items;
    {
	NMRec STRUCT;

#line 46 "Notification.xs"
	 STRUCT;

	if (sv_derived_from( ST(0), "NMRec")) {
	    IV tmp = SvIV((SV*)SvRV( ST(0)));
	     STRUCT = INT2PTR(NMRec,tmp);
	}
	else
	    Perl_croak(aTHX_ " STRUCT is not of type NMRec");
	if (items == 1) { /* Get field */
	    switch (ix) {
	    case 0:	  /* nmMark */
#line 62 "Notification.xs"
	++sp;
	*sp = sv_newmortal();
	sv_setiv(*sp, (IV)(STRUCT->nmMark));
		break;
	    case 1:	  /* nmIcon */
#line 63 "Notification.xs"
	++sp;
	*sp = sv_newmortal();
	sv_setref_pv(*sp, "Handle", (void*)(STRUCT->nmIcon));
		break;
	    case 2:	  /* nmSound */
#line 64 "Notification.xs"
	++sp;
	*sp = sv_newmortal();
	sv_setref_pv(*sp, "Handle", (void*)(STRUCT->nmSound));
		break;
	    case 3:	  /* nmStr */
#line 65 "Notification.xs"
	++sp;
	*sp = sv_newmortal();
	sv_setpvn(*sp, ((char *) (((PerlNMPtr)STRUCT)->text)) + 1, (((PerlNMPtr)STRUCT)->text)[0]);
		break;
	    case 4:	  /* nmRefCon */
#line 67 "Notification.xs"
	++sp;
	*sp = sv_newmortal();
	sv_setiv(*sp, (IV)(STRUCT->nmRefCon));
		break;
	    }
	} else { 	   /* Set field */
	    switch (ix) {
	    case 0:	  /* nmMark */
#line 62 "Notification.xs"
	 STRUCT->nmMark = (short)SvIV( ST(1));
		break;
	    case 1:	  /* nmIcon */
#line 63 "Notification.xs"
	 STRUCT->nmIcon;

	if (sv_derived_from( ST(1), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV( ST(1)));
	     STRUCT->nmIcon = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ " STRUCT->nmIcon is not of type Handle");
		break;
	    case 2:	  /* nmSound */
#line 64 "Notification.xs"
	 STRUCT->nmSound;

	if (sv_derived_from( ST(1), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV( ST(1)));
	     STRUCT->nmSound = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ " STRUCT->nmSound is not of type Handle");
		break;
	    case 3:	  /* nmStr */
#line 65 "Notification.xs"
	 ((PerlNMPtr)STRUCT)->text;

	MacPerl_CopyC2P(SvPV_nolen( ST(1)),  ((PerlNMPtr)STRUCT)->text);
		break;
	    case 4:	  /* nmRefCon */
#line 67 "Notification.xs"
	 STRUCT->nmRefCon = (long)SvIV( ST(1));
		break;
	    }
#line 46 "Notification.xs"
	}
    }
    XSRETURN(1);
}

XS(XS_NMRec__new); /* prototype to pass -Wmissing-prototypes */
XS(XS_NMRec__new)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: NMRec::_new(package)");
    {
	char *	package = (char *)SvPV_nolen(ST(0));
	NMRec	RETVAL;
#line 82 "Notification.xs"
	RETVAL = (NMRec)NewPtr(sizeof(PerlNMRec));
	RETVAL->qType	= nmType;
	RETVAL->nmMark	= 1;
	RETVAL->nmIcon  = GetOurIcon();
	RETVAL->nmSound = (Handle)-1;
	RETVAL->nmStr   = nil;
	RETVAL->nmResp  = (NMUPP)nil;
	RETVAL->nmRefCon= 0;
	((PerlNMPtr)RETVAL)->posted = false;
	((PerlNMPtr)RETVAL)->text[0]= 0;
#line 172 "Notification.c"
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "NMRec", (void*)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_NMRec_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS(XS_NMRec_DESTROY)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: NMRec::DESTROY(rec)");
    {
	NMRec	rec;

	if (SvROK(ST(0))) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    rec = INT2PTR(NMRec,tmp);
	}
	else
	    Perl_croak(aTHX_ "rec is not a reference");
#line 99 "Notification.xs"
	if (((PerlNMPtr)rec)->posted)
		NMRemove(rec);
	DisposePtr((Ptr)rec);
#line 198 "Notification.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Notification_NMInstall); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Notification_NMInstall)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Notification::NMInstall(nmRequest)");
    {
	NMRec	nmRequest;
	MacOSRet	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "NMRec")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    nmRequest = INT2PTR(NMRec,tmp);
	}
	else
	    Perl_croak(aTHX_ "nmRequest is not of type NMRec");
#line 122 "Notification.xs"
	((PerlNMPtr)nmRequest)->posted = true;
	if (((PerlNMPtr)nmRequest)->text[0])
		nmRequest->nmStr = ((PerlNMPtr)nmRequest)->text;
	else
		nmRequest->nmStr = nil;
	RETVAL = NMInstall(nmRequest);
#line 227 "Notification.c"
	XSprePUSH; PUSHi((IV)!(gMacPerl_OSErr = (short)(RETVAL)));
    }
    XSRETURN(1);
}

XS(XS_Mac__Notification_NMRemove); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Notification_NMRemove)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Notification::NMRemove(nmRequest)");
    {
	NMRec	nmRequest;
	MacOSRet	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "NMRec")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    nmRequest = INT2PTR(NMRec,tmp);
	}
	else
	    Perl_croak(aTHX_ "nmRequest is not of type NMRec");
#line 140 "Notification.xs"
	((PerlNMPtr)nmRequest)->posted = false;
	RETVAL = NMRemove(nmRequest);
#line 253 "Notification.c"
	XSprePUSH; PUSHi((IV)!(gMacPerl_OSErr = (short)(RETVAL)));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Mac__Notification); /* prototype to pass -Wmissing-prototypes */
XS(boot_Mac__Notification)
{
    dXSARGS;
    char* file = __FILE__;

    XS_VERSION_BOOTCHECK ;

        cv = newXS("NMRec::nmMark", XS_Mac__Notification_NMRec, file);
        XSANY.any_i32 = 0 ; 
        cv = newXS("NMRec::nmIcon", XS_Mac__Notification_NMRec, file);
        XSANY.any_i32 = 1 ; 
        cv = newXS("NMRec::nmSound", XS_Mac__Notification_NMRec, file);
        XSANY.any_i32 = 2 ; 
        cv = newXS("NMRec::nmStr", XS_Mac__Notification_NMRec, file);
        XSANY.any_i32 = 3 ; 
        cv = newXS("NMRec::nmRefCon", XS_Mac__Notification_NMRec, file);
        XSANY.any_i32 = 4 ; 
        newXS("NMRec::_new", XS_NMRec__new, file);
        newXS("NMRec::DESTROY", XS_NMRec_DESTROY, file);
        newXS("Mac::Notification::NMInstall", XS_Mac__Notification_NMInstall, file);
        newXS("Mac::Notification::NMRemove", XS_Mac__Notification_NMRemove, file);
    XSRETURN_YES;
}

