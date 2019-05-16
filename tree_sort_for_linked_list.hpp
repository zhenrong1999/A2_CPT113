//
//  tree_sort_for_linked_list.hpp
//  A2_CPT113
//
//  Created by <author> on 16/05/2019.
//
//

#ifndef tree_sort_for_linked_list_hpp
#define tree_sort_for_linked_list_hpp

#include "car_info.hpp"
#include <iostream>

template <class Type> struct tree_node {
  Type content;
  tree_node<Type> *left, *right;
};

template <class Type> class tree_sort_for_linked_list {
public:
  tree_node<Type> *root = NULL;
  tree_sort_for_linked_list();
  ~tree_sort_for_linked_list();
  tree_node<Type> *newNode(Type);
  tree_node<Type> *insert(Type);
  tree_node<Type> *insert(tree_node<Type> *, Type);
  tree_node<Type> *&get_root();
  void inorder();
  void inorder(tree_node<Type> *);
  tree_node<car_info> *
  car_info_sort_tree_insert(tree_sort_for_linked_list<car_info> input,
                            tree_node<car_info> *node, car_info content,
                            string mode);
  friend void car_info_insert3(tree_sort_for_linked_list<car_info> input,
                               car_info content, string mode);

};
void car_info_insert3(tree_sort_for_linked_list<car_info> input,
                      car_info content, string mode) {
  input.car_info_sort_tree_insert(input, input.get_root(), content, mode);
}


#endif /* tree_sort_for_linked_list_hpp */
