// treeView.cpp : implementation of the CMyTreeView class
//

#include "stdafx.h"
#include "tree.h"

#include "treeDoc.h"
#include "treeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	//{{AFX_MSG_MAP(CMyTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView construction/destruction

CMyTreeView::CMyTreeView()
{
	m_bOnceAdded = false;
}

CMyTreeView::~CMyTreeView()
{
}

BOOL CMyTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CTreeView::PreCreateWindow (cs))
		return FALSE;
	//add '+' or '-' signes and linking lines among the nodes of the tree
    cs.style |= TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS |
       TVS_SHOWSELALWAYS;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView drawing

void CMyTreeView::OnDraw(CDC* pDC)
{
	CTreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

void CMyTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
		//LOGFONT lf;
	if  (!m_bOnceAdded)
	{
		CFont  font;
		//::ZeroMemory(&lf,sizeof(lf));
		//lf.lfHeight=120;
		//::lstrcpy(lf.lfFaceName,_T("Courier New"));
		//font.CreatePointFontIndirect(&lf);
		font.CreatePointFont(120,_T("Courier New"));
		SetFont(&font);

		GetTreeCtrl().SetLineColor(RGB(255,0,0));

		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("Settings"),0,0,0,0,4,TVI_ROOT,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("CRT Simulator"),0,0,0,0,5,TVI_ROOT,NULL);

		HTREEITEM hA=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("Availability"),
			0,0,0,0,3,TVI_ROOT,NULL);
		HTREEITEM hP=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("Passenger"),
			0,0,0,0,3,TVI_ROOT,NULL);

		HTREEITEM hAA=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AA"),0,0,0,0,1,hA,NULL);
		HTREEITEM hAB=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AB"),0,0,0,0,2,hA,NULL);
		HTREEITEM hAC=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AC"),0,0,0,0,3,hA,NULL);
		HTREEITEM hAD=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AD"),0,0,0,0,1,hA,NULL);

		HTREEITEM hAAA=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAA"),0,0,0,0,1,hAA,NULL);
		HTREEITEM hAAB=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAB"),0,0,0,0,2,hAA,NULL);
		HTREEITEM hAAC=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAC"),0,0,0,0,3,hAA,NULL);
		HTREEITEM hAAD=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAD"),0,0,0,0,1,hAA,NULL);

		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAAA"),0,0,0,0,1,hAAA,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAAB"),0,0,0,0,2,hAAA,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAAC"),0,0,0,0,3,hAAA,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAAD"),0,0,0,0,1,hAAA,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAAE"),0,0,0,0,2,hAAA,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAAF"),0,0,0,0,3,hAAA,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAAG"),0,0,0,0,1,hAAA,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AAAH"),0,0,0,0,2,hAAA,NULL);

		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AABA"),0,0,0,0,1,hAAB,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AABB"),0,0,0,0,2,hAAB,NULL);

		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AACA"),0,0,0,0,1,hAAC,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AACB"),0,0,0,0,2,hAAC,NULL);
		
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AADA"),0,0,0,0,1,hAAD,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("AADB"),0,0,0,0,2,hAAD,NULL);

		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("PA"),0,0,0,0,1,hP,NULL);
		GetTreeCtrl().InsertItem(TVIF_TEXT,_T("PB"),0,0,0,0,2,hP,NULL);
		
		HTREEITEM hPC=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("PC"),0,0,0,0,3,hP,NULL);
		HTREEITEM hPCA=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("PCA"),0,0,0,0,1,hPC,NULL);
		HTREEITEM hPCB=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("PCB"),0,0,0,0,2,hPC,NULL);
		HTREEITEM hPCC=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("PCC"),0,0,0,0,3,hPC,NULL);
		HTREEITEM hPCD=GetTreeCtrl().InsertItem(TVIF_TEXT,_T("PCD"),0,0,0,0,1,hPC,NULL);
		m_bOnceAdded = TRUE;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView printing

BOOL CMyTreeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyTreeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyTreeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView diagnostics

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CTreeDoc* CMyTreeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeDoc)));
	return (CTreeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTreeView message handlers


void CMyTreeView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	HTREEITEM hi=GetTreeCtrl().GetSelectedItem();
	CString s=GetTreeCtrl().GetItemText(hi);
//	DWORD d = GetTreeCtrl().GetItemData(hi);

	CMainFrame* pFrm =  (CMainFrame*)AfxGetMainWnd();  //get mainframe's address

	if (s == "Settings")
			pFrm->SwitchRightViews(4);
	else
	if (s == "CRT Simulator")
		pFrm->SwitchRightViews(5);
	else
	if ((s == "AAAA") ||
		(s == "AAAD") ||
		(s == "AAAG") ||
		(s == "AABA") ||
		(s == "AACA") ||
		(s == "AADA") ||
		(s == "PCA" ) ||
		(s == "PCD" ))
			pFrm->SwitchRightViews(1);
	else 
	if ((s == "AAAB") ||
		(s == "AAAE") ||
		(s == "AAAH") ||
		(s == "AABB") ||
		(s == "AACB") ||
		(s == "AADB") ||
		(s == "PCB" )) 
			pFrm->SwitchRightViews(2);
	else 	
   			pFrm->SwitchRightViews(3);

	*pResult = 0;
}
