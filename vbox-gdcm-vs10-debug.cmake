# Client maintainer: mathieu malaterre gmail . com

set(CTEST_SITE "vbox_win7")
set(CTEST_BUILD_NAME "Win7-vs10-Debug")
set(CTEST_BUILD_CONFIGURATION Debug)
set(CTEST_CMAKE_GENERATOR "Visual Studio 10")
#set(CTEST_DASHBOARD_ROOT "c:/cygwin/home/mathieu/Dashboard/gdcm-vs9/")
set(dashboard_binary_name "gdcm-build-debug-32-nightly")

SET(CTEST_GIT_COMMAND "C:/cygwin/bin/git.exe")
#SET(ENV{CFLAGS} "/W4")
#SET(ENV{CXXFLAGS} "/W4")

macro(dashboard_hook_init)
  set( dashboard_cache "
    GDCM_BUILD_SHARED_LIBS:BOOL=ON
    GDCM_BUILD_APPLICATIONS:BOOL=ON
    GDCM_BUILD_EXAMPLES:BOOL=ON
    GDCM_USE_VTK:BOOL=ON
    VTK_DIR:PATH=$ENV{HOME}/Dashboards/${dashboard_root_name}/vtk-vs10-debug
    "
    )
endmacro(dashboard_hook_init)

include(${CTEST_SCRIPT_DIRECTORY}/gdcm_common.cmake)