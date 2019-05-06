//
//  stack.hpp
//  A2_CPT113
//
//  Created by <author> on 04/05/2019.
//
//

#ifndef stack_hpp
#define stack_hpp

#include <iostream>
#include "nodeType.hpp"

template <class Type>
class stack {
protected:
int total_number_of_stack=0;
nodeType<Type> bottom_stack;
nodeType<Type> top_stack;

public:
    stack();
    ~stack();
    void initialize();
    void push(Type input_content);
    void pop();
    bool is_empty();
    Type top();


};


#endif /* stack_hpp */
