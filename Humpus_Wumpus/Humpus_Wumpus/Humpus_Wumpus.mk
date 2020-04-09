##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Humpus_Wumpus
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/alexa/OneDrive/Documents/GitHub/HU-BrickPi-Robotica/Humpus_Wumpus
ProjectPath            :=C:/Users/alexa/OneDrive/Documents/GitHub/HU-BrickPi-Robotica/Humpus_Wumpus/Humpus_Wumpus
IntermediateDirectory  :=../build-$(ConfigurationName)/Humpus_Wumpus
OutDir                 :=../build-$(ConfigurationName)/Humpus_Wumpus
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=alexa
Date                   :=09/04/2020
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
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files/TDM-GCC/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Humpus_Wumpus/wumpusAI.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Humpus_Wumpus/customizeWumpus.cpp$(ObjectSuffix) 



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
../build-$(ConfigurationName)/Humpus_Wumpus/wumpusAI.cpp$(ObjectSuffix): wumpusAI.cpp ../build-$(ConfigurationName)/Humpus_Wumpus/wumpusAI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alexa/OneDrive/Documents/GitHub/HU-BrickPi-Robotica/Humpus_Wumpus/Humpus_Wumpus/wumpusAI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wumpusAI.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Humpus_Wumpus/wumpusAI.cpp$(DependSuffix): wumpusAI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Humpus_Wumpus/wumpusAI.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Humpus_Wumpus/wumpusAI.cpp$(DependSuffix) -MM wumpusAI.cpp

../build-$(ConfigurationName)/Humpus_Wumpus/wumpusAI.cpp$(PreprocessSuffix): wumpusAI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Humpus_Wumpus/wumpusAI.cpp$(PreprocessSuffix) wumpusAI.cpp

../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alexa/OneDrive/Documents/GitHub/HU-BrickPi-Robotica/Humpus_Wumpus/Humpus_Wumpus/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Humpus_Wumpus/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Humpus_Wumpus/customizeWumpus.cpp$(ObjectSuffix): customizeWumpus.cpp ../build-$(ConfigurationName)/Humpus_Wumpus/customizeWumpus.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/alexa/OneDrive/Documents/GitHub/HU-BrickPi-Robotica/Humpus_Wumpus/Humpus_Wumpus/customizeWumpus.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/customizeWumpus.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Humpus_Wumpus/customizeWumpus.cpp$(DependSuffix): customizeWumpus.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Humpus_Wumpus/customizeWumpus.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Humpus_Wumpus/customizeWumpus.cpp$(DependSuffix) -MM customizeWumpus.cpp

../build-$(ConfigurationName)/Humpus_Wumpus/customizeWumpus.cpp$(PreprocessSuffix): customizeWumpus.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Humpus_Wumpus/customizeWumpus.cpp$(PreprocessSuffix) customizeWumpus.cpp


-include ../build-$(ConfigurationName)/Humpus_Wumpus//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


