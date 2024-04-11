#if !defined(AFX_VIEW1_H__0AFF879B_BD81_4091_AE08_F9C8BA478D7F__INCLUDED_)
#define AFX_VIEW1_H__0AFF879B_BD81_4091_AE08_F9C8BA478D7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// View1.h : header file
//

#include "treeDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CView1 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CView1 : public CFormView
{
protected:
	CView1();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CView1)

// Form Data
public:
	//{{AFX_DATA(CView1)
	enum { IDD = IDD_VIEW1_FORM };
	CEdit	m_EDIT2;
	CEdit	m_EDIT1;
	//}}AFX_DATA

// Attributes
public:
	CTreeDoc* GetDocument();// Operations

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CView1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CView1();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CView1)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in treeView.cpp
inline CTreeDoc* CView1::GetDocument()
   { return (CTreeDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW1_H__0AFF879B_BD81_4091_AE08_F9C8BA478D7F__INCLUDED_)
