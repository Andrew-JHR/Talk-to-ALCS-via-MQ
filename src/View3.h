#if !defined(AFX_VIEW3_H__1453C092_8E92_471A_94B5_84F331F6AE7D__INCLUDED_)
#define AFX_VIEW3_H__1453C092_8E92_471A_94B5_84F331F6AE7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// View3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CView3 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "afxwin.h"

class CView3 : public CFormView
{
protected:
	CView3();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CView3)

// Form Data
public:
	//{{AFX_DATA(CView3)
	enum { IDD = IDD_VIEW3_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CView3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CView3();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CView3)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_VW3LIST;
	virtual void OnInitialUpdate();
	afx_msg void OnLbnDblclkVw3list();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW3_H__1453C092_8E92_471A_94B5_84F331F6AE7D__INCLUDED_)
