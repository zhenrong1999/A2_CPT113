//
//  ordered_linked_list.cpp
//  A2_CPT113
//
//  Created by <author> on 04/05/2019.
//
//

#include "ordered_linked_list.hpp"
template class ordered_linked_list<int>;
template class ordered_linked_list<car_info>;
template class ordered_linked_list<car_model_type>;
template class ordered_linked_list<string>;

template <class Type> ordered_linked_list<Type>::ordered_linked_list() {
  first_node = NULL;
  last_node = NULL;
}

template <class Type> ordered_linked_list<Type>::~ordered_linked_list() {
  if (!is_empty()) {
    nodeType<Type> *to_delete = first_node;
    while (!is_empty()) {
      first_node = first_node->next_node;
      delete to_delete;
      to_delete = first_node;
    }
  }
}
template <class Type>
void ordered_linked_list<Type>::set_display_item(display_item* display_item_in){
  display_measurement=display_item_in;
}

template <class Type> bool ordered_linked_list<Type>::is_empty() {
  if (first_node == NULL)
    return true;
  return false;
}

template <class Type> int ordered_linked_list<Type>::length_of_list() {
  return total_number_of_node;
}

template <class Type>
nodeType<Type> *ordered_linked_list<Type>::get_item_by_index(int index) {
  nodeType<Type> *current;
  if (index > total_number_of_node && index < -1) {
    std::cout << "The index is not in the list which may cause " << '\n';
  } else {
    int i = index % 2;
    switch (i) {
    case 0:
      current = first_node;
      break;
    case 1:
      current = first_node->next_node;
      break;
    }
    for (i = i; i < index; i = i + 2)
      current = current->next_node->next_node;
  }
  return current;
}

template <class Type>
nodeType<Type> *ordered_linked_list<Type>::get_item(Type to_search) {
  nodeType<Type> *start_node = first_node;
  nodeType<Type> *slow_ptr = first_node;
  nodeType<Type> *fast_ptr = first_node;
  nodeType<Type> *end_node = NULL;
  do {
    while (fast_ptr != end_node && fast_ptr->next_node != end_node) {
      fast_ptr = fast_ptr->next_node->next_node;
      slow_ptr = slow_ptr->next_node;
    }
    if (slow_ptr == fast_ptr && slow_ptr->content != to_search) {
      return NULL;
      break;
    } else if (slow_ptr->content < to_search) {
      end_node = fast_ptr->next_node;
      slow_ptr = start_node = fast_ptr = (slow_ptr->next_node);
    } else if (slow_ptr->content > to_search) {
      end_node = slow_ptr;
      fast_ptr = slow_ptr = start_node;
    }
  } while (slow_ptr->content != to_search);
  return slow_ptr;
}

template <class Type>
void ordered_linked_list<Type>::insert_item(Type input_content) {
  if (is_empty()) {
    first_node = last_node = new nodeType<Type>;
    first_node->content = input_content;
    first_node->next_node = NULL;
  }
   else if (input_content < first_node->content) {
    nodeType<Type> *temp = new nodeType<Type>;
    temp->content = input_content;
    temp->next_node = first_node;
    first_node = temp;
    std::cout << "Change in first node." << '\n';
  } else if (input_content > last_node->content) {
    nodeType<Type> *temp = new nodeType<Type>;
    temp->content = input_content;
    temp->next_node = NULL;
    last_node->next_node = temp;
    last_node = temp;
    std::cout << "Change in last node." << '\n';
  } else {
    nodeType<Type> *current = first_node;
    if (current->content == input_content) {
      std::cerr << "The same input content has been found!" << '\n';
      return;
    }
    while (current->next_node->content < input_content) {
      if (current->content == input_content) {
        std::cerr << "The same input content has been found!" << '\n';
        return;
      } else {
        current = current->next_node;
        if(current->next_node==NULL||current==last_node)
        {break;}
      }
    }

    if(current->next_node->content==input_content){
      std::cerr << "The same input content has been found!" << '\n';
      return;
    }


    nodeType<Type> *temp = new nodeType<Type>;
    temp->content = input_content;
    temp->next_node = current->next_node;
    current->next_node = temp;
    std::cout << "Change in between nodes." << '\n';
  }
    total_number_of_node++;
}

