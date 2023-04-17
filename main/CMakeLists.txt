cmake_minimum_required(VERSION 3.20)
##--------------------- Version file ---------------------------------------##
##--------------------- Compile Options ------------------------------------##
##--------------------- Global Macros --------------------------------------##
##--------------------- Include directories --------------------------------##
##--------------------- Source files ---------------------------------------##
file(GLOB_RECURSE SRC_DIR CONFIGURE_DEPENDS src/*.cpp src/*.c include/*.h include/*.hpp)
message("SRC_DIR: ${SRC_DIR}")
##--------------------- Build target ---------------------------------------##
add_executable(main ${SRC_DIR})
target_include_directories(main PUBLIC include)
#local library
target_link_libraries(main PUBLIC bsp others lambda)
# external library
find_package(fmt REQUIRED)
target_link_libraries(main PUBLIC fmt::fmt)
find_package(GTest REQUIRED)
target_link_libraries(main PUBLIC GTest::gtest)
find_package(Threads)
target_link_libraries(main PUBLIC Threads::Threads)
##--------------------- Merge library --------------------------------------##
##--------------------- Build demo executable-------------------------------##
##--------------------- Build unit tests -----------------------------------##
##--------------------- Install and Package target -------------------------##
##----Package, These variables should set before including CPack module ----##