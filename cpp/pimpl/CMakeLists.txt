add_library(pimpl pimpl.cpp)

add_executable(test_pimpl main.cpp)
target_link_libraries(test_pimpl pimpl)

add_test(test_pimpl
  ${CMAKE_BINARY_DIR}/pimpl/test_pimpl)

install(TARGETS test_pimpl
  RUNTIME DESTINATION bin)
