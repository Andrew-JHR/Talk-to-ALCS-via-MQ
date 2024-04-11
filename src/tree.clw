; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CView4
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "tree.h"
LastPage=0

ClassCount=9
Class1=CTreeApp
Class2=CTreeDoc
Class3=CMyTreeView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Resource3=IDD_VIEW1_FORM
Class6=CView1
Resource4=IDD_VIEW2_FORM
Class7=CView2
Class8=CView3
Resource5=IDD_VIEW3_FORM
Class9=CView4
Resource6=IDD_VIEW4_FORM

[CLS:CTreeApp]
Type=0
HeaderFile=tree.h
ImplementationFile=tree.cpp
Filter=N

[CLS:CTreeDoc]
Type=0
HeaderFile=treeDoc.h
ImplementationFile=treeDoc.cpp
Filter=N

[CLS:CMyTreeView]
Type=0
HeaderFile=treeView.h
ImplementationFile=treeView.cpp
Filter=C
BaseClass=CTreeView
VirtualFilter=VWC
LastObject=CMyTreeView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=tree.cpp
ImplementationFile=tree.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_VIEW1_FORM]
Type=1
Class=CView1
ControlCount=4
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_LIST1,listbox,1352728835
Control4=IDC_STATIC,static,1342308352

[CLS:CView1]
Type=0
HeaderFile=View1.h
ImplementationFile=View1.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=VWC

[DLG:IDD_VIEW2_FORM]
Type=1
Class=CView2
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,button,1342177287
Control3=IDC_MONTHCALENDAR1,SysMonthCal32,1342242832

[CLS:CView2]
Type=0
HeaderFile=View2.h
ImplementationFile=View2.cpp
BaseClass=CFormView
Filter=D

[DLG:IDD_VIEW3_FORM]
Type=1
Class=CView3
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_TREE1,SysTreeView32,1350631424

[CLS:CView3]
Type=0
HeaderFile=View3.h
ImplementationFile=View3.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_TREE1

[DLG:IDD_VIEW4_FORM]
Type=1
Class=CView4
ControlCount=21
Control1=IDC_INI,edit,1350631552
Control2=IDC_DIR,button,1342242816
Control3=IDC_OPEN,button,1342242816
Control4=IDC_CRI,combobox,1344340227
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_QMGR,edit,1350631552
Control8=IDC_CRTQ,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_QRYQ,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_RPLYQ,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_LOG,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_TIMES,edit,1350639744
Control19=IDC_STATIC,static,1342308352
Control20=IDC_SLEEP,edit,1350639744
Control21=IDC_STATIC,static,1342308352

[CLS:CView4]
Type=0
HeaderFile=view4.h
ImplementationFile=view4.cpp
BaseClass=CFormView
LastObject=CView4
