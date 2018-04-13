cmake_minimum_required(VERSION 3.10)
project(project)

set(CMAKE_CXX_STANDARD 11)

add_executable(project
        main.cpp
        tree.cpp
        branch.cpp)

INCLUDE_DIRECTORIES (/System/Library/Frameworks)
find_library(COCOA_LIBRARY Cocoa)
find_library(GLUT_LIBRARY GLUT )
find_library(OpenGL_LIBRARY OpenGL )
MARK_AS_ADVANCED (COCOA_LIBRARY
        GLUT_LIBRARY
        OpenGL_LIBRARY)
set(EXTRA_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})

include_directories(include/vecmath)
include_directories(/usr/X11R6/include/)
link_directories(/usr/X11R6/lib)
target_link_libraries(project ${EXTRA_LIBS})
