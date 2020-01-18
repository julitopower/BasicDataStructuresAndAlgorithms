#include <iostream>
#include <string>

#include "slist.hpp"

namespace {
struct MyType {
  int a;
  int b;
};
} // unnamed namespace

int main(int argc, char** argv) {
  std::cout << "Generic singly linked list" << std::endl;

  // List of integers
  bda::List<std::int64_t> list{};
  
  for (auto i = 0U ; i < 1000 ; ++i) {
    list.push(i);
  }
  
  for (auto it = list.iter(); it.has_value(); it.next()) {
    std::cout << it.get() << ", ";
    it.get()++;
  }

  for (auto it = list.citer(); it.has_value(); it.next()) {
    std::cout << it.get() << ", ";
  }
  std::cout << std::endl;
  
  // List of strings
  bda::List<std::string> str_list{};
  str_list.push("Well this is unexpected");
  str_list.push("Another great string");

  for (auto it = str_list.citer(); it.has_value(); it.next()) {
    std::cout << it.get() << ", ";
  }
  std::cout << std::endl;

  // List of MyType
  bda::List<MyType> mytype_list;
  mytype_list.push({.a = 1, .b = 1});
}
