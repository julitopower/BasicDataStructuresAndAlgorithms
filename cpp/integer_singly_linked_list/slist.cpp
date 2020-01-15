q#include "slist.hpp"
#include "exception"

namespace bda {
IntNode::IntNode(std::int64_t val) : val{val} {}

IntNode::~IntNode() {
  if (next != nullptr) {
    delete next;
  }
}

void ConstIntIterator::next() {
  if (curr_ != nullptr) {
    curr_ = curr_->next;
  }
}

void IntIterator::next() {
  if (curr_ != nullptr) {
    curr_ = curr_->next;
  }
}

const std::int64_t& ConstIntIterator::get() const {
  if (curr_ == nullptr) {
    throw std::logic_error{"Invalid iterator. You may be trying to get values past the last one."};
  }
  return curr_->val;
}

std::int64_t& IntIterator::get() {
  if (curr_ == nullptr) {
    throw std::logic_error{"Invalid iterator. You may be trying to get values past the last one."};
  }
  return curr_->val;
}

bool ConstIntIterator::has_value() const {
  return curr_ != nullptr;
}

bool IntIterator::has_value() const {
  return curr_ != nullptr;
}

ConstIntIterator::ConstIntIterator(IntNode* root) : curr_{root} {}

IntIterator::IntIterator(IntNode* root) : curr_{root} {}

ConstIntIterator IntSList::citer() const {
  return ConstIntIterator(this->root());
}

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
} // namespace bda
