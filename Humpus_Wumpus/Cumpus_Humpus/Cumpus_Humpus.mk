##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Cumpus_Humpus
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/stijn/OneDrive/Documenten/Documenten/Github/HU-BrickPi-Robotica/Humpus_Wumpus
ProjectPath            :=C:/Users/stijn/OneDrive/Documenten/Documenten/Github/HU-BrickPi-Robotica/Humpus_Wumpus/Cumpus_Humpus
IntermediateDirectory  :=../build-$(ConfigurationName)/Cumpus_Humpus
OutDir                 :=../build-$(ConfigurationName)/Cumpus_Humpus
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=stijn
Date                   :=08/04/2020
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
Objects0=../build-$(ConfigurationName)/Cumpus_Humpus/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Cumpus_Humpus/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Cumpus_Humpus" mkdir "..\build-$(ConfigurationName)\Cumpus_Humpus"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Cumpus_Humpus" mkdir "..\build-$(ConfigurationName)\Cumpus_Humpus"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Cumpus_Humpus/.d:
	@if not exist "..\build-$(ConfigurationName)\Cumpus_Humpus" mkdir "..\build-$(ConfigurationName)\Cumpus_Humpus"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Cumpus_Humpus/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Cumpus_Humpus/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/stijn/OneDrive/Documenten/Documenten/Github/HU-BrickPi-Robotica/Humpus_Wumpus/Cumpus_Humpus/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Cumpus_Humpus/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Cumpus_Humpus/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Cumpus_Humpus/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Cumpus_Humpus/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Cumpus_Humpus/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/Cumpus_Humpus//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


