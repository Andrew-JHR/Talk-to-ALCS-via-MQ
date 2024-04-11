// tree.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "tree.h"

#include "MainFrm.h"
#include "treeDoc.h"
#include "treeView.h"
#include "View1.h"
#include "View2.h"
#include "View3.h"
#include "View4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeApp

BEGIN_MESSAGE_MAP(CTreeApp, CWinApp)
	//{{AFX_MSG_MAP(CTreeApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeApp construction

CTreeApp::CTreeApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTreeApp object

CTreeApp theApp;

CView5* pView5;						// MQCRT input/output
CView4* pView4;						// Session Control interface

THREADPARMS ThreadParms;	// ##### global fields for thread control
CWinThread*  pThread;     // ### thread control 

ImqQueueManager mgr;            // Queue manager               
ImqQueue iqueue, oqueue;         // Queue               
ImqMessage imsg, omsg;                     // Data message     
ImqGetMessageOptions gmo;    // Get message options  
ImqChannel  chl;                      // Server Connection Channel
FILE *outfile;							// file for logging
CString warning;

char buffer[4096];						// Message buffer   
CString CRI, LOG, CRTQ;
CString CMD, QMGR, QRYQ;
CString TIMES,SLEEP;
CString IP,AUTH,CHL;
int nMsgLen;
CString oldCRI, oldQRYQ, oldCRTQ;	 // save the original values

HWND hWnd_View4;			//hwnd for view4;

#pragma data_seg (".shared")
short int Number_of_Sessions = 0 ;
#pragma data_seg ( )
#pragma comment (linker, "/section:.shared,rws")	

/////////////////////////////////////////////////////////////////////////////
// CTreeApp initialization

BOOL CTreeApp::InitInstance()
{
	if ( Number_of_Sessions == 5 )
	{
		AfxMessageBox("You have alreadly created too many sessions !!");
		return FALSE;
	}
	else
	{
		Number_of_Sessions ++ ;
	}

/* {    // BLOCK: doc template registration
		// Register the document template.  Document templates serve
		// as the connection between documents, frame windows and views.
		// Attach this form to another document or frame window by changing
		// the document or frame class in the constructor below.
		CSingleDocTemplate* pNewDocTemplate = new CSingleDocTemplate(
			IDR_VIEW3_TMPL,
			RUNTIME_CLASS(CTreeDoc),		// document class
			RUNTIME_CLASS(CMainFrame),		// frame class
			RUNTIME_CLASS(CView3));		// view class
		AddDocTemplate(pNewDocTemplate);
	}*/


	AfxEnableControlContainer();
	
	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CTreeDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CMyTreeView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CTreeApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CTreeApp message handlers

