//
//  queue.hpp
//  CPT211-Website
//
//  Created by <author> on 14/05/2019.
//
//

#ifndef queue_hpp
#define queue_hpp

#include <iostream>
#include "nodeType.hpp"

template <class Type>
class queue {
private:
  int total_number_of_queue=0;
  nodeType<Type> *front_node;
  nodeType<Type> *back_node;

public:
    queue();
    ~queue();
    void initialize();
    void addQueue(Type input_content);
    void delQueue();
    bool is_empty();
    Type front();
    int queue_lenght();
protected:

};


#endif /* queue_hpp */
