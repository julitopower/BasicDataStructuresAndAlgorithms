#pragma once
#include <cstddef>
#include <string>

namespace cesar {

/*
 * This class represents a Cesar Cypher for ascii characters between
 * 'a' and 'z'. None of the member functions verify that the
 * characters in the strings handled are within this range.
 */
class CesarCypher {
 public:

  /*! \brief Initialize the shift that this CesarCypher applies
   *
   * \param shift How much to shift each character
   */
  CesarCypher(std::size_t shift) noexcept;

  /*! \brief Apply Caesar cypher to sentence and return result as a new string
   *
   * \param sentence The sentence to cypher
   * \return The cyphered sentence
   */
  std::string cypher(const std::string& sentence);

  /*! \brief Apply reverse Caesar cypher to sentence and return result as a new
             string
   *
   * \param sentence The sentence to decypher
   * \return The decyphered sentence   
   */  
  std::string decypher(const std::string& sentence);
  
  /*! \brief Apply Caesar cypher to sentence and write result in buffer
   *
   * \param sentence The sentence to cypher
   * \param output The output buffer. It must have size > sentence.size()
   */  
  void cypher(const std::string& sentence, char* output);
  
  /*! \brief Apply reverse Caesar cypher to sentence and write result in buffer
   *
   * \param sentence The sentence to decypher
   * \param output The output buffer. It must have size > sentence.size()   
   */    
  void decypher(const std::string& sentence, char* output);  
 private:

  std::string cypher(const std::string& sentence, std::size_t shift);
  void cypher(const std::string& sentence, char* buffer, std::size_t shift);
    
  std::size_t shift_;
  const std::size_t zero_ = 'a';
  const std::size_t range_ = 'z' - 'a' + 1;
};
} // namespace cesar
