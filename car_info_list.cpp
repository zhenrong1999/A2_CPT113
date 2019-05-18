//
//  car_info_list.cpp
//  A2_CPT113
//
//  Created by <author> on 17/05/2019.
//
//

#include "car_info_list.hpp"

car_info_list::car_info_list() : ordered_linked_list<car_info>() {}

car_info_list::~car_info_list() {}

void car_info_list::insert_car(string plat_no_in, string car_model_in,
                               string color_in, float rental_prize_in) {
  if (sorted_mode == "default" || sorted_mode == "no plate")
    ordered_linked_list::insert_item(
        car_info(plat_no_in, car_model_in, color_in, rental_prize_in));
  else
    insert_car(car_info(plat_no_in, car_model_in, color_in, rental_prize_in));
}

void car_info_list::insert_car(car_info content) {
  if (sorted_mode == "default" || sorted_mode == "no plate")
    ordered_linked_list::insert_item(content);
  else
  {
    nodeType<car_info>*temp=new nodeType<car_info>;
    temp->content=content;
    last_node->next_node=temp;
    last_node=temp;
    sort_car_info_list(sorted_mode);
  }
}

void car_info_list::edit_car(string plat_no_in, string car_model_in,
                             string color_in, float rental_prize_in) {
  get_item(car_info(plat_no_in))
      .change(plat_no_in, car_model_in, color_in, rental_prize_in);
}

void car_info_list::delete_car(string plate_no) {
  ordered_linked_list::delete_item(car_info(plate_no));
}
void car_info_list::delete_car(int index) {
  ordered_linked_list::delete_index(index);
}

comparingNodeType<string, nodeType<car_info> *> *car_info_list::sort_inoder(
    comparingNodeType<string, nodeType<car_info> *> *current) {
  if (current != NULL) {
    if (current->left != NULL) {
      comparingNodeType<string, nodeType<car_info> *> *temp =
          sort_inoder(current->left);
      temp->content->next_node = current->content;
      return temp;
    }
    if (current->right != NULL) {
      current->content->next_node = current->right->content;
      comparingNodeType<string, nodeType<car_info> *> *temp =
          sort_inoder(current->right);
      return temp;
    }
    return current;
  }
  return NULL;
}

void car_info_list::sort_car_info_list(string mode) {
  binary_tree_sorting<string, nodeType<car_info> *> sorting;
  nodeType<car_info> *current = first_node;
  if (mode == "default" || mode == "no plate") {
    sorted_mode = "default";
    while (current != NULL) {
      sorting.insert(current->content.getplat_no(), current);
      current = current->next_node;
    }
  } else if (mode == "car model") {
    sorted_mode = "car model";
    while (current != NULL) {
      sorting.insert(current->content.getcar_model() +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  }
  else if (mode == "rental prize") {
    sorted_mode = "rental prize";
    while (current != NULL) {
      sorting.insert( to_string(current->content.getrental_prize()) +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  }else if (mode == "color") {
    sorted_mode = "color";
    while (current != NULL) {
      sorting.insert( current->content.getcar_color() +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  }
  else if (mode == "rental day") {
    sorted_mode = "rental day";
    while (current != NULL) {
      sorting.insert( to_string(current->content.getrental_day()) +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  }
  else if (mode == "rental sales") {
    sorted_mode = "rental sales";
    while (current != NULL) {
      sorting.insert(to_string(current->content.getrental_sales()) +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  }
  else {
    std::cerr << "invalid sorting method" << '\n';
    return;
  }
  comparingNodeType<string, nodeType<car_info> *> *root = sorting.get_root(); //get the root for the binary tree.
  sort_inoder(root);
  comparingNodeType<string, nodeType<car_info> *> *temp = root;
  //Getting the first node of the new sorted linked list.
  while (temp->left != NULL) {
    temp = temp->left;
  }
  first_node = temp->content;
  temp = root;
  //Getting the last node of the new sorted linked list.
  while (temp->right != NULL) {
    temp = temp->right;
  }
  last_node = temp->content;
  last_node->next_node = NULL;
  root->content->content.display();
}

int car_info_list::length_of_list() {
  return ordered_linked_list::length_of_list();
}

void car_info_list::display() {
  cout << setw(3) << "No." << '|' << setw(20) << "car_model" << '|' << setw(10)
       << "plat_no" << '|' << setw(10) << "color" << '|' << setw(10)
       << "rental_prize" << endl;
  ordered_linked_list::display();
}
