/*
 * This file was generated automatically by xsubpp version 1.9508 from the
 * contents of Resources.xs. Do not edit this file, edit Resources.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Resources.xs"
/* $Header: /cvsroot/macperl/perl/macos/ext/Mac/Resources/Resources.xs,v 1.7 2003/10/28 05:53:31 pudge Exp $
 *
 *    Copyright (c) 1996 Matthias Neeracher
 *
 *    You may distribute under the terms of the Perl Artistic License,
 *    as specified in the README file.
 *
 * $Log: Resources.xs,v $
 * Revision 1.7  2003/10/28 05:53:31  pudge
 * Add Carbon compat. notes
 *
 * Revision 1.6  2003/05/08 03:15:16  pudge
 * Properly free stuff, get path size
 *
 * Revision 1.5  2003/04/06 21:45:41  pudge
 * Add FSCreateResourceFile and FSOpenResourceFile for creating/opening resource
 * files from data fork instead of resource fork
 *
 * Revision 1.4  2002/11/13 02:04:52  pudge
 * Aieeeeee!  Big ol' Carbon update.
 *
 * Revision 1.3  2002/01/23 05:44:42  pudge
 * Update whitespace etc., from Thomas
 *
 * Revision 1.2  2000/09/09 22:18:28  neeri
 * Dynamic libraries compile under 5.6
 *
 * Revision 1.1  2000/08/14 03:39:33  neeri
 * Checked into Sourceforge
 *
 * Revision 1.3  1998/04/07 01:03:11  neeri
 * MacPerl 5.2.0r4b1
 *
 * Revision 1.2  1997/11/18 00:53:19  neeri
 * MacPerl 5.1.5
 *
 * Revision 1.1  1997/04/07 20:50:41  neeri
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
#include <Memory.h>
#include <Resources.h>

#define ResErrorReturn	\
	if (gMacPerl_OSErr = ResError()) {	\
		XSRETURN_UNDEF;						\
	} else {							\
		XSRETURN_YES;						\
	}

#define ResErrorCheck						\
	if (gMacPerl_OSErr = ResError()) {	\
		XSRETURN_UNDEF;						\
	} else 0 	

#define ResErrorCheckRetval				\
	if (RETVAL == -1) {						\
		gMacPerl_OSErr = ResError();		\
		XSRETURN_UNDEF;						\
	} else 0

#define ResErrorCheckRetvalNULL			\
	if (!RETVAL) {								\
		gMacPerl_OSErr = ResError();		\
		XSRETURN_UNDEF;						\
	} else 0

#line 88 "Resources.c"
XS(XS_Mac__Resources_CloseResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_CloseResFile)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::CloseResFile(refNum)");
    {
	short	refNum = (short)SvIV(ST(0));

	CloseResFile(refNum);
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_CurResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_CurResFile)
{
    dXSARGS;
    if (items != 0)
	Perl_croak(aTHX_ "Usage: Mac::Resources::CurResFile()");
    {
	short	RETVAL;
	dXSTARG;

	RETVAL = CurResFile();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_HomeResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_HomeResFile)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::HomeResFile(theResource)");
    {
	Handle	theResource;
	short	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	RETVAL = HomeResFile(theResource);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 127 "Resources.xs"
	ResErrorCheckRetval;
#line 141 "Resources.c"
    }
    XSRETURN(1);
}

#ifndef MACOS_TRADITIONAL
#define XSubPPtmpAAAA 1

XS(XS_Mac__Resources_CreateResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_CreateResFile)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::CreateResFile(fileName)");
    {
	Str255	fileName;

	MacPerl_CopyC2P(SvPV_nolen(ST(0)), fileName);
#line 149 "Resources.xs"
	croak("Usage: Mac::Resourcecs::CreateResFile unsupported in Carbon");
#line 161 "Resources.c"
    }
    XSRETURN_EMPTY;
}

#else
#define XSubPPtmpAAAB 1

XS(XS_Mac__Resources_CreateResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_CreateResFile)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::CreateResFile(fileName)");
    {
	Str255	fileName;

	MacPerl_CopyC2P(SvPV_nolen(ST(0)), fileName);

	CreateResFile(fileName);
#line 157 "Resources.xs"
	ResErrorReturn;
#line 183 "Resources.c"
    }
    XSRETURN_EMPTY;
}

#endif
#ifndef MACOS_TRADITIONAL
#define XSubPPtmpAAAC 1

XS(XS_Mac__Resources_OpenResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_OpenResFile)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::OpenResFile(fileName)");
    {
	Str255	fileName;
	short	RETVAL;
	dXSTARG;

	MacPerl_CopyC2P(SvPV_nolen(ST(0)), fileName);
#line 182 "Resources.xs"
	croak("Usage: Mac::Resourcecs::OpenResFile unsupported in Carbon");
#line 206 "Resources.c"
    }
    XSRETURN(1);
}

#else
#define XSubPPtmpAAAD 1

XS(XS_Mac__Resources_OpenResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_OpenResFile)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::OpenResFile(fileName)");
    {
	Str255	fileName;
	short	RETVAL;
	dXSTARG;

	MacPerl_CopyC2P(SvPV_nolen(ST(0)), fileName);

	RETVAL = OpenResFile(fileName);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 190 "Resources.xs"
	ResErrorCheckRetval;
#line 231 "Resources.c"
    }
    XSRETURN(1);
}

#endif
XS(XS_Mac__Resources_UseResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_UseResFile)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::UseResFile(refNum)");
    {
	short	refNum = (short)SvIV(ST(0));

	UseResFile(refNum);
#line 214 "Resources.xs"
	ResErrorReturn;
#line 249 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_CountTypes); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_CountTypes)
{
    dXSARGS;
    if (items != 0)
	Perl_croak(aTHX_ "Usage: Mac::Resources::CountTypes()");
    {
	short	RETVAL;
	dXSTARG;

	RETVAL = CountTypes();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_Count1Types); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_Count1Types)
{
    dXSARGS;
    if (items != 0)
	Perl_croak(aTHX_ "Usage: Mac::Resources::Count1Types()");
    {
	short	RETVAL;
	dXSTARG;

	RETVAL = Count1Types();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_GetIndType); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetIndType)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetIndType(index)");
    {
	short	index = (short)SvIV(ST(0));
	OSType	RETVAL;
#line 257 "Resources.xs"
	GetIndType(&RETVAL, index);
#line 297 "Resources.c"
	ST(0) = sv_newmortal();
	{ OSType hos = htonl(RETVAL);
	  sv_setpvn(ST(0), (char *) &hos, 4);
	}
#line 261 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 304 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_Get1IndType); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_Get1IndType)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::Get1IndType(index)");
    {
	short	index = (short)SvIV(ST(0));
	OSType	RETVAL;
#line 267 "Resources.xs"
	Get1IndType(&RETVAL, index);
#line 320 "Resources.c"
	ST(0) = sv_newmortal();
	{ OSType hos = htonl(RETVAL);
	  sv_setpvn(ST(0), (char *) &hos, 4);
	}
#line 271 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 327 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_SetResLoad); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_SetResLoad)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::SetResLoad(load)");
    {
	Boolean	load = (bool)SvTRUE(ST(0));

	SetResLoad(load);
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_CountResources); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_CountResources)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::CountResources(theType)");
    {
	OSType	theType;
	short	RETVAL;
	dXSTARG;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = CountResources(theType);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_Count1Resources); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_Count1Resources)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::Count1Resources(theType)");
    {
	OSType	theType;
	short	RETVAL;
	dXSTARG;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = Count1Resources(theType);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_GetIndResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetIndResource)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetIndResource(theType, index)");
    {
	OSType	theType;
	short	index = (short)SvIV(ST(1));
	Handle	RETVAL;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = GetIndResource(theType, index);
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Handle", (void*)RETVAL);
#line 323 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 405 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_Get1IndResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_Get1IndResource)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::Get1IndResource(theType, index)");
    {
	OSType	theType;
	short	index = (short)SvIV(ST(1));
	Handle	RETVAL;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = Get1IndResource(theType, index);
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Handle", (void*)RETVAL);
#line 330 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 429 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_GetResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetResource)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetResource(theType, theID)");
    {
	OSType	theType;
	short	theID = (short)SvIV(ST(1));
	Handle	RETVAL;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = GetResource(theType, theID);
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Handle", (void*)RETVAL);
#line 349 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 453 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_Get1Resource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_Get1Resource)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::Get1Resource(theType, theID)");
    {
	OSType	theType;
	short	theID = (short)SvIV(ST(1));
	Handle	RETVAL;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = Get1Resource(theType, theID);
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Handle", (void*)RETVAL);
#line 356 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 477 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_GetNamedResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetNamedResource)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetNamedResource(theType, name)");
    {
	OSType	theType;
	Str255	name;
	Handle	RETVAL;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	MacPerl_CopyC2P(SvPV_nolen(ST(1)), name);

	RETVAL = GetNamedResource(theType, name);
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Handle", (void*)RETVAL);
#line 376 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 503 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_Get1NamedResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_Get1NamedResource)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::Get1NamedResource(theType, name)");
    {
	OSType	theType;
	Str255	name;
	Handle	RETVAL;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	MacPerl_CopyC2P(SvPV_nolen(ST(1)), name);

	RETVAL = Get1NamedResource(theType, name);
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Handle", (void*)RETVAL);
#line 383 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 529 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_LoadResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_LoadResource)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::LoadResource(theResource)");
    {
	Handle	theResource;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	LoadResource(theResource);
#line 402 "Resources.xs"
	ResErrorReturn;
#line 553 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_ReleaseResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_ReleaseResource)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::ReleaseResource(theResource)");
    {
	Handle	theResource;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	ReleaseResource(theResource);
#line 424 "Resources.xs"
	ResErrorReturn;
#line 577 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_DetachResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_DetachResource)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::DetachResource(theResource)");
    {
	Handle	theResource;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	DetachResource(theResource);
#line 446 "Resources.xs"
	ResErrorReturn;
#line 601 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_UniqueID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_UniqueID)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::UniqueID(theType)");
    {
	OSType	theType;
	short	RETVAL;
	dXSTARG;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = UniqueID(theType);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_Unique1ID); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_Unique1ID)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::Unique1ID(theType)");
    {
	OSType	theType;
	short	RETVAL;
	dXSTARG;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = Unique1ID(theType);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_GetResAttrs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetResAttrs)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetResAttrs(theResource)");
    {
	Handle	theResource;
	short	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	RETVAL = GetResAttrs(theResource);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 486 "Resources.xs"
	ResErrorCheck;
#line 668 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_GetResInfo); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetResInfo)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetResInfo(theResource)");
    SP -= items;
    {
	Handle	theResource;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");
#line 504 "Resources.xs"
	{
		short		theID;
		OSType	theType;
		Str255	name;

		GetResInfo(theResource, &theID, &theType, name);
		ResErrorCheck;

		EXTEND(sp, 3);
	++sp;
	*sp = sv_newmortal();
	sv_setiv(*sp, (IV)(theID));
	++sp;
	*sp = sv_newmortal();
	{ OSType hos = htonl((theType));
	  sv_setpvn(*sp, (char *) &hos, 4);
	}
		if (*name)
	++sp;
	*sp = sv_newmortal();
	sv_setpvn(*sp, ((char *) (name)) + 1, (name)[0]);
	}
#line 712 "Resources.c"
	PUTBACK;
	return;
    }
}

XS(XS_Mac__Resources_SetResInfo); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_SetResInfo)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::Resources::SetResInfo(theResource, theID, name)");
    {
	Handle	theResource;
	short	theID = (short)SvIV(ST(1));
	Str255	name;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	MacPerl_CopyC2P(SvPV_nolen(ST(2)), name);

	SetResInfo(theResource, theID, name);
#line 532 "Resources.xs"
	ResErrorReturn;
#line 741 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_AddResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_AddResource)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::Resources::AddResource(theData, theType, theID, name)");
    {
	Handle	theData;
	OSType	theType;
	short	theID = (short)SvIV(ST(2));
	Str255	name;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theData = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theData is not of type Handle");

	memcpy(&theType, SvPV_nolen(ST(1)), sizeof(OSType));
	theType = ntohl(theType);

	MacPerl_CopyC2P(SvPV_nolen(ST(3)), name);

	AddResource(theData, theType, theID, name);
#line 550 "Resources.xs"
	ResErrorReturn;
#line 773 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_GetResourceSizeOnDisk); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetResourceSizeOnDisk)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetResourceSizeOnDisk(theResource)");
    {
	Handle	theResource;
	long	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	RETVAL = GetResourceSizeOnDisk(theResource);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 568 "Resources.xs"
	ResErrorCheckRetval;
#line 800 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_GetMaxResourceSize); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetMaxResourceSize)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetMaxResourceSize(theResource)");
    {
	Handle	theResource;
	long	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	RETVAL = GetMaxResourceSize(theResource);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 593 "Resources.xs"
	ResErrorCheckRetval;
#line 827 "Resources.c"
    }
    XSRETURN(1);
}

#ifndef MACOS_TRADITIONAL
#define XSubPPtmpAAAE 1

XS(XS_Mac__Resources_RsrcMapEntry); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_RsrcMapEntry)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::RsrcMapEntry(theResource)");
    {
	Handle	theResource;
	long	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");
#line 618 "Resources.xs"
	croak("Usage: Mac::Resourcecs::RsrcMapEntry unsupported in Carbon");
#line 854 "Resources.c"
    }
    XSRETURN(1);
}

#else
#define XSubPPtmpAAAF 1

XS(XS_Mac__Resources_RsrcMapEntry); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_RsrcMapEntry)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::RsrcMapEntry(theResource)");
    {
	Handle	theResource;
	long	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	RETVAL = RsrcMapEntry(theResource);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 626 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 884 "Resources.c"
    }
    XSRETURN(1);
}

#endif
XS(XS_Mac__Resources_SetResAttrs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_SetResAttrs)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::SetResAttrs(theResource, attrs)");
    {
	Handle	theResource;
	short	attrs = (short)SvIV(ST(1));

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	SetResAttrs(theResource, attrs);
#line 651 "Resources.xs"
	ResErrorReturn;
#line 910 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_ChangedResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_ChangedResource)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::ChangedResource(theResource)");
    {
	Handle	theResource;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	ChangedResource(theResource);
#line 675 "Resources.xs"
	ResErrorReturn;
#line 934 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_RemoveResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_RemoveResource)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::RemoveResource(theResource)");
    {
	Handle	theResource;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	RemoveResource(theResource);
#line 694 "Resources.xs"
	ResErrorReturn;
#line 958 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_UpdateResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_UpdateResFile)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::UpdateResFile(refNum)");
    {
	short	refNum = (short)SvIV(ST(0));

	UpdateResFile(refNum);
#line 717 "Resources.xs"
	ResErrorReturn;
#line 975 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_WriteResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_WriteResource)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::WriteResource(theResource)");
    {
	Handle	theResource;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	WriteResource(theResource);
#line 738 "Resources.xs"
	ResErrorReturn;
#line 999 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_SetResPurge); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_SetResPurge)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::SetResPurge(install)");
    {
	Boolean	install = (bool)SvTRUE(ST(0));

	SetResPurge(install);
#line 765 "Resources.xs"
	ResErrorReturn;
#line 1016 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_GetResFileAttrs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_GetResFileAttrs)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::Resources::GetResFileAttrs(refNum)");
    {
	short	refNum = (short)SvIV(ST(0));
	short	RETVAL;
	dXSTARG;

	RETVAL = GetResFileAttrs(refNum);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 784 "Resources.xs"
	ResErrorCheck;
#line 1036 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_SetResFileAttrs); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_SetResFileAttrs)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::SetResFileAttrs(refNum, attrs)");
    {
	short	refNum = (short)SvIV(ST(0));
	short	attrs = (short)SvIV(ST(1));

	SetResFileAttrs(refNum, attrs);
#line 807 "Resources.xs"
	ResErrorReturn;
#line 1054 "Resources.c"
    }
    XSRETURN_EMPTY;
}

#ifndef MACOS_TRADITIONAL
#define XSubPPtmpAAAG 1

XS(XS_Mac__Resources_RGetResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_RGetResource)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::RGetResource(theType, theID)");
    {
	OSType	theType;
	short	theID = (short)SvIV(ST(1));
	Handle	RETVAL;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);
#line 841 "Resources.xs"
	croak("Usage: Mac::Resourcecs::RGetResource unsupported in Carbon");
#line 1077 "Resources.c"
    }
    XSRETURN(1);
}

#else
#define XSubPPtmpAAAH 1

XS(XS_Mac__Resources_RGetResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_RGetResource)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::RGetResource(theType, theID)");
    {
	OSType	theType;
	short	theID = (short)SvIV(ST(1));
	Handle	RETVAL;

	memcpy(&theType, SvPV_nolen(ST(0)), sizeof(OSType));
	theType = ntohl(theType);

	RETVAL = RGetResource(theType, theID);
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Handle", (void*)RETVAL);
#line 850 "Resources.xs"
	ResErrorCheckRetvalNULL;
#line 1104 "Resources.c"
    }
    XSRETURN(1);
}

#endif
XS(XS_Mac__Resources_FSpOpenResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_FSpOpenResFile)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::FSpOpenResFile(spec, permission)");
    {
	FSSpec	spec;
	SInt8	permission = (SInt8)SvIV(ST(1));
	short	RETVAL;
	dXSTARG;

	if (GUSIPath2FSp((char *) SvPV_nolen(ST(0)), &spec))
		croak("spec is not a valid file specification");
	else
		0;

	RETVAL = FSpOpenResFile(&spec, permission);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 874 "Resources.xs"
	ResErrorCheckRetval;
#line 1131 "Resources.c"
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_FSOpenResourceFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_FSOpenResourceFile)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::Resources::FSOpenResourceFile(ref, forkName, permissions)");
    {
	FSRef	ref;
	char *	forkName = (char *)SvPV_nolen(ST(1));
	SInt8	permissions = (SInt8)SvIV(ST(2));
	short	RETVAL;
	dXSTARG;

	if (GUSIPath2FS((char *) SvPV_nolen(ST(0)), &ref))
		croak("ref is not a valid file specification");
	else
		0;
#line 893 "Resources.xs"
	{
#ifdef MACOS_TRADITIONAL
	croak("Usage: Mac::Resources::FSOpenResourceFile unsupported in Mac OS");
#else
		SInt16			refNum;
		HFSUniStr255		forkNameU;

		if (strEQ(forkName, "rsrc"))
			FSGetResourceForkName(&forkNameU);
		else
			FSGetDataForkName(&forkNameU);

		gMacPerl_OSErr = FSOpenResourceFile(&ref,
			forkNameU.length, forkNameU.unicode,
			permissions, &refNum
		);

		if (!gMacPerl_OSErr)
			RETVAL = refNum;
		else
			RETVAL = 0;
#endif
	}
#line 1177 "Resources.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_FSpCreateResFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_FSpCreateResFile)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::Resources::FSpCreateResFile(spec, creator, fileType, scriptTag)");
    {
	FSSpec	spec;
	OSType	creator;
	OSType	fileType;
	SInt8	scriptTag = (SInt8)SvIV(ST(3));

	if (GUSIPath2FSp((char *) SvPV_nolen(ST(0)), &spec))
		croak("spec is not a valid file specification");
	else
		0;

	memcpy(&creator, SvPV_nolen(ST(1)), sizeof(OSType));
	creator = ntohl(creator);

	memcpy(&fileType, SvPV_nolen(ST(2)), sizeof(OSType));
	fileType = ntohl(fileType);

	FSpCreateResFile(&spec, creator, fileType, scriptTag);
#line 940 "Resources.xs"
	ResErrorReturn;
#line 1209 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_FSCreateResourceFile); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_FSCreateResourceFile)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::Resources::FSCreateResourceFile(parentRef, name, forkName)");
    {
	FSRef	parentRef;
	Str255	name;
	char *	forkName = (char *)SvPV_nolen(ST(2));

	if (GUSIPath2FS((char *) SvPV_nolen(ST(0)), &parentRef))
		croak("parentRef is not a valid file specification");
	else
		0;

	MacPerl_CopyC2P(SvPV_nolen(ST(1)), name);
#line 959 "Resources.xs"
	{
#ifdef MACOS_TRADITIONAL
	croak("Usage: Mac::Resources::FSCreateResourceFile unsupported in Mac OS");
#else
		HFSUniStr255		forkNameU;
		UnicodeMappingPtr	iUnicodeMapping = malloc(sizeof(UnicodeMapping));
		TextToUnicodeInfo	oTextToUnicodeInfo;
		UniChar *		uName = malloc(sizeof(UniChar) * sizeof(Str255));
		UniCharCount		uNameLength;

		iUnicodeMapping->unicodeEncoding = kTextEncodingUnicodeDefault;
		iUnicodeMapping->otherEncoding   = kTextEncodingISOLatin1;
		iUnicodeMapping->mappingVersion  = kUnicodeUseLatestMapping;

		CreateTextToUnicodeInfo(iUnicodeMapping, &oTextToUnicodeInfo);
		ConvertFromPStringToUnicode(
			oTextToUnicodeInfo, name, sizeof(UniChar) * sizeof(Str255),
			&uNameLength, uName
		);

		if (strEQ(forkName, "rsrc"))
			FSGetResourceForkName(&forkNameU);
		else
			FSGetDataForkName(&forkNameU);

		gMacPerl_OSErr = FSCreateResourceFile(&parentRef,
			(uNameLength / sizeof(UniChar)), uName,
			NULL, NULL,
			forkNameU.length, forkNameU.unicode,
			NULL, NULL
		);

		free(uName);
		free(iUnicodeMapping);
	}
#endif
#line 1268 "Resources.c"
#line 996 "Resources.xs"
	ResErrorReturn;
#line 1271 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_ReadPartialResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_ReadPartialResource)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::Resources::ReadPartialResource(theResource, offset, count)");
    {
	Handle	theResource;
	long	offset = (long)SvIV(ST(1));
	long	count = (long)SvIV(ST(2));
	SV *	RETVAL;

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");
#line 1012 "Resources.xs"
	RETVAL = newSV(count);
	ReadPartialResource(theResource, offset, SvPV_nolen(RETVAL), count);
	ResErrorCheck;
#line 1298 "Resources.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

XS(XS_Mac__Resources_WritePartialResource); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_WritePartialResource)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::Resources::WritePartialResource(theResource, offset, data)");
    {
	Handle	theResource;
	long	offset = (long)SvIV(ST(1));
	SV *	data = ST(2);

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");
#line 1036 "Resources.xs"
	{
		STRLEN	count;
		void *	buffer = SvPV(data, count);
		WritePartialResource(theResource, offset, buffer, count);
		ResErrorReturn;
	}
#line 1329 "Resources.c"
    }
    XSRETURN_EMPTY;
}

XS(XS_Mac__Resources_SetResourceSize); /* prototype to pass -Wmissing-prototypes */
XS(XS_Mac__Resources_SetResourceSize)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::Resources::SetResourceSize(theResource, newSize)");
    {
	Handle	theResource;
	long	newSize = (long)SvIV(ST(1));

	if (sv_derived_from(ST(0), "Handle")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    theResource = INT2PTR(Handle,tmp);
	}
	else
	    Perl_croak(aTHX_ "theResource is not of type Handle");

	SetResourceSize(theResource, newSize);
#line 1061 "Resources.xs"
	ResErrorReturn;
#line 1354 "Resources.c"
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Mac__Resources); /* prototype to pass -Wmissing-prototypes */
XS(boot_Mac__Resources)
{
    dXSARGS;
    char* file = __FILE__;

    XS_VERSION_BOOTCHECK ;

        newXS("Mac::Resources::CloseResFile", XS_Mac__Resources_CloseResFile, file);
        newXS("Mac::Resources::CurResFile", XS_Mac__Resources_CurResFile, file);
        newXS("Mac::Resources::HomeResFile", XS_Mac__Resources_HomeResFile, file);
#if XSubPPtmpAAAA
        newXS("Mac::Resources::CreateResFile", XS_Mac__Resources_CreateResFile, file);
#endif
#if XSubPPtmpAAAB
        newXS("Mac::Resources::CreateResFile", XS_Mac__Resources_CreateResFile, file);
#endif
#if XSubPPtmpAAAC
        newXS("Mac::Resources::OpenResFile", XS_Mac__Resources_OpenResFile, file);
#endif
#if XSubPPtmpAAAD
        newXS("Mac::Resources::OpenResFile", XS_Mac__Resources_OpenResFile, file);
#endif
        newXS("Mac::Resources::UseResFile", XS_Mac__Resources_UseResFile, file);
        newXS("Mac::Resources::CountTypes", XS_Mac__Resources_CountTypes, file);
        newXS("Mac::Resources::Count1Types", XS_Mac__Resources_Count1Types, file);
        newXS("Mac::Resources::GetIndType", XS_Mac__Resources_GetIndType, file);
        newXS("Mac::Resources::Get1IndType", XS_Mac__Resources_Get1IndType, file);
        newXS("Mac::Resources::SetResLoad", XS_Mac__Resources_SetResLoad, file);
        newXS("Mac::Resources::CountResources", XS_Mac__Resources_CountResources, file);
        newXS("Mac::Resources::Count1Resources", XS_Mac__Resources_Count1Resources, file);
        newXS("Mac::Resources::GetIndResource", XS_Mac__Resources_GetIndResource, file);
        newXS("Mac::Resources::Get1IndResource", XS_Mac__Resources_Get1IndResource, file);
        newXS("Mac::Resources::GetResource", XS_Mac__Resources_GetResource, file);
        newXS("Mac::Resources::Get1Resource", XS_Mac__Resources_Get1Resource, file);
        newXS("Mac::Resources::GetNamedResource", XS_Mac__Resources_GetNamedResource, file);
        newXS("Mac::Resources::Get1NamedResource", XS_Mac__Resources_Get1NamedResource, file);
        newXS("Mac::Resources::LoadResource", XS_Mac__Resources_LoadResource, file);
        newXS("Mac::Resources::ReleaseResource", XS_Mac__Resources_ReleaseResource, file);
        newXS("Mac::Resources::DetachResource", XS_Mac__Resources_DetachResource, file);
        newXS("Mac::Resources::UniqueID", XS_Mac__Resources_UniqueID, file);
        newXS("Mac::Resources::Unique1ID", XS_Mac__Resources_Unique1ID, file);
        newXS("Mac::Resources::GetResAttrs", XS_Mac__Resources_GetResAttrs, file);
        newXS("Mac::Resources::GetResInfo", XS_Mac__Resources_GetResInfo, file);
        newXS("Mac::Resources::SetResInfo", XS_Mac__Resources_SetResInfo, file);
        newXS("Mac::Resources::AddResource", XS_Mac__Resources_AddResource, file);
        newXS("Mac::Resources::GetResourceSizeOnDisk", XS_Mac__Resources_GetResourceSizeOnDisk, file);
        newXS("Mac::Resources::GetMaxResourceSize", XS_Mac__Resources_GetMaxResourceSize, file);
#if XSubPPtmpAAAE
        newXS("Mac::Resources::RsrcMapEntry", XS_Mac__Resources_RsrcMapEntry, file);
#endif
#if XSubPPtmpAAAF
        newXS("Mac::Resources::RsrcMapEntry", XS_Mac__Resources_RsrcMapEntry, file);
#endif
        newXS("Mac::Resources::SetResAttrs", XS_Mac__Resources_SetResAttrs, file);
        newXS("Mac::Resources::ChangedResource", XS_Mac__Resources_ChangedResource, file);
        newXS("Mac::Resources::RemoveResource", XS_Mac__Resources_RemoveResource, file);
        newXS("Mac::Resources::UpdateResFile", XS_Mac__Resources_UpdateResFile, file);
        newXS("Mac::Resources::WriteResource", XS_Mac__Resources_WriteResource, file);
        newXS("Mac::Resources::SetResPurge", XS_Mac__Resources_SetResPurge, file);
        newXS("Mac::Resources::GetResFileAttrs", XS_Mac__Resources_GetResFileAttrs, file);
        newXS("Mac::Resources::SetResFileAttrs", XS_Mac__Resources_SetResFileAttrs, file);
#if XSubPPtmpAAAG
        newXS("Mac::Resources::RGetResource", XS_Mac__Resources_RGetResource, file);
#endif
#if XSubPPtmpAAAH
        newXS("Mac::Resources::RGetResource", XS_Mac__Resources_RGetResource, file);
#endif
        newXS("Mac::Resources::FSpOpenResFile", XS_Mac__Resources_FSpOpenResFile, file);
        newXS("Mac::Resources::FSOpenResourceFile", XS_Mac__Resources_FSOpenResourceFile, file);
        newXS("Mac::Resources::FSpCreateResFile", XS_Mac__Resources_FSpCreateResFile, file);
        newXS("Mac::Resources::FSCreateResourceFile", XS_Mac__Resources_FSCreateResourceFile, file);
        newXS("Mac::Resources::ReadPartialResource", XS_Mac__Resources_ReadPartialResource, file);
        newXS("Mac::Resources::WritePartialResource", XS_Mac__Resources_WritePartialResource, file);
        newXS("Mac::Resources::SetResourceSize", XS_Mac__Resources_SetResourceSize, file);

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#if XSubPPtmpAAAC
#endif
#if XSubPPtmpAAAD
#endif
#if XSubPPtmpAAAE
#endif
#if XSubPPtmpAAAF
#endif
#if XSubPPtmpAAAG
#endif
#if XSubPPtmpAAAH
#endif
#line 1456 "Resources.c"

    /* End of Initialisation Section */

    XSRETURN_YES;
}

