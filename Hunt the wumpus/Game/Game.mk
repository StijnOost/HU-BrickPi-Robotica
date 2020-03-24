##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Game
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :="C:/Users/stijn/OneDrive/Documenten/GitHub/HU-BrickPi-Robotica/Hunt the wumpus"
ProjectPath            :="C:/Users/stijn/OneDrive/Documenten/GitHub/HU-BrickPi-Robotica/Hunt the wumpus/Game"
IntermediateDirectory  :=/Users/stijn/OneDrive/Documenten/GitHub/HU-BrickPi-Robotica/Hunt\ the\ wumpus"/build-$(ConfigurationName)//Users/stijn/OneDrive/Documenten/GitHub/HU-BrickPi-Robotica/Hunt\ the\ wumpus/Game
OutDir                 :=/Users/stijn/OneDrive/Documenten/GitHub/HU-BrickPi-Robotica/Hunt\ the\ wumpus"/build-$(ConfigurationName)//Users/stijn/OneDrive/Documenten/GitHub/HU-BrickPi-Robotica/Hunt\ the\ wumpus/Game
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=stijn
Date                   :=24/03/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
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
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
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
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Game/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Game/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Game" mkdir "..\build-$(ConfigurationName)\Game"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Game" mkdir "..\build-$(ConfigurationName)\Game"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Game/.d:
	@if not exist "..\build-$(ConfigurationName)\Game" mkdir "..\build-$(ConfigurationName)\Game"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Game/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Game/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/stijn/OneDrive/Documenten/GitHub/HU-BrickPi-Robotica/Hunt the wumpus/Game/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Game/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Game/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Game/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Game/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Game/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/Game//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


