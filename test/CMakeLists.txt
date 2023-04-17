cmake_minimum_required(VERSION 3.20)
##--------------------- Version file ---------------------------------------##
##--------------------- Compile Options ------------------------------------##
##--------------------- Global Macros --------------------------------------##
##--------------------- Include directories --------------------------------##
##--------------------- Source files ---------------------------------------##
file(GLOB_RECURSE SRC_DIR CONFIGURE_DEPENDS src/*.cpp src/*.c include/*.h include/*.hpp)
message("SRC_DIR: ${SRC_DIR}")
##--------------------- Build target ---------------------------------------##
add_library(project_test STATIC ${SRC_DIR})
target_include_directories(project_test PUBLIC include)
#local library本地库
target_link_libraries(project_test PUBLIC bsp others)
# external library
find_package(fmt REQUIRED)
target_link_libraries(project_test PUBLIC fmt::fmt)
find_package(GTest REQUIRED)
target_link_libraries(project_test PUBLIC gtest)
target_link_libraries(project_test PUBLIC gmock)
##--------------------- Merge library --------------------------------------##
##--------------------- Build demo executable-------------------------------##
##--------------------- Build unit tests -----------------------------------##
option(CMAKE_ENABLE_TEST "Whether to enable unit tests" ON)
if(CMAKE_ENABLE_TEST)
    message(STATUS "Unit tests enabled")
    enable_testing()

    add_executable(test_add  src/test_add.cpp)
    add_executable(test_minus src/test_minus.cpp)
    add_executable(test_gtest_demo src/test_gtest_demo.cpp)
    target_link_libraries(test_add PUBLIC bsp gtest gtest_main)
    target_link_libraries(test_minus PUBLIC bsp gtest gtest_main)
    target_link_libraries(test_gtest_demo PUBLIC bsp gtest gtest_main)

    add_test(NAME test_add COMMAND test_add)
    add_test(NAME test_minus COMMAND test_minus)
    add_test(NAME test_gtest_demo COMMAND test_gtest_demo)
endif ()
##--------------------- Install and Package target -------------------------##
##----Package, These variables should set before including CPack module ----##