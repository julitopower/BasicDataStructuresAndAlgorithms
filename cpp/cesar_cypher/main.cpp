#include <iostream>

#include "cesar.hpp"
#include <cassert>

int main(int, char**) {
  const auto range = 'z' - 'a' + 1;
  const std::string s = "abcdefghijklmnopqrstuvwxyz";  
  for (auto i = 0U ; i < range * 2 ; ++i) {
    cesar::CesarCypher cypher{i};
    assert(s == cypher.decypher(cypher.cypher(s)));

  }
}
