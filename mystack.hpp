//
//  stack.hpp
//  A2_CPT113
//
//  Created by <author> on 04/05/2019.
//
//

#ifndef mystack_hpp
#define mystack_hpp

#include <iostream>
#include "nodeType.hpp"
#include "book_info.hpp"

template <class Type>
class mystack {
protected:
int total_number_of_stack=0;
nodeType<Type> *bottom_stack;
nodeType<Type> *top_stack;

public:
    mystack();
    ~mystack();
    void initialize();
    void push(Type input_content);
    void pop();
    bool is_empty();
    Type top();
    int stack_height();

};


#endif /* mystack_hpp */
