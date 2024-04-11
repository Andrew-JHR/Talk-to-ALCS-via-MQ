// View4.cpp : implementation file
//

#include "stdafx.h"
#include "tree.h"
#include "View4.h"
#include ".\view4.h"

extern char buffer[4096];		         /* Message buffer                */
extern CString CRI, LOG, CRTQ;
extern CString CMD, QMGR, QRYQ;
extern CString TIMES,SLEEP;
extern CString IP,CHL,AUTH;
extern int nMsgLen;

extern HWND hWnd_View4;			//hwnd for view4;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// View4

IMPLEMENT_DYNCREATE(CView4, CFormView)

CView4::CView4()
	: CFormView(CView4::IDD)
{
	//{{AFX_DATA_INIT(View4)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CView4::~CView4()
{
}

void CView4::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(View4)
	DDX_Control(pDX, IDC_TIMES, m_TIMES);
	DDX_Control(pDX, IDC_SLEEP, m_SLEEP);
	DDX_Control(pDX, IDC_IP, m_IP);
	DDX_Control(pDX, IDC_QRYQ, m_QRYQ);
	DDX_Control(pDX, IDC_QMGR, m_QMGR);
	DDX_Control(pDX, IDC_OPEN, m_OPEN);
	DDX_Control(pDX, IDC_LOG, m_LOG);
	DDX_Control(pDX, IDC_CRTQ, m_CRTQ);
	DDX_Control(pDX, IDC_CRI, m_CRI);
	DDX_Control(pDX, IDC_INI, m_INI);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_AUTH, m_AUTH);
	DDX_Control(pDX, IDC_CHL, m_CHL);
}


BEGIN_MESSAGE_MAP(CView4, CFormView)
	//{{AFX_MSG_MAP(CView4)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_DIR, OnDir)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_EN_CHANGE(IDC_INI, OnEnChangeIni)
	ON_EN_CHANGE(IDC_CRI, OnEnChangeCri)
	ON_EN_CHANGE(IDC_QMGR, OnEnChangeQmgr)
	ON_EN_CHANGE(IDC_QRYQ, OnEnChangeQryq)
	ON_EN_CHANGE(IDC_CRTQ, OnEnChangeCrtq)
	ON_EN_CHANGE(IDC_LOG, OnEnChangeLog)
	ON_EN_CHANGE(IDC_SLEEP, OnEnChangeSleep)
	ON_EN_CHANGE(IDC_TIMES, OnEnChangeTimes)
	ON_EN_CHANGE(IDC_IP, OnEnChangeIp)
	ON_EN_CHANGE(IDC_CHL, OnEnChangeChl)
	ON_EN_CHANGE(IDC_AUTH, OnEnChangeAuth)
	ON_MESSAGE(WM_USER_CRI_ALLOCATION,OnCriAllocation)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// View4 diagnostics

#ifdef _DEBUG
void CView4::AssertValid() const
{
	CFormView::AssertValid();
}

void CView4::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// View4 message handlers

