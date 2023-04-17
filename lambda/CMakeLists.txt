cmake_minimum_required(VERSION 3.20)
##--------------------- Version file ---------------------------------------##
##--------------------- Compile Options ------------------------------------##
##--------------------- Global Macros --------------------------------------##
##--------------------- Include directories --------------------------------##
##--------------------- Source files ---------------------------------------##
file(GLOB_RECURSE SRC_DIR CONFIGURE_DEPENDS src/*.cpp src/*.c include/*.h include/*.hpp)
message("SRC_DIR: ${SRC_DIR}")
##--------------------- Build target ---------------------------------------##
#01 static library
add_library(lambda_static STATIC ${SRC_DIR})
target_include_directories(lambda_static PUBLIC include)
#rename static library
SET_TARGET_PROPERTIES(lambda_static PROPERTIES OUTPUT_NAME "lambda")
SET_TARGET_PROPERTIES(lambda_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

#02 shared library
add_library(lambda SHARED ${SRC_DIR})
target_include_directories(lambda PUBLIC include)
#rename shared library
#SET_TARGET_PROPERTIES(lambda PROPERTIES OUTPUT_NAME "lambda")
#SET_TARGET_PROPERTIES(lambda PROPERTIES CLEAN_DIRECT_OUTPUT 1)

##--------------------- Merge library --------------------------------------##
##--------------------- Build demo executable-------------------------------##
##--------------------- Build unit tests -----------------------------------##
##--------------------- Install and Package target -------------------------##
##----Package, These variables should set before including CPack module ----##


