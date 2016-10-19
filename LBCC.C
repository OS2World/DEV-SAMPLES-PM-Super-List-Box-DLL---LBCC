#pragma	title("Super List Box DLL  --  Version 2.10 -- (LBCC.C)")
#pragma	subtitle("   Prominare Designer - Interface Definitions")
	
#define	INCL_DOS		   /* Include OS/2 DOS Kernal		*/
#define	INCL_GPI		   /* Include OS/2 PM GPI Interface	*/
#define	INCL_WIN		   /* Include OS/2 PM Windows Interface	*/
#define	INCL_NLS		   /* Include OS/2 PM NLS Support	*/

#if defined(__IBMC__)

#pragma	info(noext)

#endif

#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ccls32.h>

#include "LBCC.h"
#include "listbox.h"

/* This	module contains	an example installable control that can	be used	*/
/* by Prominare	Designer to include within applications	where		*/
/* additional facilities are provided that are not found within	the	*/
/* default controls of OS/2 Presentation Manager.			*/
/*									*/
/* For complete	details	regarding the Custom Control Library		*/
/* Specification (CCLS), Version 2.1c, consult Section 2 in the		*/
/* Prominare Development System	Programming Guide.			*/
/*									*/
/* The DLL is created using the	following options in Prominare Builder:	*/
/*									*/
/* Option	       Value						*/
/* ------	       -----						*/
/* Op Sys	       OS/2 PM Static DLL				*/
/* Optimization	       Maximize						*/
/* Compile Type	       Subsystem					*/
/* CPU		       80386						*/
/* Warning Level       3						*/
/*									*/
/* Equivalent command line invocation:					*/
/*									*/
/*     Icc -G3e- -O+ -Rn -W3 -C	LBCC.C					*/

/* Filename:   LBCC.C							*/

/*  Version:   2.10							*/
/*  Created:   1994-04-22						*/
/*  Revised:   1994-04-22						*/

/* Routines:   BOOL EXPENTRY LBCCRegister(HAB hAB);			*/
/*	       BOOL EXPENTRY LBCCQuery(PUSERINFO32 pUserInfo);		*/
/*	       MRESULT EXPENTRY	LBCCStyles(HWND	hWnd, ULONG msg,	*/
/*					   MPARAM mp1, MPARAM mp2);	*/
/*	       MRESULT EXPENTRY	LBCCAnalystStyles(HWND hWnd,		*/
/*						  ULONG	msg,		*/
/*						  MPARAM mp1,		*/
/*						  MPARAM mp2);		*/


/* Copyright ¸ 1989-1994  Prominare Inc.  All Rights Reserved.		*/

/* --------------------------------------------------------------------	*/

/************************************************************************/
/************************************************************************/
/*		       DISCLAIMER OF WARRANTIES.			*/
/************************************************************************/
/************************************************************************/
/*     The following [enclosed]	code is	library	code created by		*/
/*     Prominare Inc.  This library code is  provided to you solely	*/
/*     for the purpose of assisting you	in the development of your	*/
/*     applications.  The code is provided "AS IS", without		*/
/*     warranty	of any kind.  Prominare	Inc. shall not be liable	*/
/*     for any damages arising out of your use of the library code,	*/
/*     even if they have been advised of the possibility of such	*/
/*     damages.								*/
/************************************************************************/
/************************************************************************/

