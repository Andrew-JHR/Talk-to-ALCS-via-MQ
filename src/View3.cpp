// View3.cpp : implementation file
//

#include "stdafx.h"
#include "tree.h"
#include "View3.h"
#include ".\view3.h"
#include "View5.h"

extern  CView5 * pView5; 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView3

IMPLEMENT_DYNCREATE(CView3, CFormView)

CView3::CView3()
	: CFormView(CView3::IDD)
{
	//{{AFX_DATA_INIT(CView3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CView3::~CView3()
{
}

void CView3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CView3)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_VW3LIST, m_VW3LIST);
}


BEGIN_MESSAGE_MAP(CView3, CFormView)
	//{{AFX_MSG_MAP(CView3)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_LBN_DBLCLK(IDC_VW3LIST, OnLbnDblclkVw3list)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView3 diagnostics

#ifdef _DEBUG
void CView3::AssertValid() const
{
	CFormView::AssertValid();
}

void CView3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView3 message handlers

void CView3::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_VW3LIST.AddString("String From View3");

}

void CView3::OnLbnDblclkVw3list()
{
	CString oldCMD;
	int nSelect = m_VW3LIST.GetCurSel();
	m_VW3LIST.GetText(nSelect,oldCMD);
	
	 pView5->m_INPUT.SetWindowText(oldCMD);	

}
