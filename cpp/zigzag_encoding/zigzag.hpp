#ifndef BDSA_ZIGZAG_HPP
#define BDSA_ZIGZAG_HPP

#include <cstdint>

namespace bdsa {
#ifdef BITS_64
/*! \brief Zigzag encode a value
 *
 * \param n the number to encode
 */
std::uint64_t zigzag(std::int64_t n);
#endif

/*! \brief Zigzag encode a value
 *
 * \param n the number to encode
 */
std::uint32_t zigzag(std::int32_t n);
} // namespace bsda

#endif // BDSA_ZIGZAG_HPP
