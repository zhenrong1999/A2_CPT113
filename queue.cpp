//
//  queue.cpp
//  CPT211-Website
//
//  Created by <author> on 14/05/2019.
//
//

#include "queue.hpp"
template class queue<std::string>;
template <class Type> queue<Type>::queue() { front_node = back_node = NULL; }
template <class Type> queue<Type>::~queue() { initialize(); }
template <class Type> void queue<Type>::initialize() {
  while (!is_empty()) {
    delQueue();
  }
}
template <class Type> void queue<Type>::addQueue(Type input_content) {
  nodeType<Type> *new_back_node = new nodeType<Type>;
  new_back_node->content = input_content;
  new_back_node->next_node = NULL;
  if (front_node == NULL) {
    front_node = back_node = new_back_node;
  } else {
    back_node->next_node = new_back_node;
    back_node = new_back_node;
  }
  total_number_of_queue++;
}

template <class Type> void queue<Type>::delQueue() {
  if (is_empty()) {
    std::cerr << "The queue is empty. Nothing to be deleted." << '\n';
    return;
  } else {
    nodeType<Type> *to_be_deleted = new nodeType<Type>;
    to_be_deleted = front_node;
    front_node = front_node->next_node;
    delete to_be_deleted;
    total_number_of_queue--;
    if (front_node == NULL) {
      back_node = front_node;
    }
    return;
  }
}
template <class Type> bool queue<Type>::is_empty() {
  if (front_node == NULL)
    return 1;
  else
    return 0;
}
template <class Type> Type queue<Type>::front() { return front_node->content; }

template <class Type> int queue<Type>::length() {
  return total_number_of_queue;
}
