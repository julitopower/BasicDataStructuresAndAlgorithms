add_library(generic_slist slist.cpp slist.hpp)

add_executable(app_generic_slist main.cpp)
target_link_libraries(app_generic_slist generic_slist)
