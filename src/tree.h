// tree.h : main header file for the TREE application
//

#if !defined(AFX_TREE_H__A865D219_FF31_4811_9E29_4FB973C2F935__INCLUDED_)
#define AFX_TREE_H__A865D219_FF31_4811_9E29_4FB973C2F935__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_USER_THRDMQ_FINISHED  WM_USER+0x100  //### Define for the MQGET thread control
#define WM_USER_CRI_ALLOCATION       WM_USER+0x101

struct THREADPARMS		// ##### global fields for thread control
{											// ##### global fields for thread control
	char * pBfr;						// ##### global fields for thread control
	HWND hWnd;					// ##### global fields for thread control
};

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreeApp:
// See tree.cpp for the implementation of this class
//

class CTreeApp : public CWinApp
{
public:
	CTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTreeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREE_H__A865D219_FF31_4811_9E29_4FB973C2F935__INCLUDED_)




