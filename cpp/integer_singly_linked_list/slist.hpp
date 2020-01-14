#include <iostream>
#include <stdint.h>
#include <tuple>

////////////////////////////////////////////////////////////////////////////////
//TODO: Mark noexcept functinos as such
////////////////////////////////////////////////////////////////////////////////
namespace bda {
/*!
 * \brief A node part of a singly linked list. Payload is int64_t
 */
struct IntNode {
 public:
  /*! Payload type */
  using value_type = std::int64_t;
  /*!
   * \brief Create a  node with the given value
   */
  IntNode(std::int64_t val);
  ~IntNode();

 public:
  /*! The actual payload */
  std::int64_t val;
  /*! Pointer to the next node in the list */
  IntNode* next = nullptr;
};

/*!
 * \brief Iterator to traverse a singly linked list
 *
 * Does not allow modifying the list
 */
class ConstIntIterator {
 public:
  /*!
   * \brief Create Iterator that points to root IntNode
   *
   * This is a const interator
   */
  ConstIntIterator(IntNode* root);
  /*!
   * \brief Advance the iterator one position
   *
   * This method never throws.
   */
  void next();
  /*!
   * \brief Get the current value of the iterator
   *
   * If the iterator does not point to a valid IntNode it throws
   */
  const std::int64_t& get() const;
  /*!
   * \brief Does the iterator point to a valid IntNode?
   */
  bool has_value() const;
 private:
  IntNode* curr_ = nullptr;
};

/*!
 * \brief Iterator to traverse a singly linked list
 *
 * Does not allow modifying the list
 */
class IntIterator {
 public:
  /*!
   * \brief Create Iterator that points to root IntNode
   *
   * This is a const interator
   */
  IntIterator(IntNode* root);
  /*!
   * \brief Advance the iterator one position
   *
   * This method never throws.
   */
  void next();
  /*!
   * \brief Get the current value of the iterator
   *
   * If the iterator does not point to a valid IntNode it throws
   */
  std::int64_t& get();
  /*!
   * \brief Does the iterator point to a valid IntNode?
   */
  bool has_value() const;
 private:
  IntNode* curr_ = nullptr;
};

class IntSList {
 public:
  using value_type = std::int64_t;

  ~IntSList();
  ConstIntIterator citer() const;
  IntIterator iter() const;  
  IntNode* root() const;
  IntNode* last() const;
  void push(std::int64_t val);
 private:
  std::size_t size_ = 0;
  IntNode* root_ = nullptr;
  IntNode* last_ = nullptr;  
};
}
