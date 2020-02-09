if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  add_definitions(-DBITS_64)
endif()


add_library(zigzag zigzag.cpp)
add_executable(test_zigzag main.cpp)
target_link_libraries(test_zigzag zigzag)

add_test(test_zigzag
  ${CMAKE_BINARY_DIR}/zigzag_encoding/test_zigzag)

install(TARGETS test_zigzag
  RUNTIME DESTINATION bin)
