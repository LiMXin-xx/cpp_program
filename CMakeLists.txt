cmake_minimum_required(VERSION 3.26)
project(cpp_program)
#C++17
set(CMAKE_CXX_STANDARD 17)
#添加头文件
include_directories(include)
#添加源文件
aux_source_directory(./src DIR_SRCS)
aux_source_directory(./src/stl_app DIR_STL_APP)
#可执行文件
add_executable(clion_cpp_demo ${DIR_SRCS} ${DIR_STL_APP})
