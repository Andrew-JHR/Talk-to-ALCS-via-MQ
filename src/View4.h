#if !defined(AFX_VIEW4_H__4F061089_E830_47E8_BFA1_1E3A95E776D9__INCLUDED_)
#define AFX_VIEW4_H__4F061089_E830_47E8_BFA1_1E3A95E776D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// View4.h : header file
//

#include "treeDoc.h"

/////////////////////////////////////////////////////////////////////////////
// View4 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "afxwin.h"

class CView4 : public CFormView
{
protected:
	CView4();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CView4)

// Form Data
public:
	//{{AFX_DATA(View4)
	enum { IDD = IDD_VIEW4_FORM };
	CEdit	m_TIMES;
	CEdit	m_SLEEP;
	CEdit	m_IP;
	CEdit	m_QRYQ;
	CEdit	m_QMGR;
	CButton	m_OPEN;
	CEdit	m_LOG;
	CEdit	m_CRTQ;
	CEdit   	m_CRI;
	CEdit	m_INI;
	//}}AFX_DATA

// Attributes
private:
    char parm[11][100];           //save the INI parameters    

// Operations
public:
	CTreeDoc* GetDocument(); // Operations

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CView4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CView4();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CView4)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDir();
	virtual void OnInitialUpdate();
	afx_msg void OnOpen();
	afx_msg void OnEnChangeIni();
	afx_msg void OnEnChangeCri();
	afx_msg void OnEnChangeQmgr();
	afx_msg void OnEnChangeQryq();
	afx_msg void OnEnChangeCrtq();
	afx_msg void OnEnChangeLog();
	afx_msg void OnEnChangeSleep();
	afx_msg void OnEnChangeTimes();
	CEdit m_AUTH;
	CEdit m_CHL;
	afx_msg void OnEnChangeIp();
	afx_msg void OnEnChangeChl();
	afx_msg void OnEnChangeAuth();
	afx_msg LONG OnCriAllocation(WPARAM wParam, LPARAM lParam);

protected:
//	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

inline CTreeDoc* CView4::GetDocument()
   { return (CTreeDoc*)m_pDocument; }

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW4_H__4F061089_E830_47E8_BFA1_1E3A95E776D9__INCLUDED_)
