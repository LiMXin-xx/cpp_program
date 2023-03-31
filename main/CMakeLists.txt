cmake_minimum_required(VERSION 3.20)
file(GLOB_RECURSE SRC_DIR CONFIGURE_DEPENDS src/*.cpp src/*.c include/*.h include/*.hpp)
message("SRC_DIR: ${SRC_DIR}")
# Build demo executable
add_executable(main ${SRC_DIR})
target_include_directories(main PUBLIC include)
#local library
target_link_libraries(main PUBLIC others)
target_link_libraries(main PUBLIC bsp)
# external library
find_package(fmt REQUIRED)
target_link_libraries(main PUBLIC fmt)
find_package(GTest REQUIRED)
target_link_libraries(main PUBLIC gtest)