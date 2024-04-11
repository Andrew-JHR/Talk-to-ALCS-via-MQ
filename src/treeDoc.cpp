// treeDoc.cpp : implementation of the CTreeDoc class
//

#include "stdafx.h"
#include "tree.h"

#include "treeDoc.h"

extern THREADPARMS ThreadParms;   //define in global
extern CWinThread*  pThread;     // ### thread control 

extern ImqQueueManager mgr;               /* Queue manager            */
extern ImqQueue iqueue, oqueue;             /* Queue                         */
extern ImqMessage imsg, omsg;               /* Data message              */
extern ImqGetMessageOptions gmo;         /* Get message options    */
extern ImqChannel chl;                   //channel
extern FILE *outfile;			      		// file for logging
extern CString warning;

extern char buffer[4096];		         /* Message buffer                */
extern CString CRI, LOG, CRTQ;
extern CString CMD, QMGR, QRYQ;
extern CString TIMES,SLEEP;
extern CString IP,CHL,AUTH;
extern int nMsgLen;
extern HWND hWnd_View4;

extern CString oldCRI, oldQRYQ, oldCRTQ;	 // save the original values


MQBYTE correl[MQ_CORREL_ID_LENGTH];			//correlation ID 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc

IMPLEMENT_DYNCREATE(CTreeDoc, CDocument)

BEGIN_MESSAGE_MAP(CTreeDoc, CDocument)
	//{{AFX_MSG_MAP(CTreeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc construction/destruction

CTreeDoc::CTreeDoc()
{
	/*
	// Create a thread for MQGET and suspend it for now
	pThread=AfxBeginThread(CTreeDoc::ThreadMQ,
		&ThreadParms,
		THREAD_PRIORITY_NORMAL,
		0,
		CREATE_SUSPENDED);
		*/
}

CTreeDoc::~CTreeDoc()
{
}

BOOL CTreeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTreeDoc serialization

void CTreeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc diagnostics

#ifdef _DEBUG
void CTreeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTreeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc commands

void CTreeDoc::pack(unsigned char *pk, const char *unpk, int len)
{
	for (int i,j=i=0 ; j < len ; i++ , j += 2)
	{
		unsigned char uc;
		pk[i] = unpk[j];
		if (unpk[j] > '9')		//chk if 'A'-'F' or 'a'-'f'
  			pk[i] += 9;			//yes
		pk[i] <<= 4;			//shift left 4 bits


		uc = unpk[j+1] & 0xf;
		if (unpk[j+1] > '9')
			uc += 9; 
		pk[i] |= uc;
	}
}

