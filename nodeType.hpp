//
//  nodeType.hpp
//  A2_CPT113
//
//  Created by <author> on 04/05/2019.
//
//

#ifndef nodeType_hpp
#define nodeType_hpp
#include <iostream>

template <class Type>
struct nodeType {
  Type content;
  nodeType<Type> *next_node;
};


#endif /* nodeType_hpp */