BOOL	EXPENTRY LBCCRegister(HAB hAB);
BOOL	EXPENTRY LBCCQuery(PUSERINFO32 pUserInfo);
MRESULT	EXPENTRY LBCCStyles(HWND hWnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT	EXPENTRY LBCCAnalystStyles(HWND	hWnd, ULONG msg, MPARAM	mp1, MPARAM mp2);

#pragma	subtitle("   Super List Box DLL - Control Initialization Function")
#pragma	page ( )

/* --- LBCCRegister ------------------------------------ [ Public ] ---	*/
/*									*/
/*     This function is	used to	register the installable control class	*/
/*     with OS/2 Presentation Manager.	The registration must use the	*/
/*     USER_CWINDOWWORDS to reserve memory for the control to allow for	*/
/*     proper usage by Prominare Designer and for use by the control	*/
/*     dialog and window procedures.  The information for the control	*/
/*     containing the style, presentation parameters and control data	*/
/*     is pointed to by	a pointer that can be referenced by the		*/
/*     control's dialog and window procedure as required.  The memory   */
/*     for the structure is allocated and controlled through Prominare	*/
/*     Designer.   The control can reserve more	memory for its use	*/
/*     by adding the memory required to	that of	the USER_CWINDOWWORDS	*/
/*     constant.							*/
/*									*/
/*     Upon Entry:							*/
/*									*/
/*     HAB hAB;	= Application Anchor Block Handle			*/
/*									*/
/*     Upon Exit:							*/
/*									*/
/*     LBCCRegister =  TRUE : Class Registration Successful		*/
/*		    = FALSE : Class Registration Failed			*/
/*									*/
/* --------------------------------------------------------------------	*/

BOOL EXPENTRY LBCCRegister(HAB hAB)

{
		       /* Register the control class with OS/2		*/
		       /* Presentation Manager and return registration	*/
		       /* result					*/

return(fRegisterListBox(hAB));

}
#pragma	subtitle("   Super List Box DLL - Query Control Information Function")
#pragma	page ( )

/* --- LBCCQuery --------------------------------------- [ Public ] ---	*/
/*									*/
/*     This function is	used to	return to the caller information	*/
/*     regarding the installable control and its capabilities.	The	*/
/*     function	should return a	true value otherwise Prominare		*/
/*     Designer	will not register the control as being usable.		*/
/*									*/
/*     Upon Entry:							*/
/*									*/
/*     PUSERINFO32 pUserInfo; =	User Information Pointer		*/
/*									*/
/*     Upon Exit:							*/
/*									*/
/*     LBCCQuery =  TRUE : User	Information Being Returned		*/
/*		 = FALSE : No User Information Available		*/
/*									*/
/* --------------------------------------------------------------------	*/

BOOL EXPENTRY LBCCQuery(PUSERINFO32 pUserInfo)

{
		       /* Complete the User Information	structure	*/
		       /* passed to the	function by Prominare Designer	*/

		       /* Complete the version and number of control	*/
		       /* types.  In Version 2.1c of CCSL, only	one	*/
		       /* control type is used.				*/
pUserInfo->ulMajor = 2UL;
pUserInfo->ulMinor = 0UL;
pUserInfo->cTypes = 1UL;
		       /* Complete the author and control classname	*/

strcpy(pUserInfo->szAuthor,    "Prominare Inc.");
strcpy(pUserInfo->szClassname, "ListBoxWindow");
strcpy(pUserInfo->szName,      "LBCC");

		       /* Complete the default size and	style of the	*/
		       /* first	user control type			*/

pUserInfo->utDefined[0].cx	     = 48L;
pUserInfo->utDefined[0].cy	     = 32L;
pUserInfo->utDefined[0].flStyle	     = WS_VISIBLE;

		       /* Set the maximum amount of text control can	*/
		       /* accept including NULL	termination byte	*/

pUserInfo->utDefined[0].cMaxText     = 0UL;

		       /* Save the style's dialogue ID, type, control   */
		       /* data size and	count of style masks		*/

pUserInfo->utDefined[0].idDlg	     = DLG_CTRLUSER;
pUserInfo->utDefined[0].idDlgAnalyst = DLG_CTRLUSER;
pUserInfo->utDefined[0].ulType	     = UTYPE_PRIVATE;
pUserInfo->utDefined[0].cCtlData     = sizeof(LISTBOXCDATA);
pUserInfo->utDefined[0].cMasks	     = 6UL;
pUserInfo->utDefined[0].flOptions    = CCLSOPT_VARICDATA | CCLSOPT_REFRESH;
pUserInfo->utDefined[0].flStyleType  = STYLETYPE_BITFLAGS;
pUserInfo->utDefined[0].stMasks[0].flStyleMask = LS_MULTIPLESEL;
pUserInfo->utDefined[0].stMasks[0].idStyle     = IDS_LS_MULTIPLESEL;
pUserInfo->utDefined[0].stMasks[1].flStyleMask = LS_OWNERDRAW;
pUserInfo->utDefined[0].stMasks[1].idStyle     = IDS_LS_OWNERDRAW;
pUserInfo->utDefined[0].stMasks[2].flStyleMask = LS_NOADJUSTPOS;
pUserInfo->utDefined[0].stMasks[2].idStyle     = IDS_LS_NOADJUSTPOS;
pUserInfo->utDefined[0].stMasks[3].flStyleMask = LS_HORZSCROLL;
pUserInfo->utDefined[0].stMasks[3].idStyle     = IDS_LS_HORZSCROLL;
pUserInfo->utDefined[0].stMasks[4].flStyleMask = LS_EXTENDEDSEL;
pUserInfo->utDefined[0].stMasks[4].idStyle     = IDS_LS_EXTENDEDSEL;
pUserInfo->utDefined[0].stMasks[5].flStyleMask = LSXS_CHECKBOX;
pUserInfo->utDefined[0].stMasks[5].idStyle     = IDS_LSXS_CHECKBOX;

		       /* Save the description of the control		*/

strcpy(pUserInfo->utDefined[0].szDescription, "32-Bit List Box");

		       /* Return the success flag back to Prominare	*/
		       /* Designer					*/
return(TRUE);
}
#pragma	subtitle("   Super List Box DLL - Control Styles Dialogue Procedure")
#pragma	page ( )

/* --- LBCCStyles -------------------------------------- [ Public ] ---	*/
/*									*/
/*     This function is	used for the custom control's styles dialogue   */
/*     box procedure.							*/
/*									*/
/*     When the	dialogue is invoked from Prominare Designer, the	*/
/*     address of the user style information is	contained in message	*/
/*     parameter 2.  The dialogue is responsible for saving the		*/
/*     address.	 The best method to do this is to save the pointer	*/
/*     in the dialogue's reserved memory where it can be retrieved as   */
/*     needed.								*/
/*									*/
/*     Upon Entry:							*/
/*									*/
/*     HWND   hWnd; = Dialog Window Handle				*/
/*     ULONG  msg;  = PM Message					*/
/*     MPARAM mp1;  = Message Parameter	1				*/
/*     MPARAM mp2;  = Message Parameter	2				*/
/*									*/
/*     Upon Exit:							*/
/*									*/
/*     LBCCStyles = Message Handling Result				*/
/*									*/
/* --------------------------------------------------------------------	*/

MRESULT	EXPENTRY LBCCStyles(HWND hWnd, ULONG msg, MPARAM mp1, MPARAM mp2)

{
CHAR	      szBuffer[256];	   /* Buffer				*/
INT	      cItems;		   /* Items Count			*/
INT	      cLen;		   /* Text Length			*/
INT	      cLines;		   /* Lines Count			*/
INT	      cSounds;		   /* Sounds Count			*/
INT	      cTextLen;		   /* Text Length			*/
IPT	      iptData;		   /* MLE Data Start Position		*/
PCHAR	      pch;		   /* Character	String Pointer		*/
PCHAR	      pchData;		   /* Data Pointer			*/
PLISTBOXCDATA plbwcd;		   /* List Box CTLDATA Pointer		*/
PUSERSTYLE32  pust;		   /* User Style Pointer		*/
SWP	      swp;		   /* Screen Window Position Holder	*/
register INT i,	n;		   /* Loop Counter			*/

switch ( msg )
   {
		       /* Perform dialogue initialization		*/
   case	WM_INITDLG :
		       /* Save the pointer to user style information	*/
		       /* within the dialog's reserved memory           */

       WinSetWindowPtr(hWnd, QWL_USER, (PVOID)mp2);

		       /* Get the pointer to the user style information	*/

       if ( (pust = (PUSERSTYLE32)mp2) != NULL )
	   {
		       /* Set the text,	ID symbol and value for	the	*/
		       /* control					*/

	   WinSetDlgItemText(hWnd, EF_SYMBOL, pust->szid);
	   WinSetDlgItemText(hWnd, EF_SYMBOLVALUE, _ltoa((LONG)pust->id, szBuffer, 10));
	   plbwcd = (PLISTBOXCDATA)pust->pbCtlData;

	   if (	plbwcd->vdata.lbcd1_1.cItems )
	       {
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_SETTEXTLIMIT,
				 MPFROMLONG(16384L), 0L);
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_DISABLEREFRESH, 0L, 0L);
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_RESETUNDO,	0L, 0L);
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_FORMAT,
				 MPFROMSHORT(MLFIE_NOTRANS), 0L);
	       for ( i = n = 0,	iptData	= 0L; i	< plbwcd->vdata.lbcd1_1.cItems;	i++ )
		   {
		   WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_SETIMPORTEXPORT,
				     MPFROMP(szBuffer),
				     MPFROMLONG(cLen = (INT)strlen(strcat(strcpy(szBuffer,
										 &plbwcd->vdata.lbcd1_1.abList[n]),
									  "\n"))));
		   WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_IMPORT, MPFROMP(&iptData),
				     MPFROMLONG(cLen));
		   n +=	(INT)strlen(&plbwcd->vdata.lbcd1_1.abList[n]) +	1;
		   }
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_ENABLEREFRESH, 0L,	0L);
	       if ( plbwcd->vdata.lbcd1_1.cSounds )
		   {
		   WinSetDlgItemText(hWnd, EF_SND1, &plbwcd->vdata.lbcd1_1.abList[n]);
		   if (	plbwcd->vdata.lbcd1_1.cSounds == 2 )
		       {
		       n += (INT)strlen(&plbwcd->vdata.lbcd1_1.abList[n]) + 1;
		       WinSetDlgItemText(hWnd, EF_SND2,	&plbwcd->vdata.lbcd1_1.abList[n]);
		       }
		   }
	       }
		       /* Set multiple selection check box if selected	*/

	   if (	pust->flStyle &	LS_MULTIPLESEL )
	       WinSendDlgItemMsg(hWnd, CB_LS_MULTIPLESEL, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set Owner draw check box if selected		*/

	   if (	pust->flStyle &	LS_OWNERDRAW )
	       WinSendDlgItemMsg(hWnd, CB_LS_OWNERDRAW,	BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set No adjust	position check box if selected	*/

	   if (	pust->flStyle &	LS_NOADJUSTPOS )
	       WinSendDlgItemMsg(hWnd, CB_LS_NOADJUSTPOS, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set Horizontal scroll	check box if selected	*/

	   if (	pust->flStyle &	LS_HORZSCROLL )
	       WinSendDlgItemMsg(hWnd, CB_LS_HORZSCROLL, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set Extended selection check box if selected	*/

	   if (	pust->flStyle &	LS_EXTENDEDSEL )
	       WinSendDlgItemMsg(hWnd, CB_LS_EXTENDEDSEL, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set Check box	selection check	box if selected	*/

	   if (	plbwcd && plbwcd->vdata.lbcd1_1.flExtStyles & LSXS_CHECKBOX )
	       WinSendDlgItemMsg(hWnd, CB_LSXS_CHECKBOX, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

	   if (	pust->flStyle &	WS_VISIBLE )
	       WinSendDlgItemMsg(hWnd, CB_VISIBLE, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

	   if (	pust->flStyle &	WS_GROUP )
	       WinSendDlgItemMsg(hWnd, CB_GROUP, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

	   if (	pust->flStyle &	WS_DISABLED )
	       WinSendDlgItemMsg(hWnd, CB_DISABLED, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

	   if (	pust->flStyle &	WS_TABSTOP )
	       WinSendDlgItemMsg(hWnd, CB_TABSTOP, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);
	   }
		       /* Centre dialog	on the screen			*/

       WinQueryWindowPos(hWnd, (PSWP)&swp);
       WinSetWindowPos(hWnd, HWND_TOP,
		       (WinQuerySysValue(HWND_DESKTOP, SV_CXSCREEN) - swp.cx) /	2L,
		       (WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN) - swp.cy) /	2L,
		       0L, 0L, SWP_MOVE);
       break;
		       /* Process push button selections		*/
   case	WM_COMMAND :
       switch (	SHORT1FROMMP(mp1) )
	   {
		       /* Presentation push button selected		*/

	   case	DID_PRESPARAM :

		       /* Get the pointer to the user style information	*/

	       if ( (pust = PDATA32FROMDLG(hWnd)) != NULL )

		       /* Get the address of the look up function from	*/
		       /* user style information structure and display	*/
		       /* the dialog.  The value selected within the	*/
		       /* dialog will be automatically placed within	*/
		       /* the required entry fields			*/

		   pust->pfnGetPresParams(hWnd);
	       break;
		       /* ID List push button selected			*/

	   case	DID_IDLIST :

		       /* Get the pointer to the user style information	*/

	       if ( (pust = PDATA32FROMDLG(hWnd)) != NULL )

		       /* Get the address of the look up function from	*/
		       /* user style information structure and display	*/
		       /* the dialog.  The value selected within the	*/
		       /* dialog will be automatically placed within	*/
		       /* the required entry fields			*/

		   pust->pfnLookupSymbol(hWnd, EF_SYMBOL, EF_SYMBOLVALUE);
	       break;
		       /* Enter	pushbutton selected get	the definitions	*/
		       /* for the control				*/
	   case	DID_OK :

		       /* Get the pointer to the user style information	*/

	       if ( (pust = PDATA32FROMDLG(hWnd)) != NULL )
		   {
		       /* Get the address of the symbol	validation	*/
		       /* function from	the user style information	*/
		       /* structure.  The function will	validate the	*/
		       /* symbol and will check	for duplications of	*/
		       /* values.  A return value of TRUE from the	*/
		       /* validation function indicates	that the symbol	*/
		       /* and value are	acceptable.  Conversely, a	*/
		       /* FALSE	return value indicates that symbol or	*/
		       /* value	was not	acceptable.  In	this case,	*/
		       /* the dialog should not	be exited from and the	*/
		       /* values within	the entry fields should	not be	*/
		       /* saved.					*/

		   if (	!pust->pfnValidateSymbol(hWnd, EF_SYMBOL, EF_SYMBOLVALUE) )
		       break;
		   else
		       {
		       pust->cText = 0;

		       /* Get the symbol of the	control	and save within	*/
		       /* the user style information structure for use	*/
		       /* by Prominare Designer				*/

		       WinQueryDlgItemText(hWnd, EF_SYMBOL, CCHID, pust->szid);

		       /* Get the id value of the control and save	*/
		       /* within the user style	information structure	*/
		       /* for use by Prominare Designer			*/

		       WinQueryDlgItemText(hWnd, EF_SYMBOLVALUE, 16L, szBuffer);
		       pust->id	= (ULONG)atol(szBuffer);

		       cLines =	SHORT1FROMMR(WinSendDlgItemMsg(hWnd, MLE_LIST,
					     MLM_QUERYLINECOUNT, 0L, 0L));

		       DosAllocMem((PPVOID)(PVOID)&pchData, 16384UL, PAG_READ |	PAG_WRITE | PAG_COMMIT);
		       for ( i = n = cItems = 0, iptData = 0L; i < cLines; i++ )
			   if (	(cLen =	(INT)(cTextLen = (LONG)WinSendDlgItemMsg(hWnd, MLE_LIST,
										 MLM_QUERYLINELENGTH,
										 MPFROMLONG(iptData), 0L))) != 0 )
			       {
			       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_SETIMPORTEXPORT,
						 MPFROMP(szBuffer), MPFROMLONG((IPT)cTextLen));
			       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_EXPORT,
						 MPFROMP(&iptData), MPFROMP(&cTextLen));

			       szBuffer[cLen] =	0;
			       if ( (pch = strchr(szBuffer, '\r')) != NULL )
				   *pch	= 0;
			       else
				   if (	(pch = strchr(szBuffer,	'\n')) != NULL )
				       *pch = 0;

			       if ( szBuffer[0]	)
				   {
				   strcpy(&pchData[n], szBuffer);
				   n +=	(INT)strlen(szBuffer) +	1;
				   ++cItems;
				   }
			       }

		       if ( WinQueryDlgItemTextLength(hWnd, EF_SND1) ||
			    WinQueryDlgItemTextLength(hWnd, EF_SND2) )
			   {
			   WinQueryDlgItemText(hWnd, EF_SND1, CCHMAXPATH, szBuffer);
			   if (	szBuffer[0] )
			       {
			       strcpy(&pchData[n], szBuffer);
			       n += (INT)strlen(szBuffer) + 1;
			       }
			   else
			       pchData[n++] = 0;
			   cSounds = 1;
			   if (	WinQueryDlgItemTextLength(hWnd,	EF_SND2) )
			       {
			       WinQueryDlgItemText(hWnd, EF_SND2, CCHMAXPATH, szBuffer);
			       if ( szBuffer[0]	)
				   {
				   strcpy(&pchData[n], szBuffer);
				   n +=	(INT)strlen(szBuffer) +	1;
				   ++cSounds;
				   }
			       }
			   }
		       if ( !(pust->pbCtlData =	(PBYTE)pust->pfnRealloc(pust->pbCtlData,
									n + sizeof(LISTBOXCDATA) - 1L))	)
			   {
			   WinMessageBox(HWND_DESKTOP, hWnd,
					 "Memory error on reallocating control data!",
					 "Super List Box Control", 0UL,	MB_OK |	MB_ICONEXCLAMATION);
			   return(0L);
			   }

		       pust->cbCtlData = (ULONG)(sizeof(LISTBOXCDATA) -	1 + n);

		       plbwcd =	(PLISTBOXCDATA)pust->pbCtlData;
		       plbwcd->cb = (ULONG)(sizeof(PLISTBOXCDATA) - 1 +	n);
		       plbwcd->vdata.lbcd1_1.cItems  = (ULONG)cItems;
		       plbwcd->vdata.lbcd1_1.cSounds = (ULONG)cSounds;
		       memcpy(plbwcd->vdata.lbcd1_1.abList, pchData, (UINT)n);
		       DosFreeMem((PVOID)pchData);

		       pust->flStyle = 0UL;

		       /* Check	to see if multiple selection desired	*/
		       /* and if selected add style to base selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_MULTIPLESEL, BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= LS_MULTIPLESEL;

		       /* Check	to see if owner	draw desired and if	*/
		       /* selected add style to	base selected		*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_OWNERDRAW, BM_QUERYCHECK, 0L,	0L) )
			   pust->flStyle |= LS_OWNERDRAW;

		       /* Check	to see if no adjust position desired	*/
		       /* and if selected add style to base selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_NOADJUSTPOS, BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= LS_NOADJUSTPOS;

		       /* Check	to see if horizontal scroll desired and	*/
		       /* if selected add style	to base	selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_HORZSCROLL, BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= LS_HORZSCROLL;

		       /* Check	to see if extended selection desired	*/
		       /* and if selected add style to base selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_EXTENDEDSEL, BM_QUERYCHECK, 0L, 0L) )
			   plbwcd->vdata.lbcd1_1.flExtStyles |=	LS_EXTENDEDSEL;

		       /* Check	to see if check	box selection desired	*/
		       /* and if selected add style to base selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LSXS_CHECKBOX, BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= LSXS_CHECKBOX;

		       if ( WinSendDlgItemMsg(hWnd, CB_VISIBLE,
					      BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= WS_VISIBLE;

		       if ( WinSendDlgItemMsg(hWnd, CB_GROUP,
					      BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= WS_GROUP;

		       if ( WinSendDlgItemMsg(hWnd, CB_DISABLED,
					      BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= WS_DISABLED;

		       if ( WinSendDlgItemMsg(hWnd, CB_TABSTOP,
					      BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= WS_TABSTOP;
		       }
		   }
		       /* Exit the dialogue indicating changes made	*/

	       WinDismissDlg(hWnd, TRUE);
	       break;
		       /* Cancel selected, exit	the dialogue without	*/
		       /* changing anything				*/

	   case	DID_CANCEL :
	       WinDismissDlg(hWnd, FALSE);
	       break;
	   }
       break;
		       /* Close	received, exit dialog			*/
   case	WM_CLOSE :
       WinDismissDlg(hWnd, FALSE);
       break;
		       /* Pass through unhandled messages		*/
   default :
       return(WinDefDlgProc(hWnd, msg, mp1, mp2));
   }
return(0L);

}
#pragma	subtitle("   Super List Box DLL - Control Styles Dialogue Procedure")
#pragma	page ( )

/* --- LBCCAnalystStyles ---------------------------- [	Public ] --- */
/*									*/
/*     This function is	used for the custom control's styles dialogue   */
/*     box procedure.							*/
/*									*/
/*     When the	dialogue is invoked from Prominare Designer, the	*/
/*     address of the user style information is	contained in message	*/
/*     parameter 2.  The dialogue is responsible for saving the		*/
/*     address.	 The best method to do this is to save the pointer	*/
/*     in the dialogue's reserved memory where it can be retrieved as   */
/*     needed.								*/
/*									*/
/*     Upon Entry:							*/
/*									*/
/*     HWND   hWnd; = Dialog Window Handle				*/
/*     ULONG  msg;  = PM Message					*/
/*     MPARAM mp1;  = Message Parameter	1				*/
/*     MPARAM mp2;  = Message Parameter	2				*/
/*									*/
/*     Upon Exit:							*/
/*									*/
/*     LBCCAnalystStyles = Message Handling Result		     */
/*									*/
/* --------------------------------------------------------------------	*/

MRESULT	EXPENTRY LBCCAnalystStyles(HWND	hWnd, ULONG msg, MPARAM	mp1, MPARAM mp2)

{
CHAR	      szBuffer[256];	   /* Buffer				*/
INT	      cItems;		   /* Items Count			*/
INT	      cLen;		   /* Text Length			*/
INT	      cLines;		   /* Lines Count			*/
INT	      cSounds;		   /* Sounds Count			*/
INT	      cTextLen;		   /* Text Length			*/
IPT	      iptData;		   /* MLE Data Start Position		*/
PCHAR	      pch;		   /* Character	String Pointer		*/
PCHAR	      pchData;		   /* Data Pointer			*/
PLISTBOXCDATA plbwcd;		   /* List Box CTLDATA Pointer		*/
PUSERSTYLE32  pust;		   /* User Style Pointer		*/
SWP	      swp;		   /* Screen Window Position Holder	*/
register INT i,	n;		   /* Loop Counter			*/

switch ( msg )
   {
		       /* Perform dialogue initialization		*/
   case	WM_INITDLG :
		       /* Save the pointer to user style information	*/
		       /* within the dialog's reserved memory           */

       WinSetWindowPtr(hWnd, QWL_USER, (PVOID)mp2);

		       /* Get the pointer to the user style information	*/

       if ( (pust = (PUSERSTYLE32)mp2) != NULL )
	   {
		       /* Set the text,	ID symbol and value for	the	*/
		       /* control					*/

	   plbwcd = (PLISTBOXCDATA)pust->pbCtlData;

	   if (	plbwcd->vdata.lbcd1_1.cItems )
	       {
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_SETTEXTLIMIT,
				 MPFROMLONG(16384L), 0L);
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_DISABLEREFRESH, 0L, 0L);
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_RESETUNDO,	0L, 0L);
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_FORMAT,
				 MPFROMSHORT(MLFIE_NOTRANS), 0L);
	       for ( i = n = 0,	iptData	= 0L; i	< plbwcd->vdata.lbcd1_1.cItems;	i++ )
		   {
		   WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_SETIMPORTEXPORT,
				     MPFROMP(szBuffer),
				     MPFROMLONG(cLen = (INT)strlen(strcat(strcpy(szBuffer,
										 &plbwcd->vdata.lbcd1_1.abList[n]),
									  "\n"))));
		   WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_IMPORT, MPFROMP(&iptData),
				     MPFROMLONG(cLen));
		   n +=	(INT)strlen(&plbwcd->vdata.lbcd1_1.abList[n]) +	1;
		   }
	       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_ENABLEREFRESH, 0L,	0L);
	       if ( plbwcd->vdata.lbcd1_1.cSounds )
		   {
		   WinSetDlgItemText(hWnd, EF_SND1, &plbwcd->vdata.lbcd1_1.abList[n]);
		   if (	plbwcd->vdata.lbcd1_1.cSounds == 2 )
		       {
		       n += (INT)strlen(&plbwcd->vdata.lbcd1_1.abList[n]) + 1;
		       WinSetDlgItemText(hWnd, EF_SND2,	&plbwcd->vdata.lbcd1_1.abList[n]);
		       }
		   }
	       }
		       /* Set multiple selection check box if selected	*/

	   if (	pust->flStyle &	LS_MULTIPLESEL )
	       WinSendDlgItemMsg(hWnd, CB_LS_MULTIPLESEL, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set Owner draw check box if selected		*/

	   if (	pust->flStyle &	LS_OWNERDRAW )
	       WinSendDlgItemMsg(hWnd, CB_LS_OWNERDRAW,	BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set No adjust	position check box if selected	*/

	   if (	pust->flStyle &	LS_NOADJUSTPOS )
	       WinSendDlgItemMsg(hWnd, CB_LS_NOADJUSTPOS, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set Horizontal scroll	check box if selected	*/

	   if (	pust->flStyle &	LS_HORZSCROLL )
	       WinSendDlgItemMsg(hWnd, CB_LS_HORZSCROLL, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set Extended selection check box if selected	*/

	   if (	pust->flStyle &	LS_EXTENDEDSEL )
	       WinSendDlgItemMsg(hWnd, CB_LS_EXTENDEDSEL, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

		       /* Set Check box	selection check	box if selected	*/

	   if (	plbwcd && plbwcd->vdata.lbcd1_1.flExtStyles & LSXS_CHECKBOX )
	       WinSendDlgItemMsg(hWnd, CB_LSXS_CHECKBOX, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

	   if (	pust->flStyle &	WS_VISIBLE )
	       WinSendDlgItemMsg(hWnd, CB_VISIBLE, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

	   if (	pust->flStyle &	WS_GROUP )
	       WinSendDlgItemMsg(hWnd, CB_GROUP, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

	   if (	pust->flStyle &	WS_DISABLED )
	       WinSendDlgItemMsg(hWnd, CB_DISABLED, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);

	   if (	pust->flStyle &	WS_TABSTOP )
	       WinSendDlgItemMsg(hWnd, CB_TABSTOP, BM_SETCHECK,
				 MPFROMSHORT(TRUE), 0L);
	   }
		       /* Centre dialog	on the screen			*/

       WinQueryWindowPos(hWnd, (PSWP)&swp);
       WinSetWindowPos(hWnd, HWND_TOP,
		       (WinQuerySysValue(HWND_DESKTOP, SV_CXSCREEN) - swp.cx) /	2L,
		       (WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN) - swp.cy) /	2L,
		       0L, 0L, SWP_MOVE);
       break;
		       /* Process push button selections		*/
   case	WM_COMMAND :
       switch (	SHORT1FROMMP(mp1) )
	   {
		       /* Presentation push button selected		*/

	   case	DID_PRESPARAM :

		       /* Get the pointer to the user style information	*/

	       if ( (pust = PDATA32FROMDLG(hWnd)) != NULL )

		       /* Get the address of the look up function from	*/
		       /* user style information structure and display	*/
		       /* the dialog.  The value selected within the	*/
		       /* dialog will be automatically placed within	*/
		       /* the required entry fields			*/

		   pust->pfnGetPresParams(hWnd);
	       break;
		       /* Enter	pushbutton selected get	the definitions	*/
		       /* for the control				*/
	   case	DID_OK :

		       /* Get the pointer to the user style information	*/

	       if ( (pust = PDATA32FROMDLG(hWnd)) != NULL )
		   {
		       pust->cText = 0;

		       cLines =	SHORT1FROMMR(WinSendDlgItemMsg(hWnd, MLE_LIST,
					     MLM_QUERYLINECOUNT, 0L, 0L));

		       DosAllocMem((PPVOID)(PVOID)&pchData, 16384UL, PAG_READ |	PAG_WRITE | PAG_COMMIT);
		       for ( i = n = cItems = 0, iptData = 0L; i < cLines; i++ )
			   if (	(cLen =	(INT)(cTextLen = (LONG)WinSendDlgItemMsg(hWnd, MLE_LIST,
										 MLM_QUERYLINELENGTH,
										 MPFROMLONG(iptData), 0L))) != 0 )
			       {
			       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_SETIMPORTEXPORT,
						 MPFROMP(szBuffer), MPFROMLONG((IPT)cTextLen));
			       WinSendDlgItemMsg(hWnd, MLE_LIST, MLM_EXPORT,
						 MPFROMP(&iptData), MPFROMP(&cTextLen));

			       szBuffer[cLen] =	0;
			       if ( (pch = strchr(szBuffer, '\r')) != NULL )
				   *pch	= 0;
			       else
				   if (	(pch = strchr(szBuffer,	'\n')) != NULL )
				       *pch = 0;

			       if ( szBuffer[0]	)
				   {
				   strcpy(&pchData[n], szBuffer);
				   n +=	(INT)strlen(szBuffer) +	1;
				   ++cItems;
				   }
			       }

		       if ( WinQueryDlgItemTextLength(hWnd, EF_SND1) ||
			    WinQueryDlgItemTextLength(hWnd, EF_SND2) )
			   {
			   WinQueryDlgItemText(hWnd, EF_SND1, CCHMAXPATH, szBuffer);
			   if (	szBuffer[0] )
			       {
			       strcpy(&pchData[n], szBuffer);
			       n += (INT)strlen(szBuffer) + 1;
			       }
			   else
			       pchData[n++] = 0;
			   cSounds = 1;
			   if (	WinQueryDlgItemTextLength(hWnd,	EF_SND2) )
			       {
			       WinQueryDlgItemText(hWnd, EF_SND2, CCHMAXPATH, szBuffer);
			       if ( szBuffer[0]	)
				   {
				   strcpy(&pchData[n], szBuffer);
				   n +=	(INT)strlen(szBuffer) +	1;
				   ++cSounds;
				   }
			       }
			   }
		       if ( !(pust->pbCtlData =	(PBYTE)pust->pfnRealloc(pust->pbCtlData,
									n + sizeof(LISTBOXCDATA) - 1L))	)
			   {
			   WinMessageBox(HWND_DESKTOP, hWnd,
					 "Memory error on reallocating control data!",
					 "Super List Box Control", 0UL,	MB_OK |	MB_ICONEXCLAMATION);
			   return(0L);
			   }

		       pust->cbCtlData = (ULONG)(sizeof(LISTBOXCDATA) -	1 + n);

		       plbwcd =	(PLISTBOXCDATA)pust->pbCtlData;
		       plbwcd->cb = (ULONG)(sizeof(PLISTBOXCDATA) - 1 +	n);
		       plbwcd->vdata.lbcd1_1.cItems  = (ULONG)cItems;
		       plbwcd->vdata.lbcd1_1.cSounds = (ULONG)cSounds;
		       memcpy(plbwcd->vdata.lbcd1_1.abList, pchData, (UINT)n);
		       DosFreeMem((PVOID)pchData);

		       pust->flStyle = 0UL;

		       /* Check	to see if multiple selection desired	*/
		       /* and if selected add style to base selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_MULTIPLESEL, BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= LS_MULTIPLESEL;

		       /* Check	to see if owner	draw desired and if	*/
		       /* selected add style to	base selected		*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_OWNERDRAW, BM_QUERYCHECK, 0L,	0L) )
			   pust->flStyle |= LS_OWNERDRAW;

		       /* Check	to see if no adjust position desired	*/
		       /* and if selected add style to base selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_NOADJUSTPOS, BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= LS_NOADJUSTPOS;

		       /* Check	to see if horizontal scroll desired and	*/
		       /* if selected add style	to base	selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_HORZSCROLL, BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= LS_HORZSCROLL;

		       /* Check	to see if extended selection desired	*/
		       /* and if selected add style to base selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LS_EXTENDEDSEL, BM_QUERYCHECK, 0L, 0L) )
			   plbwcd->vdata.lbcd1_1.flExtStyles |=	LS_EXTENDEDSEL;

		       /* Check	to see if check	box selection desired	*/
		       /* and if selected add style to base selected	*/

		       if ( WinSendDlgItemMsg(hWnd, CB_LSXS_CHECKBOX, BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= LSXS_CHECKBOX;

		       if ( WinSendDlgItemMsg(hWnd, CB_VISIBLE,
					      BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= WS_VISIBLE;

		       if ( WinSendDlgItemMsg(hWnd, CB_GROUP,
					      BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= WS_GROUP;

		       if ( WinSendDlgItemMsg(hWnd, CB_DISABLED,
					      BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= WS_DISABLED;

		       if ( WinSendDlgItemMsg(hWnd, CB_TABSTOP,
					      BM_QUERYCHECK, 0L, 0L) )
			   pust->flStyle |= WS_TABSTOP;
		   }
		       /* Exit the dialogue indicating changes made	*/

	       WinDismissDlg(hWnd, TRUE);
	       break;
		       /* Cancel selected, exit	the dialogue without	*/
		       /* changing anything				*/

	   case	DID_CANCEL :
	       WinDismissDlg(hWnd, FALSE);
	       break;
	   }
       break;
		       /* Close	received, exit dialog			*/
   case	WM_CLOSE :
       WinDismissDlg(hWnd, FALSE);
       break;
		       /* Pass through unhandled messages		*/
   default :
       return(WinDefDlgProc(hWnd, msg, mp1, mp2));
   }
return(0L);

}
