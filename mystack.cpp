//
//  stack.cpp
//  A2_CPT113
//
//  Created by <author> on 04/05/2019.
//
//

#include "mystack.hpp"
template <class Type> mystack<Type>::mystack() {
  top_stack = bottom_stack = NULL;
}
template <class Type> mystack<Type>::~mystack() { initialize(); }
template <class Type> void mystack<Type>::initialize() {
while (!is_empty()) {
  pop();
}
}
template <class Type> bool mystack<Type>::is_empty() {
  if (top_stack == NULL)
    return 1;
  else
    return 0;
}
template <class Type> void mystack<Type>::push(Type input_content) {
  nodeType<Type> *new_top_stack = new nodeType<Type>;
  new_top_stack->content = input_content;
  new_top_stack->next_node = top_stack;
  top_stack = new_top_stack;
  total_number_of_stack++;
  if (bottom_stack == NULL) {
    bottom_stack = top_stack;
  }
}
template <class Type> void mystack<Type>::pop() {
  if (is_empty()) {
    std::cerr << "The stack is empty. Nothing to be pop out." << '\n';
  } else {
    nodeType<Type> *to_be_deleted = new nodeType<Type>;
    to_be_deleted = top_stack;
    top_stack = top_stack->next_node;
    delete to_be_deleted;
    total_number_of_stack--;
    if (top_stack == NULL) {
      bottom_stack = top_stack;
    }
  }
}
template <class Type> Type mystack<Type>::top() { return top_stack->content; }
template <class Type> int mystack<Type>::stack_height() {
  return total_number_of_stack;
}

template class mystack<int>;
template class mystack<book_info>;
