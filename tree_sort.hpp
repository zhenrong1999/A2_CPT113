//
//  tree_sort.hpp
//  A2_CPT113
//
//  Created by <author> on 16/05/2019.
//
//

#ifndef tree_sort_hpp
#define tree_sort_hpp

#include <iostream>

template <class Type>
struct tree_node {
  Type content;
  struct node *left, *right;
};

template <class Type>
class tree_sort {
private:
public:
    tree_sort();
    ~tree_sort();
    tree_node<Type>* add_node(Type item);
protected:

};


#endif /* tree_sort_hpp */
