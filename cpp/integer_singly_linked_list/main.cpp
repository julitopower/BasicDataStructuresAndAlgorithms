#include <iostream>

#include "slist.hpp"

int main(int, char**) {
  std::cout << "Testing integer singly linked list" << std::endl;
  bda::IntSList list{};
  
  for (auto i = 0U ; i < 1000 ; ++i) {
    list.push(i);
  }
  
  for (auto it = list.citer(); it.has_value(); it.next()) {
    std::cout << it.get() << ", ";
  }
  std::cout << std::endl;
}
