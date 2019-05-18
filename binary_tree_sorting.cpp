//
//  binary_tree_sorting.cpp
//  A2_CPT113
//
//  Created by <author> on 17/05/2019.
//
//

#include "binary_tree_sorting.hpp"
template class binary_tree_sorting<std::string,nodeType<car_info>*>;
//template class binary_tree_sorting<std::string,car_info>;
//template class binary_tree_sorting<std::string,car_info*>;

template <class Type,class Type2>
binary_tree_sorting<Type,Type2>::binary_tree_sorting()  {
}

template <class Type,class Type2>
binary_tree_sorting<Type,Type2>::binary_tree_sorting(Type to_be_compare,Type2 content)  {
  root=insert_into_tree(root,to_be_compare,content);
}
template <class Type,class Type2>
binary_tree_sorting<Type,Type2>::~binary_tree_sorting() {}

template <class Type,class Type2>
comparingNodeType<Type,Type2> * binary_tree_sorting<Type,Type2>::create_new_tree_node(Type to_be_compare,Type2 content) {
  comparingNodeType<Type,Type2> *temp = new comparingNodeType<Type,Type2>;
  temp->to_be_compare = to_be_compare;
  temp->content=content;
  temp->left = temp->right = NULL;
  return temp;
}

template <class Type,class Type2>
void binary_tree_sorting<Type,Type2>::insert(Type to_be_compare,Type2 content)  {
  root = insert_into_tree(root,to_be_compare, content);
}

template <class Type,class Type2>
comparingNodeType<Type,Type2> * binary_tree_sorting<Type,Type2>::insert_into_tree(comparingNodeType<Type,Type2>* current,Type to_be_compare,Type2 content)  {
  /* If the tree is empty, return a new tree_node */
  if (current == NULL)
    return create_new_tree_node(to_be_compare,content);

  /* Otherwise, recur down the tree */
  if (to_be_compare < current->to_be_compare)
    current->left = insert_into_tree(current->left, to_be_compare,content);
  else if (to_be_compare > current->to_be_compare)
    current->right = insert_into_tree(current->right, to_be_compare,content);

  /* return the (unchanged) tree_node pointer */
  return current;
}

template <class Type,class Type2>
void binary_tree_sorting<Type,Type2>::display_inorder()  {
  display_inorder(root);
}

template <class Type,class Type2>
void binary_tree_sorting<Type,Type2>::display_inorder(comparingNodeType<Type,Type2>* current)  {
  if (current != NULL) {
    display_inorder(current->left);
    std::cout << current->content<< '\n';
    display_inorder(current->right);
  }
}

template <class Type,class Type2>
comparingNodeType<Type,Type2> *binary_tree_sorting<Type,Type2>::get_root()
{
  return root;
}
