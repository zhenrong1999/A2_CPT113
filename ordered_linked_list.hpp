//
//  ordered_linked_list.hpp
//  A2_CPT113
//
//  Created by <author> on 04/05/2019.
//
//

#ifndef ordered_linked_list_hpp
#define ordered_linked_list_hpp

#include "nodeType.hpp"
/**
 * The linked list that will always in order.
 */
template <class Type>
class ordered_linked_list {
private:
  nodeType<Type> *first_node;
  nodeType<Type> *last_node;
  int total_number_of_node=0;
public:
    ordered_linked_list();  //Initialize the ordered_linked_list
    ~ordered_linked_list(); //Destroy the ordered_linked_list
    bool is_empty();  //Check if the list is empty and return true if it is empty vise vesa.
    int length_of_list(); //Return the total number of node contain in the list.
    Type get_item(int index); //Return the node(content in the list) of given index(the position of the node).First node is 0.
    void insert_item(Type content); //Add in new content/item/node to the linked list in order
    void delete_index(int index); //Delete the content/item/node in the linked list with given index(position of the content/item/node).
    void delete_item(Type);  //Delete the content/item/node in the linked list with given content/item/node
    void copy_from(ordered_linked_list<Type>);  //copy the whole list to another linked list.
protected:

};


#endif /* ordered_linked_list_hpp */