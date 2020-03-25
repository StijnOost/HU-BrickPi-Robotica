##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Jari_Project
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/alexa/OneDrive/Documents/GitHub/HU-BrickPi-Robotica/Humpus_Wumpus
ProjectPath            :=C:/Users/alexa/OneDrive/Documents/GitHub/HU-BrickPi-Robotica/Humpus_Wumpus/Jari_Project
IntermediateDirectory  :=../build-$(ConfigurationName)/Jari_Project
OutDir                 :=../build-$(ConfigurationName)/Jari_Project
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=alexa
Date                   :=25/03/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="C:/Program Files/TDM-GCC/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files/TDM-GCC/bin/g++.exe" -shared -fPIC
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
RcCompilerName         :="C:/Program Files/TDM-GCC/bin/windres.exe"
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
AR       := "C:/Program Files/TDM-GCC/bin/ar.exe" rcu
CXX      := "C:/Program Files/TDM-GCC/bin/g++.exe"
CC       := "C:/Program Files/TDM-GCC/bin/gcc.exe"
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files/TDM-GCC/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Jari_Project/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Jari_Project/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Jari_Project" mkdir "..\build-$(ConfigurationName)\Jari_Project"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Jari_Project" mkdir "..\build-$(ConfigurationName)\Jari_Project"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Jari_Project/.d:
	@if not exist "..\build-$(ConfigurationName)\Jari_Project" mkdir "..\build-$(ConfigurationName)\Jari_Project"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Jari_Project/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Jari_Project/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alexa/OneDrive/Documents/GitHub/HU-BrickPi-Robotica/Humpus_Wumpus/Jari_Project/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Jari_Project/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Jari_Project/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Jari_Project/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Jari_Project/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Jari_Project/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/Jari_Project//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


