#include <iostream>
#include <stdint.h>
#include <tuple>

////////////////////////////////////////////////////////////////////////////////
//TODO: Mark noexcept functions as such
////////////////////////////////////////////////////////////////////////////////
namespace bda { // bda stands for Basic Data Structures
/*!
 * \brief A node part of a singly linked list. Payload is generic
 */
template <typename T>
struct Node {
 public:
  /*! Payload type */
  using value_type = T;
  /*!
   * \brief Create a  node with the given value
   *
   * \param val The payload of this node
   */
  Node(T val) : val{val} {}
  
  ~Node() {
    if (next != nullptr) {
      delete next;
    }
  }

 public:
  /*! \brief The actual payload */
  T val;
  /*! \brief Pointer to the next node in the list */
  Node* next = nullptr;
};

/*!
 * \brief Iterator to traverse a singly linked list
 *
 * Does not allow modifying the list
 */
//TODO: We only need one iterator and a bit of SFINAE magic
template<typename T>
class ConstIterator {
 public:
  /*!
   * \brief Create Iterator that points to root Node
   *
   * This is a const interator
   */
  //TODO: can this be const Node&
  ConstIterator(Node<T>* root) : curr_{root} {}
  
  /*!
   * \brief Advance the iterator one position
   *
   * This method never throws.
   */
  void next() {
    if (curr_ != nullptr) {
      curr_ = curr_->next;
    }    
  }
  
  /*!
   * \brief Get the current value of the iterator
   *
   * If the iterator does not point to a valid Node it throws
   */
  const T& get() const {
    if (curr_ == nullptr) {
      throw std::logic_error{"Invalid iterator. You may be trying to get values past the last one."};
    }
    return curr_->val;    
  }
  /*!
   * \brief Does the iterator point to a valid Node?
   */
  bool has_value() const {
    return curr_ != nullptr;    
  }
 private:
  Node<T>* curr_ = nullptr;
};

/*!
 * \brief Iterator to traverse a singly linked list
 *
 * Does not allow modifying the list
 */
template <typename T>
class Iterator {
 public:
  /*!
   * \brief Create Iterator that points to root IntNode
   *
   * This is a const interator
   */
  //TODO: can this be const Node&
  Iterator(Node<T>* root) : curr_{root} {}
                            
  /*!
   * \brief Advance the iterator one position
   *
   * This method never throws.
   */
  void next() {
    if (curr_ != nullptr) {
      curr_ = curr_->next;
    }                              
  }
  /*!
   * \brief Get the current value of the iterator
   *
   * If the iterator does not point to a valid IntNode it throws
   */
  T& get() {
    if (curr_ == nullptr) {
      throw std::logic_error{"Invalid iterator. You may be trying to get values past the last one."};
    }
    return curr_->val;    
  }
  /*!
   * \brief Does the iterator point to a valid IntNode?
   */
  bool has_value() const {
    return curr_ != nullptr;    
  }
 private:
  /*! \brief non-owning pointer to current Node */
  Node<T>* curr_ = nullptr;
};

template <typename T>
class List {
 public:
  using value_type = T;

  ~List() {
    if (root_ != nullptr) {
      delete root_;
    }
  }
  ConstIterator<T> citer() const {
    return {this->root()};    
  }
  Iterator<T> iter() const {
    return {this->root()};    
  }
  
  Node<T>* root() const { return root_; }
  Node<T>* last() const { return last_; }
  void push(T val) {
    auto node = new Node<T>{val};
    if (root_ == nullptr) {
      root_ = node;
    }
    if (last_ != nullptr) {
      last_->next = node;
    }
    last_ = node;    
  }
 private:
  std::size_t size_ = 0;
  Node<T>* root_ = nullptr;
  Node<T>* last_ = nullptr;
};
} // namespace bda
