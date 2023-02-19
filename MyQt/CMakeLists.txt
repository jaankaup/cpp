cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

list(APPEND CMAKE_PREFIX_PATH "/home/janne/Qt6")

#find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Create custom window.
add_library(mylib STATIC src/window.cpp
                         src/window.h
                         src/card_loader.cpp
                         src/card_loader.h
                         src/card.cpp
                         src/card.h
                         src/misc.cpp
                         src/misc.h
                         src/booster.h
                         src/booster.cpp
                         )

target_compile_features(mylib PUBLIC cxx_std_17)
target_link_libraries(mylib PRIVATE Qt6::Widgets)

add_executable(helloworld
	src/main.cpp
	)

#target_link_libraries(helloworld PRIVATE Qt6::Core)
target_link_libraries(helloworld PRIVATE Qt6::Widgets mylib)

# set_target_properties(helloworld PROPERTIES
#     WIN32_EXECUTABLE ON
#     MACOSX_BUNDLE ON
#)
