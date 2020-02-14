add_library(cesar cesar.cpp)

add_executable(test_cesar_cypher main.cpp)
target_link_libraries(test_cesar_cypher cesar)

add_test(test_cesar_cypher
  ${CMAKE_BINARY_DIR}/cesar_cypher/test_cesar_cypher)

install(TARGETS test_cesar_cypher
  RUNTIME DESTINATION bin)
