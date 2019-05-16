//
//  tree_sort_for_linked_list.cpp
//  A2_CPT113
//
//  Created by <author> on 16/05/2019.
//
//

#include "tree_sort_for_linked_list.hpp"
template class tree_sort_for_linked_list<int>;
template class tree_sort_for_linked_list <car_info>;
template <class Type>
tree_sort_for_linked_list<Type>::tree_sort_for_linked_list() {}
template <class Type>
tree_sort_for_linked_list<Type>::~tree_sort_for_linked_list() {}
template <class Type>
tree_node<Type> *tree_sort_for_linked_list<Type>::newNode(Type content) {
  tree_node<Type> *temp = new tree_node<Type>;
  temp->content = content;
  temp->left = temp->right = NULL;
  return temp;
}
template <class Type>
tree_node<Type>*& tree_sort_for_linked_list<Type>::get_root(){
    return root;
}

template <class Type>
tree_node<Type> *tree_sort_for_linked_list<Type>::insert(Type content) {
  if (root == NULL) {
    root = insert(root, content);
    return root;
  }
  return insert(root, content);
}

template <class Type>
tree_node<Type> *tree_sort_for_linked_list<Type>::insert(tree_node<Type> *node,
                                                         Type content) {
  /* If the tree is empty, return a new node */
  if (node == NULL) {
    return newNode(content);
  }

  /* Otherwise, recur down the tree */
  if (content < node->content)
    node->left = insert(node->left, content);
  else if (content > node->content)
    node->right = insert(node->right, content);

  /* return the (unchanged) node pointer */
  return node;
}

template <class Type> void tree_sort_for_linked_list<Type>::inorder() {
  //  std::cout << root->content << '\n';
  inorder(root);
}

template <class Type>
void tree_sort_for_linked_list<Type>::inorder(tree_node<Type> *node) {
  if (node != NULL) {
    inorder(node->left);
    std::cout << node->content << '\n';
    inorder(node->right);
  }
}

/*
template <class Type>
tree_node<car_info>* tree_sort_for_linked_list<Type>::car_info_sort_tree_insert(tree_sort_for_linked_list<car_info> input,
                            tree_node<car_info> *node, car_info content,
                            string mode) {
  if (mode == "plate") {
    if (node == NULL) {
      input.get_root() = input.newNode(content);
      return input.get_root();
    }

    // Otherwise, recur down the tree
    if (content < node->content)
      node->left = car_info_sort_tree_insert(input, node->left, content, mode);
    else if (content > node->content)
      node->right = car_info_sort_tree_insert(input, node->right, content, mode);

  }

  else if (mode == "car_model") {
    if (node == NULL) {
      input.get_root() = input.newNode(content);
      return input.get_root();
    }

    // Otherwise, recur down the tree
    if (content.smaller_car_modal(node->content))
      node->left = car_info_sort_tree_insert(input, node->left, content, mode);
    else if (content.larger_car_modal(node->content))
      node->right = car_info_sort_tree_insert(input, node->right, content, mode);
  }
  // return the (unchanged) node pointer
  return node;
}
*/


template <class car_info>
tree_node<car_info>* tree_sort_for_linked_list<car_info>::car_info_sort_tree_insert(tree_sort_for_linked_list<car_info> input,
                            tree_node<car_info> *node, car_info content,
                            string mode) {
  if (mode == "plate") {
    if (node == NULL) {
      input.get_root() = input.newNode(content);
      return input.get_root();
    }

    // Otherwise, recur down the tree
    if (content < node->content)
      node->left = car_info_sort_tree_insert(input, node->left, content, mode);
    else if (content > node->content)
      node->right = car_info_sort_tree_insert(input, node->right, content, mode);

  }

  else if (mode == "car_model") {
    if (node == NULL) {
      input.get_root() = input.newNode(content);
      return input.get_root();
    }

    // Otherwise, recur down the tree
    if (content.smaller_car_modal(node->content))
      node->left = car_info_sort_tree_insert(input, node->left, content, mode);
    else if (content.larger_car_modal(node->content))
      node->right = car_info_sort_tree_insert(input, node->right, content, mode);
  }
  // return the (unchanged) node pointer
  return node;
}
