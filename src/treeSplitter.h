// treeSplitter.h: interface for the CtreeSplitter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREESPLITTER_H__C11AC894_7693_401F_8315_B44932F02168__INCLUDED_)
#define AFX_TREESPLITTER_H__C11AC894_7693_401F_8315_B44932F02168__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4786)
#include <map>
using namespace std;

class CtreeSplitter : public CSplitterWnd  
{
public:
	CtreeSplitter();
	virtual ~CtreeSplitter();
	int AddView(int nRow, int nCol, CRuntimeClass * pViewClass, 
				CCreateContext* pContext);
	void ShowView(int nViewID);
	CWnd* GetView(int nViewID);

protected:
	map<int, long> m_mapViewPane;
	map<long, int> m_mapCurrentViews;
	map<int, CWnd*> m_mapIDViews;

	int m_nIDCounter;

	CWnd* GetCurrentView(int nRow, int nCol, int * nCurID);
	void SetCurrentView(int nRow, int nCol, int nViewID);
	int HideCurrentView(int nRow, int nCol);
	void GetPaneFromViewID(int nViewID, CPoint * pane);

};

#endif // !defined(AFX_TREESPLITTER_H__C11AC894_7693_401F_8315_B44932F02168__INCLUDED_)
