add_executable(test_app_generic_slist main.cpp)
add_test(test_generic_singly_linked_list
  ${CMAKE_BINARY_DIR}/generic_singly_linked_list/test_app_generic_slist)

install(TARGETS test_app_generic_slist 
  RUNTIME DESTINATION bin)
