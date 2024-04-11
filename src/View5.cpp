// View5.cpp : 實作檔
//

#include "stdafx.h"
#include "tree.h"
#include "View5.h"
#include ".\view5.h"

extern  CView5 * pView5; 

extern THREADPARMS ThreadParms;   //define in global

extern char buffer[4096];		         /* Message buffer                */
extern CString CRI, LOG, CRTQ;
extern CString CMD, QMGR, QRYQ;
extern CString TIMES,SLEEP;
extern int nMsgLen;

extern short int Number_of_Sessions;


// CView5

IMPLEMENT_DYNCREATE(CView5, CFormView)

CView5::CView5()
	: CFormView(CView5::IDD)
{
}


CView5::~CView5()
{
	Number_of_Sessions -- ;   // decrease the total number of sessions 

	if ( CRI != "070001")
	{
		CTreeDoc* pDoc = (CTreeDoc *)GetDocument();
		ASSERT_VALID(pDoc);
		CMD = "ZOU"; 
		pDoc->mqsend();		//send the query and get the response
	}
}

//CView5 theView5;

void CView5::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT, m_INPUT);
	DDX_Control(pDX, IDC_OUTPUT, m_OUTPUT);
}

BEGIN_MESSAGE_MAP(CView5, CFormView)
	ON_BN_CLICKED(IDC_ENTER, OnBnClickedEnter)
	ON_LBN_DBLCLK(IDC_OUTPUT, OnLbnDblclkOutput)
	ON_LBN_ERRSPACE(IDC_OUTPUT, OnLbnErrspaceOutput)
	ON_BN_CLICKED(IDC_CLEAR, OnBnClickedClear)
	ON_MESSAGE(WM_USER_THRDMQ_FINISHED,OnThreadFinished)
END_MESSAGE_MAP()


// CView5 診斷

#ifdef _DEBUG
void CView5::AssertValid() const
{
	CFormView::AssertValid();
}

void CView5::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CView5 訊息處理常式

void CView5::OnDraw(CDC* /*pDC*/)
{
	CTreeDoc* pDoc = (CTreeDoc *)GetDocument();
		ASSERT_VALID(pDoc);
//		AfxMessageBox(pDoc->QMGR);
}



void CView5::OnBnClickedEnter()
{
		CTreeDoc* pDoc = (CTreeDoc *)GetDocument();
		ASSERT_VALID(pDoc);
		
		m_INPUT.GetWindowText(CMD);
		m_INPUT.SetWindowText(""); //clear
	
		nCurLine=m_OUTPUT.GetCount(); //get the current line 
		m_OUTPUT.AddString(CMD);	//write to the listbox window

		ThreadParms.hWnd = m_hWnd; //save this window's handler

		pDoc->mqsend();		//send the query and get the response 
}

void CView5::OnLbnDblclkOutput()
{
	CString oldCMD;
	int nSelect = m_OUTPUT.GetCurSel();
	m_OUTPUT.GetText(nSelect,oldCMD);
	m_INPUT.SetWindowText(oldCMD);	
}

void CView5::OnLbnErrspaceOutput()
{
	AfxMessageBox(" Space Is Full, All OUTPUT Data Will Be Erased ! ");
	m_OUTPUT.ResetContent();	
}

void CView5::OnBnClickedClear()
{
	m_OUTPUT.ResetContent();	
}

BOOL CView5::PreTranslateMessage(MSG* pMsg)
{
	 if (m_hAccel != NULL)
        if (::TranslateAccelerator (m_hWnd, m_hAccel, pMsg))
            return TRUE;
	return CFormView::PreTranslateMessage(pMsg);
}

void CView5::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle() , MAKEINTRESOURCE (IDR_MAINFRAME));
	pView5 = this;
	
	CTreeDoc* pDoc = (CTreeDoc *)GetDocument();
	ASSERT_VALID(pDoc);
	CMD = "ZIN"; 
	ThreadParms.hWnd = m_hWnd; //save this window's handler
	pDoc->mqsend();		//send the query and get the response
}

LONG CView5::OnThreadFinished(WPARAM wParam, LPARAM lParam )
{
		char * buffer = ThreadParms.pBfr; 
		for (int i,j=i=0 ; i < nMsgLen ; i++)
		{
				if (buffer[i] == 0x0a)
				{
					buffer[i] = 0;
					m_OUTPUT.AddString(&(buffer[j]));
					j = i+1;
				}
		}
		// scroll the output data to the latest position
		m_OUTPUT.SetTopIndex(nCurLine);
		m_INPUT.SetFocus();		//cursor

	return 0;
}