template <class Type> void ordered_linked_list<Type>::delete_index(int index) {
  if (index < total_number_of_node && index > -1) {
    if (index == 0) {
      nodeType<Type> *temp = first_node;
      first_node = first_node->next_node;
      delete temp;
    } else {
      nodeType<Type> *current, *previous_of_current;
      previous_of_current = first_node;
      current = first_node->next_node;
      for (int i = 1; i < index; i++) {
        previous_of_current = current;
        current = current->next_node;
      }
      if (current == last_node)
        last_node = previous_of_current;
      previous_of_current->next_node = current->next_node;
      delete current;
    }
    total_number_of_node--;
  } else {
    std::cout << "The index is not in the list which may cause " << '\n';
  }
}
template <class Type>
void ordered_linked_list<Type>::delete_item(Type content_input) {
  if (content_input >= first_node->content &&
      content_input <= last_node->content) {
    nodeType<Type> *current, *previous_of_current;
    current = first_node;
    bool equality_of_the_content = (current->content == content_input);
    do {
      if (equality_of_the_content) {
        if (current == first_node) {
          previous_of_current = first_node;
          first_node = first_node->next_node;
          delete previous_of_current;
        } else {
          if (current == last_node)
            last_node = previous_of_current;
          previous_of_current->next_node = current->next_node;
          delete current;
        }
        total_number_of_node--;
        return;
      }
      previous_of_current = current;
      current = current->next_node;
      equality_of_the_content = (current->content == content_input);
    } while (current->next_node != NULL || equality_of_the_content);
  }
  std::cout << "The content is not found in the list" << '\n';
}
template <class Type>
void ordered_linked_list<Type>::copy_from(ordered_linked_list<Type> original) {
  if (!is_empty()) {
    nodeType<Type> *to_delete = first_node;
    while (!is_empty()) {
      first_node = first_node->next_node;
      delete to_delete;
      to_delete = first_node;
    }
  }
  nodeType<Type> *current, *previous_of_current;
  first_node = current = new nodeType<Type>;
  current->content = original.get_item_by_index(0)->content;
  previous_of_current = current;
  current = new nodeType<Type>;
  for (int i = 1; i < original.length_of_list(); i++) {
    current->content = original.get_item_by_index(i)->content;
    previous_of_current->next_node = current;
    previous_of_current = current;
    current = new nodeType<Type>;
  }
  last_node = previous_of_current;
  previous_of_current->next_node = NULL;

  delete current;
  total_number_of_node = original.length_of_list();
}

template <class Type>
int ordered_linked_list<Type>::binary_search(Type to_search) {
  std::cout << "Seacrhing for " << "......" << '\n';
  if(is_empty()||to_search<first_node->content||to_search>last_node->content)
    return -1;
  if(to_search==first_node->content)
    return 0;
  if(to_search==last_node->content)
    return total_number_of_node-1;
  nodeType<Type> *start_node = first_node;
  nodeType<Type> *slow_ptr = first_node;
  nodeType<Type> *fast_ptr = first_node;
  nodeType<Type> *end_node = NULL;
  int count = 0;
  int count_previous = 0;
  do {
    while (fast_ptr != end_node && fast_ptr->next_node != end_node) {
      fast_ptr = fast_ptr->next_node->next_node;
      slow_ptr = slow_ptr->next_node;
      count++;
    }
    if (slow_ptr == fast_ptr && slow_ptr->content != to_search)
      return -1;
    else if (slow_ptr->content < to_search) {
      end_node = fast_ptr->next_node;
      slow_ptr = start_node = fast_ptr = (slow_ptr->next_node);
      count_previous = ++count;
    } else if (slow_ptr->content > to_search) {
      end_node = slow_ptr;
      fast_ptr = slow_ptr = start_node;
      count = count_previous;
    }
  } while (slow_ptr->content != to_search);
if (slow_ptr->content == to_search)
  return count;
else
  return -1;
}
template <class Type> void ordered_linked_list<Type>::display() {
  int count = 1;
  nodeType<Type> *current_node = first_node;
  while (current_node != NULL) {
    cout << setw(display_measurement->max_length_of_list_no) << left << count << current_node->content << endl;
    current_node = current_node->next_node;
    count++;
  }
}
template <class Type>
void ordered_linked_list<Type>::assign_first_node(nodeType<Type>*input_node){
first_node=input_node;
}
template <class Type>
void ordered_linked_list<Type>::assign_last_node(nodeType<Type>*input_node){
last_node=input_node;
}
