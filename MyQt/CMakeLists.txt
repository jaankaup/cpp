cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "/home/janne/Qt")

#set(Qt6_DIR "/home/janne/Downloads/qt6-build/qtbase/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

add_executable(helloworld
	main.cpp
	)

target_link_libraries(helloworld PRIVATE Qt6::Core)
