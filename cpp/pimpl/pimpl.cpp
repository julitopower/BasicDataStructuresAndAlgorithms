#include <iostream>
#include <cstring>
#include "pimpl.hpp"

namespace cesar {

/*
 * This class represents a Cesar Cypher for ascii characters between
 * 'a' and 'z'. None of the member functions verify that the
 * characters in the strings handled are within this range.
 */
class CesarCypherImpl {
 public:

  /*! \brief Initialize the shift that this CesarCypher applies
   *
   * \param shift How much to shift each character
   */  
  CesarCypherImpl(std::size_t shift) noexcept {
    shift_ = shift % range_;
  }

  /*! \brief Apply Caesar cypher to sentence and return result as a new string
   *
   * \param sentence The sentence to cypher
   * \return The cyphered sentence
   */
  std::string cypher(const std::string& sentence) {
    return cypher(sentence, shift_);
  }

  /*! \brief Apply reverse Caesar cypher to sentence and return result as a new
    string
    *
    * \param sentence The sentence to decypher
    * \return The decyphered sentence   
    */
  std::string decypher(const std::string& sentence) {
    return cypher(sentence, range_ - shift_);
  }
  
  /*! \brief Apply Caesar cypher to sentence and write result in buffer
   *
   * \param sentence The sentence to cypher
   * \param output The output buffer. It must have size > sentence.size()
   */
  void cypher(const std::string& sentence, char* output) {
    cypher(sentence, output, shift_);
  }  
  
  /*! \brief Apply reverse Caesar cypher to sentence and write result in buffer
   *
   * \param sentence The sentence to decypher
   * \param output The output buffer. It must have size > sentence.size()   
   */
  void decypher(const std::string& sentence, char* output) {
    return cypher(sentence, output, range_ - shift_);  
  }
 private:

  friend class CesarCypher;  
  
  /*
   * Apply Caesar cypher to sentence and return result as
   * a new string. The value of shift is unconstrained.
   */
  std::string cypher(const std::string& sentence, std::size_t shift) {
    if (shift == 0) {
      return sentence;
    }
  
    char output[sentence.size() + 1];
    output[sentence.size()] = '\0';
    cypher(sentence, output, shift);
    return output;  
  }
  
  /*
   * Apply Caesar cypher to sentence and write results in buffer.
   *
   * Buffer size is assumed to be at least sentence.size() + 1, and
   * to have been initialzed with '\0' in position sentence.size() + 1
   *
   * There are no restrictions to the value of shift.
   */
  void cypher(const std::string& sentence,
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
    
  std::size_t shift_;
  const std::size_t zero_ = 'a';
  const std::size_t range_ = 'z' - 'a' + 1;
};


CesarCypher::CesarCypher(std::size_t shift) noexcept {
  impl_ = std::make_unique<CesarCypherImpl>(shift);
}

/* For pimpl to work this destructor has to be defined after th
   implementatino of CesarCypherImpl is known. Otherwise
   std::unique_ptr can't generate the delete code */
CesarCypher::~CesarCypher() noexcept = default;

/* Since we defined a destructor we now have to define copy ctor and
   assignment operator */
CesarCypher::CesarCypher(const CesarCypher& other) {
  impl_ = std::make_unique<CesarCypherImpl>(other.impl_->shift_);
}

const CesarCypher& CesarCypher::operator=(const CesarCypher& other) {
  this->impl_->shift_ = other.impl_->shift_;
  return *this;
}

/*! \brief Apply Caesar cypher to sentence and return result as a new string
 *
 * \param sentence The sentence to cypher
 * \return The cyphered sentence
 */
std::string CesarCypher::cypher(const std::string& sentence) {
  return impl_->cypher(sentence);
}

/*! \brief Apply reverse Caesar cypher to sentence and return result as a new
  string
  *
  * \param sentence The sentence to decypher
  * \return The decyphered sentence   
  */  
std::string CesarCypher::decypher(const std::string& sentence) {
  return impl_->decypher(sentence);
}
  
/*! \brief Apply Caesar cypher to sentence and write result in buffer
 *
 * \param sentence The sentence to cypher
 * \param output The output buffer. It must have size > sentence.size()
 */  
void CesarCypher::cypher(const std::string& sentence, char* output) {
  impl_->cypher(sentence, output);
}
  
/*! \brief Apply reverse Caesar cypher to sentence and write result in buffer
 *
 * \param sentence The sentence to decypher
 * \param output The output buffer. It must have size > sentence.size()   
 */    
void CesarCypher::decypher(const std::string& sentence, char* output) {
  impl_->decypher(sentence, output);
}




} // namespace cesar
