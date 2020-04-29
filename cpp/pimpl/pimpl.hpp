#pragma once
#include <string>
#include <memory>

namespace cesar {
// Forward declare the implementation class. This is all the consumers will see
// from the actual implementation
class CesarCypherImpl;

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

  /*! \brief For std::unique_ptr to work with incomplete types this
             destructor needs to be declared after the CesarCypherImpl
             class is defined. See Modern Effective C++, unique_ptr.
  */
  ~CesarCypher() noexcept;

  /*! \brief Copy constructor */
  CesarCypher(const CesarCypher& other);

  /*! \brief Assignment operator */
  const CesarCypher& operator=(const CesarCypher& other);

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
  std::unique_ptr<CesarCypherImpl> impl_;
};
} // namespace cesar
