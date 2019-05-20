//
//  binary_tree_sorting.hpp
//  A2_CPT113
//
//  Created by <author> on 17/05/2019.
//
//

#ifndef binary_tree_sorting_hpp
#define binary_tree_sorting_hpp

#include <iostream>
#include "car_info.hpp"
#include "car_model_type.hpp"
#include "nodeType.hpp"
template <class Type,class Type2>
struct comparingNodeType{
  Type to_be_compare;
  Type2 content;
  struct comparingNodeType *left, *right;
};


template <class Type,class Type2>
class binary_tree_sorting {
private:
  comparingNodeType<Type,Type2> *root=NULL;
public:
    binary_tree_sorting();
    binary_tree_sorting(Type,Type2);
    void insert(Type,Type2);
    comparingNodeType<Type,Type2> *create_new_tree_node(Type,Type2);
    comparingNodeType<Type,Type2> * insert_into_tree(comparingNodeType<Type,Type2>*,Type,Type2);
    void display_inorder(); // A utility function to do inorder traversal of BST
    void display_inorder(comparingNodeType<Type,Type2>*);
    void inorder(comparingNodeType<Type,Type2>*);
    comparingNodeType<Type,Type2>* get_root();
    ~binary_tree_sorting();
protected:

};


#endif /* binary_tree_sorting_hpp */