void CTreeDoc::unpack(char *unpk, const unsigned char *pk, int len)
{
	unsigned char HexDigit[16] =   
	{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	for (int i,j=i=0 ; j < len-1 ; i++, j += 2)
		{
			unsigned char HB,LB=HB=pk[i];
			HB >>= 4; //shift right 4 bits
			unpk[j] = HexDigit[HB];
			unpk[j+1] = HexDigit[LB & 0xf] ;
		}
	unpk[len-1] = '\0';
}

void CTreeDoc::mqsend(void)
{
// enhance function to allow the dynamic CRI allocation
		if ( (CMD != "ZIN") && (CRI == "070001"))
		{
			AfxMessageBox("070001 Accepts only  'ZIN' , Please Issue 'ZIN' first !");
			return;
		}

		//record to the log file
		if ((outfile = fopen(LOG,"at")) == NULL)
		{
			AfxMessageBox("CANNOT open the Log file");
			return;
		}	

// record to log file
		fputs(CMD,outfile);			//log the command
		fputc(0x0a,outfile);		//CRLF

//set channel name/IP/protocol type
		chl.setChannelName(CHL);
		chl.setTransportType(MQXPT_TCP);
		chl.setConnectionName(IP);
		mgr.setChannelReference(&chl);

		mgr.setName(QMGR);			//qmanager name
	  
		if ( ! mgr.connect())  //  Connect to queue manager
		{
			warning.Format("MQ Connect Failed with %ld",(long)mgr.reasonCode());
			AfxMessageBox(warning);
			return;
		}

		oqueue.setConnectionReference(mgr);  // Associate queue with queue manager.
		iqueue.setConnectionReference(mgr);  // Associate queue with queue manager.
		
		oqueue.setName(QRYQ);
		oqueue.setOpenOptions(MQOO_OUTPUT + MQOO_FAIL_IF_QUIESCING);
		oqueue.open();
		if (oqueue.reasonCode())
		{
			warning.Format("MQOPEN(out) Failed with %ld",(long)mgr.reasonCode());
			AfxMessageBox(warning);
		}
		if (oqueue.completionCode() == MQCC_FAILED)
			AfxMessageBox("Unable to Open the Output Queue");

	
        iqueue.setName(CRTQ);		//set input queue name
		iqueue.setOpenOptions(MQOO_INPUT_SHARED + MQOO_FAIL_IF_QUIESCING);  
		iqueue.open();
		if (iqueue.reasonCode()) 
		{
			warning.Format("MQOPEN(in) Failed with %ld",(long)mgr.reasonCode());
			AfxMessageBox(warning);
		}
		if (iqueue.completionCode() == MQCC_FAILED ) 
			AfxMessageBox("Unable to Open the Input Queue");

		imsg.useEmptyBuffer(buffer,sizeof(buffer)-1);   //set pointer for input message
		omsg.useEmptyBuffer(buffer,sizeof(buffer)-1);  //set pointer for output message


//     set the correlation id
		for (int i=0 ; i< MQ_CORREL_ID_LENGTH ; i++)
			correl[i] = '\0';
		MQBYTE CRI3[3];				//CRI in binary
		pack(CRI3,CRI,6);			//pack the CRI
		memcpy(&correl[MQ_CORREL_ID_LENGTH-3],CRI3,3);  //rightmost 3 byte of correlid as CRI

//		if (CRI == "070001")
			memcpy(correl , AUTH,20);       //also put the authorization code for ZIN entry	

		gmo.setOptions( MQGMO_FAIL_IF_QUIESCING );

// clean up all previously existing msgs if any to make sure 1 send and 1 response
		while (TRUE)
		{
			imsg.setMessageId();			//no particular selective condition on MSGID
			imsg.setCorrelationId(correl);		//no particular selective condition on CORRELID
			if ( ! iqueue.get(imsg,gmo)) // if get fail
			  break;
		} // mqget till mo more msgs available

//prepare data to mqput
		// check if there is a pair of CRLF(0x0d,0x0a) and remove CR and keep LF
		int CMDlen =CMD.GetLength();
		char * pCMD = CMD.GetBufferSetLength(CMDlen);
		for (int i=0 ; i < CMDlen ; i++)
		{
			if (pCMD[i] == 0x0d)
			{
				memcpy(&pCMD[i],&pCMD[i+1],CMDlen-i+1);
			}
		}
		CMD.ReleaseBuffer();  //let the CString update the real length 

		// add 'EOM' to the end of the input entry
		CMD = CMD + "+";

		strcpy(buffer,CMD);
		omsg.setMessageLength(CMD.GetLength());
		
		omsg.setFormat(MQFMT_STRING);	//force to do the code xlat.

		//set the correlation ID and clear replytoqueue related fields
		omsg.setCorrelationId(correl); //set correlid
		omsg.setReplyToQueueName();
		omsg.setReplyToQueueManagerName();
		omsg.setCharacterSet(950);  // make the character set is correct

		if (!oqueue.put(omsg)) // send out the query
		{
			warning.Format("MQPUT Failed with %ld",(long)mgr.reasonCode());
			AfxMessageBox(warning);
		}

		if (!oqueue.close()) 
		{
			warning.Format("MQCLOSE(out) Failed with %ld",(long)mgr.reasonCode());
			AfxMessageBox(warning);
		}

/*		if (!iqueue.close()) 
		{
			warning.Format("MQCLOSE(in) Failed with %ld",(long)mgr.reasonCode());
			AfxMessageBox(warning);
		}
*/
		fclose(outfile);	//close the log file                                 
	
		if ( !mgr.disconnect()) // Disconnect from MQM
		{
			warning.Format("MQ Disconnect Failed with %ld",(long)mgr.reasonCode());
			AfxMessageBox(warning);
		} 

		ThreadParms.pBfr = buffer;
//		pThread->ResumeThread();
		pThread=AfxBeginThread(CTreeDoc::ThreadMQ,&ThreadParms);
}

UINT CTreeDoc::ThreadMQ(LPVOID pParam)
{
	THREADPARMS* ptp = (THREADPARMS*) pParam;
	HWND hWnd = ptp->hWnd;
	char* buffer = ptp->pBfr;

	DWORD mSeconds = atoi(SLEEP);		// xlat into digits
	int   RetryTimes = atoi(TIMES);		// xlat into digits

	//record to the log file
	if ((outfile = fopen(LOG,"at")) == NULL)
	{
		AfxMessageBox("CANNOT open the Log file");
		return 0;
	}	
/*
	mgr.setName(QMGR);			//qmanager name
	  
	if ( ! mgr.connect())  //  Connect to queue manager
	{
		warning.Format("MQ Connect Failed with %ld",(long)mgr.reasonCode());
		AfxMessageBox(warning);
		return 0;
	}
*/
//	iqueue.setConnectionReference(mgr);  // Associate queue with queue manager.
//	iqueue.setName(CRTQ);		//set input queue name
//	iqueue.setOpenOptions(MQOO_INPUT_SHARED + MQOO_FAIL_IF_QUIESCING);  
/*	iqueue.open();
	if (iqueue.reasonCode()) 
	{
		warning.Format("MQOPEN(in) Failed with %ld",(long)mgr.reasonCode());
		AfxMessageBox(warning);
	}
	if (iqueue.completionCode() == MQCC_FAILED ) 
		AfxMessageBox("Unable to Open the Input Queue");
*/
//	msg.useEmptyBuffer(buffer,4095);
    
	gmo.setOptions( MQGMO_CONVERT + MQGMO_FAIL_IF_QUIESCING );  //force to xlat the code

	//get the response
		for (int k=0 ; k < RetryTimes ; k++)
		{
			imsg.setMessageId();
			imsg.setCorrelationId(correl);
			imsg.setCharacterSet(950);

			if ( iqueue.get(imsg,gmo))
			{
				nMsgLen = imsg.dataLength();
				for ( int i=0 ; i < nMsgLen ; i++)
				{
					if (buffer[i] == 0x7f)
						buffer[i] = 0x0a;
					fputc(buffer[i],outfile);
				}
				break; 
			} // end of if successful mqget
			else if ( iqueue.reasonCode() != MQRC_NO_MSG_AVAILABLE ) 
			{
				warning.Format("MQGET Failed with %ld",(long)mgr.reasonCode());
				AfxMessageBox(warning);
				break;
			} 
			else 
			{
				Sleep(mSeconds); // wait this interval for the next retry
			}
		} //end of the RetryTimes loop

		if ( CRI == "070001" )   // ZIN entry for dynamic CRI allocation
		{
				unsigned char msgid[MQ_MSG_ID_LENGTH];
				char cri7[7];
				imsg.messageId().copyOut(msgid , MQ_MSG_ID_LENGTH);
                unpack(cri7 , &msgid[MQ_MSG_ID_LENGTH-3],7);				
				
				if ( strcmp(cri7,"000000") == 0 )
				{
					AfxMessageBox("Time Out !!");
				}
				else if  ( strcmp(cri7,"999999") !=  0 ) 
				{
					oldCRI		= CRI;				//save the original cri for later use
					oldQRYQ = QRYQ;			//save the original qurey queue name for later use
					oldCRTQ	= CRTQ;			//save the original reply queue name for later use
					CRI = cri7; 
					QRYQ = (CString)  imsg.replyToQueueName();
					CRTQ =  (CString)  imsg.replyToQueueManagerName();
					::PostMessage(hWnd_View4,WM_USER_CRI_ALLOCATION,0,0);
				}
				else
				{
					AfxMessageBox("No More Session Available !!");
				}
		} // end of if  CRI = 070001
		if ( (CRI != "070001") && ( CMD == "ZOU+" ) )
		{
			CRI		= oldCRI;		// restore all the values
			QRYQ	= oldQRYQ;
			CRTQ	= oldCRTQ;
			::PostMessage(hWnd_View4,WM_USER_CRI_ALLOCATION,0,0);
		}
		if ( strncmp(&buffer[2],"MQCRIINV",8) == 0)
		{
			AfxMessageBox("Please re-allocate the CRI by entering 'ZIN' !");
			CRI		= oldCRI;		// restore all the values
			QRYQ	= oldQRYQ;
			CRTQ	= oldCRTQ;
			::PostMessage(hWnd_View4,WM_USER_CRI_ALLOCATION,0,0);
		}

// Close input queue
	if ( !iqueue.close())
	{
		warning.Format("MQCLOSE(in) Failed with %ld",(long)mgr.reasonCode());
		AfxMessageBox(warning);
	}


		fclose(outfile);	//close the log file                                 
	
		if ( !mgr.disconnect()) // Disconnect from MQM
		{
			warning.Format("MQ Disconnect Failed with %ld",(long)mgr.reasonCode());
			AfxMessageBox(warning);
		} 

		::PostMessage(hWnd,WM_USER_THRDMQ_FINISHED,0,0);
		
	//	pThread->SuspendThread();		//Be standby for next call

	return 0;
}

//					UpdateAllViews(NULL);    //command view4 to keep up with the changes
