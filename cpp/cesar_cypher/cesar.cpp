#include <iostream>
#include <cstring>
#include "cesar.hpp"
namespace {

}

namespace cesar {
CesarCypher::CesarCypher(std::size_t shift) noexcept {
  shift_ = shift % range_;
}

/*
 * Apply Caesar cypher to sentence and write results in buffer.
 *
 * Buffer size is assumed to be at least sentence.size() + 1, and
 * to have been initialzed with '\0' in position sentence.size() + 1
 *
 * There are no restrictions to the value of shift.
 */
inline void CesarCypher::cypher(const std::string& sentence,
                                char* buffer,
                                std::size_t shift) {
  // No shift, just copy sentence on buffer
  if (shift == 0) {
    std::memcpy(buffer, sentence.c_str(), sentence.size());
    return;
  }
  
  auto idx = 0U;
  for (const char& ch : sentence) {
    const std::size_t candidate_value = ch + shift;
    if (candidate_value >= range_ + zero_) {
      buffer[idx++] = zero_ + (candidate_value - zero_) % range_;
    } else {
      buffer[idx++] = candidate_value;
    }
  }
}


/*
 * Apply Caesar cypher to sentence and return result as
 * a new string. The value of shift is unconstrained.
 */
inline std::string CesarCypher::cypher(const std::string& sentence,
                                       std::size_t shift) {
  if (shift == 0) {
    return sentence;
  }
  
  char output[sentence.size() + 1];
  output[sentence.size()] = '\0';
  cypher(sentence, output, shift);
  return output;  
}

std::string CesarCypher::cypher(const std::string& sentence) {
  return cypher(sentence, shift_);
}

std::string CesarCypher::decypher(const std::string& sentence) {
  return cypher(sentence, range_ - shift_);
}

void CesarCypher::cypher(const std::string& sentence, char* output) {
  cypher(sentence, output, shift_);
}

void CesarCypher::decypher(const std::string& sentence, char* output) {
  return cypher(sentence, output, range_ - shift_);  
}
} // namespace cesar
