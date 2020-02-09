#include "zigzag.hpp"

namespace bdsa {
#ifdef BITS_64
std::uint64_t zigzag(std::int64_t n) {
  return (n << 1) ^ (n >> 63);
}
#endif

std::uint32_t zigzag(std::int32_t n) {
  return (n << 1) ^ (n >> 31);
}
} // namespace bsda
