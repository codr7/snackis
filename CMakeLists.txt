cmake_minimum_required(VERSION 3.5)

project(snackis)

set(CMAKE_CXX_COMPILER clang++)

add_compile_options(-std=c++20 -Wall -Werror -O2 -g)

file(GLOB_RECURSE src src/snackis/*.cpp)

add_executable(exe_target ${src} src/main.cpp)
set_target_properties(exe_target PROPERTIES OUTPUT_NAME snackis)
target_include_directories(exe_target PUBLIC src/)
target_link_libraries(exe_target sodium)

add_library(lib_target STATIC ${src})
set_target_properties(lib_target PROPERTIES OUTPUT_NAME snackis)
target_include_directories(lib_target PUBLIC src/)
target_link_libraries(lib_target sodium)

install(FILES build/libsnackis.a DESTINATION lib)
install(FILES build/snackis DESTINATION bin)
