add_library(slist slist.cpp slist.hpp)

add_executable(test_app_singly_slist main.cpp)
target_link_libraries(test_app_singly_slist slist)

add_test(integer_singly_linked_list
  ${CMAKE_BINARY_DIR}/integer_singly_linked_list/test_app_singly_slist)

install(TARGETS test_app_singly_slist
  RUNTIME DESTINATION bin)
