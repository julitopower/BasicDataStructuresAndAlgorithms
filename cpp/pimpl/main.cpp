#include <iostream>

#include "pimpl.hpp"
#include <cassert>

int main(int, char**) {
  // First test different values for shift. Also test
  // copy constructor and assignment operator
  const auto range = 'z' - 'a' + 1;
  const std::string s = "abcdefghijklmnopqrstuvwxyz";
  for (auto shift = 0U ; shift < range * 2 ; ++shift) {
    cesar::CesarCypher cypher{shift};
    cesar::CesarCypher cypher_copy{cypher};
    cesar::CesarCypher cypher3{0};
    cypher3 = cypher;
    assert(s == cypher.decypher(cypher.cypher(s)));
    assert(s == cypher_copy.decypher(cypher_copy.cypher(s)));
    assert(s == cypher3.decypher(cypher3.cypher(s)));
  }
}