void CView4::OnDir()
{
	CFileDialog FileDlg(TRUE);
	if (FileDlg.DoModal() == IDOK)
	{
		m_INI.SetWindowText(FileDlg.GetPathName());	
		OnOpen(); // go open the INI file directly
	}
 }

	void CView4::OnInitialUpdate()
	{
		CFormView::OnInitialUpdate();
		GetParentFrame()->RecalcLayout();
		ResizeParentToFit();
		m_INI.SetWindowText("d:\\MQALCSPROD.INI"); //default ini file
		m_CRI.EnableWindow(FALSE);
		OnOpen();  // go open the INI file directly
		hWnd_View4 = m_hWnd;   // save the window handler
	}

	void CView4::OnOpen()
	{
			FILE *ini; 
			CString strINI;
			m_INI.GetWindowText(strINI);
			if ((ini=fopen(strINI,"r"))==NULL)
			{
				AfxMessageBox("Cannot open INI file !");
			}
			else
			{
				int i,j,k;
				char inibfr[132];

				for (i=0 ; i<11 ; i++)                    
				{
					if (fgets(inibfr,sizeof(inibfr),ini) == NULL)
					{
						AfxMessageBox("No enough INI parameters provided in INI !");
						break;
					}
					else
					{
						for (j=0 ; j < sizeof(inibfr) ; j++)
						{
    						if (inibfr[j] == '=') break;
						}
					  
						++j;          // next char
					  
						while (inibfr[j] == ' ')    // bypass blanks
						{
							j++;
						}
						k=0;
						while ( (inibfr[j] != ' ') && (inibfr[j] != 0x00) && (inibfr[j] != 0x0a) )
						{
							parm[i][k++] = inibfr[j++];		  
						}
						parm[i][k]='\0';  // construct a string
					} // end of else
				} //end of for loop 9

				fclose(ini);		//get parms complete
			
				m_QMGR.SetWindowText(parm[0]);    //set queue manager name
				QMGR = parm[0];									//also set the document's member
				m_IP.SetWindowText(parm[1]);			 //set the QMGR's IP address
				IP = parm[1];		                				//save to the global variable

				m_QRYQ.SetWindowText(parm[2]);    //set the query queue name

				m_CRTQ.SetWindowText(parm[3]);     //set the CRT Queue name header
																			//save later  to the document's member
				m_LOG.SetWindowText(parm[4]);       //set the log file name header

/*				int iCRT =(strlen(parm[5])+1)/7;					//get the valid CRIs
				for (i=0; i < iCRT ; i++)
				{
					char temp[7];
					strncpy(temp,&parm[5][i*7],6);
					temp[6] = '\0';
					m_CRI.AddString(temp);
				}


				m_CRI.SetCurSel(0);						   //choose the first one
				m_CRI.GetLBText(0,CRI);					//get the chosen CRI
*/

				m_CRI.SetWindowText(parm[5]);
				CRI = parm[5];
				LOG = parm[4] + CRI + ".txt";				//save to document
				QRYQ = parm[2];						//also set the document's member
				CRTQ = parm[3];						//save to document
				m_QRYQ.SetWindowText(QRYQ);		//reset the screen
				m_CRTQ.SetWindowText(CRTQ);		//reset the screen	
				m_LOG.SetWindowText(LOG);			//reset the screen

				m_TIMES.SetWindowText(parm[7]); //set the MQGET retry times
				TIMES = parm[7];								//also set the document's member
				m_SLEEP.SetWindowText(parm[8]); //set the retry wait time (mSeconds)
				SLEEP = parm[8];								//save to document

				m_CHL.SetWindowText(parm[9]);    //channel name
				CHL = parm[9];
				m_AUTH.SetWindowText(parm[10]); //Auth. code
				AUTH=parm[10];

				m_OPEN.EnableWindow(FALSE); //disable the open button
				m_CRI.EnableWindow(TRUE);

			} // end of else --- open INI file is successful
	} // end of OnOpen
	void CView4::OnEnChangeIni()
	{
			m_CRI.EnableWindow(FALSE);
			m_OPEN.EnableWindow(TRUE);
//			m_CRI.ResetContent();   // clear the previous choices
	}

	void CView4::OnEnChangeCri()
	{
//		int nSel = m_CRI.GetCurSel();
//		m_CRI.GetLBText(nSel,CRI);		//get the chosen CRI

//		m_CRI.GetWindowText(CRI);
		LOG = parm[4] + CRI + ".txt";
//		QRYQ = parm[2]+ CRI;				//also set the document's member
//		CRTQ = parm[3] + CRI;
//		m_QRYQ.SetWindowText(QRYQ);
//		m_CRTQ.SetWindowText(CRTQ);
		m_LOG.SetWindowText(LOG);
	}

	void CView4::OnEnChangeQmgr()
	{
		m_QMGR.GetWindowText(QMGR);
	}

	void CView4::OnEnChangeQryq()
	{
		m_QRYQ.GetWindowText(QRYQ);
	}

	void CView4::OnEnChangeCrtq()
	{
		m_CRTQ.GetWindowText(CRTQ);
	}

	void CView4::OnEnChangeLog()
	{
		m_LOG.GetWindowText(LOG);
	}

	void CView4::OnEnChangeSleep()
	{
		m_SLEEP.GetWindowText(SLEEP);
	}

	void CView4::OnEnChangeTimes()
	{
		m_TIMES.GetWindowText(TIMES);
	}

	void CView4::OnEnChangeIp()
	{
		m_IP.GetWindowText(IP);
	}

	void CView4::OnEnChangeChl()
	{
		m_CHL.GetWindowText(CHL);
	}

	void CView4::OnEnChangeAuth()
	{
		m_AUTH.GetWindowText(AUTH);
	}

	LONG CView4::OnCriAllocation(WPARAM wParam, LPARAM lParam )
{
				m_CRI.SetWindowText(CRI);
				m_QRYQ.SetWindowText(QRYQ);		//reset the screen
				m_CRTQ.SetWindowText(CRTQ);		//reset the screen	
	return 0;
}


