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

##--------------------- 添加子目录模块 -----------------------------------##
add_subdirectory(bsp)
add_subdirectory(others)
add_subdirectory(main)
add_subdirectory(test)

##--------------------- Build unit tests -----------------------------------##
option(CMAKE_ENABLE_TEST "Whether to enable unit tests" ON)
if(CMAKE_ENABLE_TEST)
    message(STATUS "Unit tests enabled")
    enable_testing()
    add_subdirectory(gtest/googletest-release-1.10.0)
    include_directories(gtest/googletest-release-1.10.0/googletest/include)

    add_executable(test_add  test/src/test_add.cpp)
    add_executable(test_minus test/src/test_minus.cpp)
    add_executable(test_gtest_demo test/src/test_gtest_demo.cpp)
    target_link_libraries(test_add bsp gtest gtest_main)
    target_link_libraries(test_minus bsp gtest gtest_main)
    target_link_libraries(test_gtest_demo bsp gtest gtest_main)

    add_test(NAME test_add COMMAND test_add)
    add_test(NAME test_minus COMMAND test_minus)
    add_test(NAME test_gtest_demo COMMAND test_gtest_demo)
endif ()