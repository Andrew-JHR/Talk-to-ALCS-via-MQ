// treeView.h : interface of the CMyTreeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEVIEW_H__FB9A93A4_DAFB_4489_9AF2_23B0528B2878__INCLUDED_)
#define AFX_TREEVIEW_H__FB9A93A4_DAFB_4489_9AF2_23B0528B2878__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "treeDoc.h"
#include "MainFrm.h"


class CMyTreeView : public CTreeView
{
protected: // create from serialization only
	CMyTreeView();
	DECLARE_DYNCREATE(CMyTreeView)

// Attributes
public:
	CTreeDoc* GetDocument();
private:
	bool m_bOnceAdded ;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTreeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyTreeView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in treeView.cpp
inline CTreeDoc* CMyTreeView::GetDocument()
   { return (CTreeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEVIEW_H__FB9A93A4_DAFB_4489_9AF2_23B0528B2878__INCLUDED_)
