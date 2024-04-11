# Microsoft Developer Studio Generated NMAKE File, Based on tree.dsp
!IF "$(CFG)" == ""
CFG=tree - Win32 Debug
!MESSAGE No configuration specified. Defaulting to tree - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "tree - Win32 Release" && "$(CFG)" != "tree - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tree.mak" CFG="tree - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "tree - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "tree - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "tree - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\tree.exe"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tree.obj"
	-@erase "$(INTDIR)\tree.pch"
	-@erase "$(INTDIR)\tree.res"
	-@erase "$(INTDIR)\treeDoc.obj"
	-@erase "$(INTDIR)\treeSplitter.obj"
	-@erase "$(INTDIR)\treeView.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\View1.obj"
	-@erase "$(INTDIR)\View2.obj"
	-@erase "$(INTDIR)\View3.obj"
	-@erase "$(OUTDIR)\tree.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tree.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\tree.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tree.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\tree.pdb" /machine:I386 /out:"$(OUTDIR)\tree.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tree.obj" \
	"$(INTDIR)\treeDoc.obj" \
	"$(INTDIR)\treeSplitter.obj" \
	"$(INTDIR)\treeView.obj" \
	"$(INTDIR)\View1.obj" \
	"$(INTDIR)\View2.obj" \
	"$(INTDIR)\View3.obj" \
	"$(INTDIR)\tree.res"

"$(OUTDIR)\tree.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "tree - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\tree.exe" "$(OUTDIR)\tree.bsc"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\tree.obj"
	-@erase "$(INTDIR)\tree.pch"
	-@erase "$(INTDIR)\tree.res"
	-@erase "$(INTDIR)\tree.sbr"
	-@erase "$(INTDIR)\treeDoc.obj"
	-@erase "$(INTDIR)\treeDoc.sbr"
	-@erase "$(INTDIR)\treeSplitter.obj"
	-@erase "$(INTDIR)\treeSplitter.sbr"
	-@erase "$(INTDIR)\treeView.obj"
	-@erase "$(INTDIR)\treeView.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\View1.obj"
	-@erase "$(INTDIR)\View1.sbr"
	-@erase "$(INTDIR)\View2.obj"
	-@erase "$(INTDIR)\View2.sbr"
	-@erase "$(INTDIR)\View3.obj"
	-@erase "$(INTDIR)\View3.sbr"
	-@erase "$(OUTDIR)\tree.bsc"
	-@erase "$(OUTDIR)\tree.exe"
	-@erase "$(OUTDIR)\tree.ilk"
	-@erase "$(OUTDIR)\tree.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\tree.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\tree.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tree.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\tree.sbr" \
	"$(INTDIR)\treeDoc.sbr" \
	"$(INTDIR)\treeSplitter.sbr" \
	"$(INTDIR)\treeView.sbr" \
	"$(INTDIR)\View1.sbr" \
	"$(INTDIR)\View2.sbr" \
	"$(INTDIR)\View3.sbr"

"$(OUTDIR)\tree.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\tree.pdb" /debug /machine:I386 /out:"$(OUTDIR)\tree.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tree.obj" \
	"$(INTDIR)\treeDoc.obj" \
	"$(INTDIR)\treeSplitter.obj" \
	"$(INTDIR)\treeView.obj" \
	"$(INTDIR)\View1.obj" \
	"$(INTDIR)\View2.obj" \
	"$(INTDIR)\View3.obj" \
	"$(INTDIR)\tree.res"

"$(OUTDIR)\tree.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("tree.dep")
!INCLUDE "tree.dep"
!ELSE 
!MESSAGE Warning: cannot find "tree.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "tree - Win32 Release" || "$(CFG)" == "tree - Win32 Debug"
SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "tree - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "tree - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tree.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tree.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\tree.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\tree.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\tree.cpp

!IF  "$(CFG)" == "tree - Win32 Release"


"$(INTDIR)\tree.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"


"$(INTDIR)\tree.obj"	"$(INTDIR)\tree.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ENDIF 

SOURCE=.\tree.rc

"$(INTDIR)\tree.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\treeDoc.cpp

!IF  "$(CFG)" == "tree - Win32 Release"


"$(INTDIR)\treeDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"


"$(INTDIR)\treeDoc.obj"	"$(INTDIR)\treeDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ENDIF 

SOURCE=.\treeSplitter.cpp

!IF  "$(CFG)" == "tree - Win32 Release"


"$(INTDIR)\treeSplitter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"


"$(INTDIR)\treeSplitter.obj"	"$(INTDIR)\treeSplitter.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ENDIF 

SOURCE=.\treeView.cpp

!IF  "$(CFG)" == "tree - Win32 Release"


"$(INTDIR)\treeView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"


"$(INTDIR)\treeView.obj"	"$(INTDIR)\treeView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ENDIF 

SOURCE=.\View1.cpp

!IF  "$(CFG)" == "tree - Win32 Release"


"$(INTDIR)\View1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"


"$(INTDIR)\View1.obj"	"$(INTDIR)\View1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ENDIF 

SOURCE=.\View2.cpp

!IF  "$(CFG)" == "tree - Win32 Release"


"$(INTDIR)\View2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"


"$(INTDIR)\View2.obj"	"$(INTDIR)\View2.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ENDIF 

SOURCE=.\View3.cpp

!IF  "$(CFG)" == "tree - Win32 Release"


"$(INTDIR)\View3.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"


"$(INTDIR)\View3.obj"	"$(INTDIR)\View3.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tree.pch"


!ENDIF 


!ENDIF 

