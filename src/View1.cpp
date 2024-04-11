// View1.cpp : implementation file
//

#include "stdafx.h"
#include "tree.h"
#include "View1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView1

IMPLEMENT_DYNCREATE(CView1, CFormView)

CView1::CView1()
	: CFormView(CView1::IDD)
{
	//{{AFX_DATA_INIT(CView1)
	//}}AFX_DATA_INIT
}

CView1::~CView1()
{
}

void CView1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CView1)
	DDX_Control(pDX, IDC_EDIT2, m_EDIT2);
	DDX_Control(pDX, IDC_EDIT1, m_EDIT1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CView1, CFormView)
	//{{AFX_MSG_MAP(CView1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView1 diagnostics

#ifdef _DEBUG
void CView1::AssertValid() const
{
	CFormView::AssertValid();
}

void CView1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView1 message handlers

#ifdef _DEBUG
CTreeDoc* CView1::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeDoc)));
	return (CTreeDoc*)m_pDocument;
}
#endif //_DEBUG */


void CView1::OnDraw(CDC* pDC) 
{
	CTreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
//	m_EDIT1.SetWindowText(pDoc->mDocStr1);
//	m_EDIT2.SetWindowText(pDoc->mDocStr2);
}


