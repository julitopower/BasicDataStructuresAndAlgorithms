cmake_minimum_required(VERSION 3.2)
project(basic_datastructures_and_algorithms)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

enable_testing()
add_subdirectory(integer_singly_linked_list)
add_subdirectory(generic_singly_linked_list)
add_subdirectory(zigzag_encoding)
add_subdirectory(cesar_cypher)
add_subdirectory(pimpl)
