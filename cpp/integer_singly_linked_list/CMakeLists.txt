add_library(slist slist.cpp slist.hpp)

add_executable(app main.cpp)
target_link_libraries(app slist)
