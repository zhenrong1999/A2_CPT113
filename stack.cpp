//
//  stack.cpp
//  A2_CPT113
//
//  Created by <author> on 04/05/2019.
//
//

#include "stack.hpp"
template <class Type> stack<Type>::stack() { initialize(); }
template <class Type> stack<Type>::~stack() {}
template <class Type> void stack<Type>::initialize() {
  if (!is_empty()) {
    nodeType<Type> *todelete;
    while (!is_empty()) {
      todelete = top_stack;
      top_stack = top_stack->next_node;
      delete todelete;
    }
    top_stack = bottom_stack = NULL;
  }
}
template <class Type> bool stack<Type>::is_empty() {
  if (top_stack == NULL)
    return 1;
  else
    return 0;
}
template <class Type> void stack<Type>::push(Type input_content) {
  nodeType<Type> *new_top_stack = new nodeType<Type>;
  new_top_stack->content = input_content;
  new_top_stack->next_node = top_stack;
  top_stack = new_top_stack;
  total_number_of_stack++;
  if (bottom_stack == NULL) {
    bottom_stack = top_stack;
  }
}
template <class Type> void stack<Type>::pop() {
if(is_empty())
{
  std::cerr << "The stack is empty. Nothing to " << '\n';
  return;
}
  nodeType<Type> *to_be_deleted = new nodeType<Type>;
  to_be_deleted=top_stack;
  top_stack=top_stack->next_node;
  delete to_be_deleted;
  total_number_of_stack--;
  if(top_stack==NULL)
  {
    bottom_stack=top_stack;
  }
}
template <class Type> Type stack<Type>::top() {}
