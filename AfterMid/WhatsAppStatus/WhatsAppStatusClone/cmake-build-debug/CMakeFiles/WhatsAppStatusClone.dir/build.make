# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\System\__C_Lion\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\System\__C_Lion\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\WhatsAppStatusClone.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\WhatsAppStatusClone.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\WhatsAppStatusClone.dir\flags.make

CMakeFiles\WhatsAppStatusClone.dir\main.cpp.obj: CMakeFiles\WhatsAppStatusClone.dir\flags.make
CMakeFiles\WhatsAppStatusClone.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WhatsAppStatusClone.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\WhatsAppStatusClone.dir\main.cpp.obj /FdCMakeFiles\WhatsAppStatusClone.dir\ /FS -c D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\main.cpp
<<

CMakeFiles\WhatsAppStatusClone.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WhatsAppStatusClone.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\WhatsAppStatusClone.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\main.cpp
<<

CMakeFiles\WhatsAppStatusClone.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WhatsAppStatusClone.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\WhatsAppStatusClone.dir\main.cpp.s /c D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\main.cpp
<<

# Object files for target WhatsAppStatusClone
WhatsAppStatusClone_OBJECTS = \
"CMakeFiles\WhatsAppStatusClone.dir\main.cpp.obj"

# External object files for target WhatsAppStatusClone
WhatsAppStatusClone_EXTERNAL_OBJECTS =

WhatsAppStatusClone.exe: CMakeFiles\WhatsAppStatusClone.dir\main.cpp.obj
WhatsAppStatusClone.exe: CMakeFiles\WhatsAppStatusClone.dir\build.make
WhatsAppStatusClone.exe: CMakeFiles\WhatsAppStatusClone.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WhatsAppStatusClone.exe"
	"D:\System\__C_Lion\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\WhatsAppStatusClone.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100220~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100220~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\WhatsAppStatusClone.dir\objects1.rsp @<<
 /out:WhatsAppStatusClone.exe /implib:WhatsAppStatusClone.lib /pdb:D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\cmake-build-debug\WhatsAppStatusClone.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\WhatsAppStatusClone.dir\build: WhatsAppStatusClone.exe

.PHONY : CMakeFiles\WhatsAppStatusClone.dir\build

CMakeFiles\WhatsAppStatusClone.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\WhatsAppStatusClone.dir\cmake_clean.cmake
.PHONY : CMakeFiles\WhatsAppStatusClone.dir\clean

CMakeFiles\WhatsAppStatusClone.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\cmake-build-debug D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\cmake-build-debug D:\C++\AfterMid\WhatsAppStatus\WhatsAppStatusClone\cmake-build-debug\CMakeFiles\WhatsAppStatusClone.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\WhatsAppStatusClone.dir\depend

