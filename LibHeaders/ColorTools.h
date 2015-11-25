#ifndef __COLORTOOLS__#define __COLORTOOLS__/*---------------------------------------------------------------------------------------//	File:	ColorTools.h	//	Date:	February 15, 1989	////	by Mike Puckett, Macintosh CPU Software Quality, x4-1332.//	��1989 - 1990, Apple Computer, Inc.//---------------------------------------------------------------------------------------*//* Useful Definitions -------------------------------------------------------------------*/#define hilite		(short)50				/* This should be defined in QuickDraw.h!	*/#define dither		(short)64				/* Only if Jackson Pollock is around.		*/#define FULL_HUE	(unsigned short)0xFFFF#define NO_HUE		(unsigned short)0x0000 /* Useful Macros ------------------------------------------------------------------------*/#define ISCGRAFPORT(grafPtr)	(TEST_FLAG(((GrafPtr)grafPtr)->portBits.rowBytes,0xC000))#define PM_ROWBYTES(rb)			((unsigned short)0x8000 | (rb))/* Useful In-Lines ----------------------------------------------------------------------*/pascal unsigned longQDVersion(void) = {	0x7014,	/* Moveq	#$14,D0	*/	0xAB1D	/* _Offscreen		*/	};/* Data Structures ----------------------------------------------------------------------*/typedef struct{	RGBColor	mTtlColor,				mBkGColor,				mBarColor,				mItmColor,				mItmMark,				mItmCmnd;	}MColorsType;#ifdef __safe_linkextern "C" {#endifextern pascal	void	InitColorTools(						void);/* General Purpose Routines -------------------------------------------------------------*/extern pascal	Boolean	HasColorQD(							void);extern pascal	Boolean	Has32BitQD(							void);extern pascal	void	HiliteRect(			Rect			*theRect);extern pascal	void	HiliteRoundRect(	Rect			*theRect,											short			ovalWidth,											short			ovalHeight);extern pascal	void	HiliteRgn(			RgnHandle		theRgn);extern pascal	Boolean	PlotIcls(			Rect			*theRect,											ResType			iclsType,											short			iclsID);extern pascal	void	PixToBits(			PixMapHandle	pmHandle,											BitMap			*bitMap);extern pascal	void	GetColorEntry(		CTabHandle		theCTable,											short			theType,											RGBColor		*colorEntry);											/* Window-Oriented Routines -------------------------------------------------------------*/extern pascal void		GetWColor(			WindowPtr		theWindow,											short			theType,											RGBColor		*theColor);	/* Control-Oriented Routines ------------------------------------------------------------*/extern pascal void		GetCtlColor(		ControlHandle	theControl,											short			theType,											RGBColor		*theColor);									/* Menu-Oriented Routines ---------------------------------------------------------------*/extern pascal void		SetMenuItemColor(	short			menuID,											short			menuItem,											RGBColor		*itemColor);extern pascal void		GetMColors(			short			menuID,											short			menuItem,											MColorsType		*mColors);#ifdef __safe_link}#endif#endif