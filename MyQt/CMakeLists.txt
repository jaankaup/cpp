# Available platform plugins are: offscreen, minimalegl, minimal, eglfs, linuxfb, vnc, wayland-egl, wayland.

cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

list(APPEND CMAKE_PREFIX_PATH "/home/janne/Qt6")

#set(Qt6_DIR "/home/janne/Downloads/qt6-build/qtbase/lib/cmake")

#find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(mylib STATIC window.cpp window.h)
# target_include_directories(mylib PUBLIC include)
target_compile_features(mylib PUBLIC cxx_std_17)
target_link_libraries(mylib PRIVATE Qt6::Widgets)

add_executable(helloworld
	main.cpp
	)

#target_link_libraries(helloworld PRIVATE Qt6::Core)
target_link_libraries(helloworld PRIVATE Qt6::Widgets mylib)

# set_target_properties(helloworld PROPERTIES
#     WIN32_EXECUTABLE ON
#     MACOSX_BUNDLE ON
#)
