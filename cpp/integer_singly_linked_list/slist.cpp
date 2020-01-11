#include "slist.hpp"
#include "exception"

namespace bda {
IntNode::IntNode(std::int64_t val) : val{val} {}
IntNode::~IntNode() {
  if (next != nullptr) {
    delete next;
  }
}
void IntIterator::next() {
  if (curr_ != nullptr) {
    curr_ = curr_->next;
  }
}

std::int64_t IntIterator::get() const {
  if (curr_ == nullptr) {
    throw std::logic_error{"Invalid iterator. You may be trying to get values past the last one."};
  }
  return curr_->val;
}

bool IntIterator::has_value() const {
  return curr_ != nullptr;
}

IntIterator::IntIterator(IntNode* root) : curr_{root} {}

IntIterator IntSList::iter() const {
  return IntIterator(this->root());
}

IntNode* IntSList::root() const { return root_; }
IntNode* IntSList::last() const { return last_; }
void IntSList::push(std::int64_t val) {
  IntNode* node = new IntNode(val);
  if (root_ == nullptr) {
    root_ = node;
  }
  if (last_ != nullptr) {
    last_->next = node;
  }
  last_ = node;
}
IntSList::~IntSList() {
  if (root_ != nullptr) {
    delete root_;
  }
}

}
