cmake_minimum_required(VERSION 3.7...3.25)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Blah VERSION 1.0
	DESCRIPTION "Blah project."
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(mylib STATIC src/pahlib.cpp include/pah/lib.hpp)
target_compile_features(mylib PUBLIC cxx_std_17)

add_executable(blah apps/joo.cpp)
target_link_libraries(blah PUBLIC mylib)
target_include_directories(blah PUBLIC
	"${PROJECT_BINARY_DIR}"
	)
configure_file(BlahConfig.h.in BlahConfig.h)
message(${PROJECT_BINARY_DIR})
