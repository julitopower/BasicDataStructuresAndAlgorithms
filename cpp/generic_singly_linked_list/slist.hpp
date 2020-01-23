#include <iostream>
#include <type_traits>
#include <stdint.h>
#include <tuple>

////////////////////////////////////////////////////////////////////////////////
//TODO: Mark noexcept functions as such
////////////////////////////////////////////////////////////////////////////////
namespace bda { // bda stands for Basic Data Structures
/*!
 * \brief A node part of a singly linked list. Payload is generic.
 *
 * \tparam T the type of the payload in the Node
 */
template <typename T>
struct Node {
 public:
  /*! \brief Payload type */
  using value_type = T;
  /*!
   * \brief Create a  node with the given value
   *
   * \param val The payload of this node
   */
  Node(T val) : val{val} {}

  /*!
   * \brief Destructor. Causes the destruction of other Nodes linked to it
   */
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
template <typename T, bool CONST>
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
   * This function provides a mutable reference, if T is not const
   *
   * If the iterator does not point to a valid IntNode it throws
   */
  template<typename R = T&>
  typename std::enable_if_t<!CONST, R>
  get() {
    if (curr_ == nullptr) {
      throw std::logic_error{"Invalid iterator. You may be trying to get values past the last one."};
    }
    return curr_->val;    
  }

  /*!
   * \brief Get the current const value of the iterator
   *
   * This function provides a const reference
   *
   * If the iterator does not point to a valid IntNode it throws
   */  
  template<typename R = const T&>
  typename std::enable_if_t<CONST, R>  
  get() {
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
  Iterator<T, true> citer() const {
    return {this->root()};    
  }
  Iterator<T, false> iter() const {
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
