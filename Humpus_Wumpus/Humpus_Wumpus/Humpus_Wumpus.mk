##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Humpus_Wumpus
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Stolk/OneDrive/Documents/GitHub/HU-Hunt-the-wumpus/Humpus_Wumpus
ProjectPath            :=C:/Users/Stolk/OneDrive/Documents/GitHub/HU-Hunt-the-wumpus/Humpus_Wumpus/Humpus_Wumpus
IntermediateDirectory  :=../build-$(ConfigurationName)/Humpus_Wumpus
OutDir                 :=../build-$(ConfigurationName)/Humpus_Wumpus
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Stolk
Date                   :=03/04/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/Users/Stolk/OneDrive/Documents/c++/bin/g++.exe
SharedObjectLinkerName :=C:/Users/Stolk/OneDrive/Documents/c++/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/Users/Stolk/OneDrive/Documents/c++/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/Users/Stolk/OneDrive/Documents/c++/bin/ar.exe rcu
CXX      := C:/Users/Stolk/OneDrive/Documents/c++/bin/g++.exe
CC       := C:/Users/Stolk/OneDrive/Documents/c++/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/Users/Stolk/OneDrive/Documents/c++/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Humpus_Wumpus/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Humpus_Wumpus" mkdir "..\build-$(ConfigurationName)\Humpus_Wumpus"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Humpus_Wumpus" mkdir "..\build-$(ConfigurationName)\Humpus_Wumpus"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Humpus_Wumpus/.d:
	@if not exist "..\build-$(ConfigurationName)\Humpus_Wumpus" mkdir "..\build-$(ConfigurationName)\Humpus_Wumpus"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Stolk/OneDrive/Documents/GitHub/HU-Hunt-the-wumpus/Humpus_Wumpus/Humpus_Wumpus/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/Humpus_Wumpus//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


