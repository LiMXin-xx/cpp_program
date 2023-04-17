cmake_minimum_required(VERSION 3.20)
project(cpp_program VERSION 1.1.2 LANGUAGES C CXX DESCRIPTION "A cpp_program C&C++ project")

##--------------------- Version file ---------------------------------------##
configure_file(main/include/main/cmake_version.h.in "${PROJECT_SOURCE_DIR}/main/include/main/cmake_version.h")
# Specified the language standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

##--------------------- Compile Options ------------------------------------##
# Configure compile options
#add_compile_options(-Wall -Wextra -pedantic -Werror)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++17")

##--------------------- Set build type ------------------------------------##
# set(CMAKE_BUILD_TYPE Debug)  # Use `cmake -DCMAKE_BUILD_TYPE=Debug` more better
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Compile options for Debug variant
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

# Compile options for Release variant
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

message(STATUS "Compile options for c: ${CMAKE_C_FLAGS}")
message(STATUS "Compile options for c++: ${CMAKE_CXX_FLAGS}")

##--------------------- Global Macros --------------------------------------##
##--------------------- Include directories --------------------------------##
##--------------------- Source files ---------------------------------------##
add_subdirectory(bsp)
add_subdirectory(others)
add_subdirectory(main)
add_subdirectory(test)
add_subdirectory(lambda)
##--------------------- Build target ---------------------------------------##
##--------------------- Merge library --------------------------------------##
##--------------------- Build demo executable-------------------------------##
##--------------------- Build unit tests -----------------------------------##
##--------------------- Install and Package target -------------------------##
##----Package, These variables should set before including CPack module ----##