// treeDoc.h : interface of the CTreeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEDOC_H__AB40DC4A_714C_4132_AE51_4BD47C30E331__INCLUDED_)
#define AFX_TREEDOC_H__AB40DC4A_714C_4132_AE51_4BD47C30E331__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "imqi.hpp"   //for MQ API
#pragma comment(lib,"imqb23vn.lib")
#pragma comment(lib,"imqc23vn.lib")

class CTreeDoc : public CDocument
{
protected: // create from serialization only
	CTreeDoc();
	DECLARE_DYNCREATE(CTreeDoc)

// Attributes

// Operations
private:
	void pack(unsigned char* , const char*, int);	//destination,source,length of source
	static void unpack(char *, const unsigned char *, int);//desti.,source,length of destination
	static UINT ThreadMQ(LPVOID);				//### function to execute on the worker thread
public:
	void mqsend(void);		//mq message send and receive

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEDOC_H__AB40DC4A_714C_4132_AE51_4BD47C30E331__INCLUDED_)
