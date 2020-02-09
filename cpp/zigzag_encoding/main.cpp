#include <iostream>
#include <vector>


#include "zigzag.hpp"

int main(int, char**) {
  std::vector<std::int64_t> v {1, -1, 0, 2, -2};
  for (const auto value : v) {
    const auto encoded = bdsa::zigzag(value);
    std::cout << value << ": " << encoded << std::endl;
  }
  
}
