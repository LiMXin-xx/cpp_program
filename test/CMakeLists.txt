cmake_minimum_required(VERSION 3.20)
file(GLOB_RECURSE SRC_DIR CONFIGURE_DEPENDS src/*.cpp src/*.c include/*.h include/*.hpp)
message("SRC_DIR: ${SRC_DIR}")
add_library(project_test STATIC ${SRC_DIR})
target_include_directories(project_test PUBLIC include)
#local library本地库
target_link_libraries(project_test PUBLIC bsp)
# external library
find_package(fmt REQUIRED)
target_link_libraries(project_test PUBLIC fmt)
find_package(GTest REQUIRED)
target_link_libraries(project_test PUBLIC gtest)
