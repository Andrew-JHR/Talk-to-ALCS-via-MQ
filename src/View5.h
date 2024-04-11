#pragma once

#include "treeDoc.h"
#include "afxwin.h"

// CView5 ����˵�


class CView5 : public CFormView
{
	DECLARE_DYNCREATE(CView5)

protected:
	CView5();           // �ʺA�إߩҨϥΪ��O�@�غc�禡
	virtual ~CView5();

public:
	enum { IDD = IDD_VIEW5_FORM };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
	
protected:	
	HACCEL m_hAccel;
private:
	int nCurLine;

public:
	CEdit m_INPUT;
	CListBox m_OUTPUT;

public:
	afx_msg void OnBnClickedEnter();
	afx_msg void OnLbnDblclkOutput();
	afx_msg void OnLbnErrspaceOutput();
	afx_msg void OnBnClickedClear();
	afx_msg LONG OnThreadFinished(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnInitialUpdate();
protected:
//	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);

};
//extern CView5 theView5;

