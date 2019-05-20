//
//  car_info_list.hpp
//  A2_CPT113
//
//  Created by <author> on 17/05/2019.
//
//

#ifndef car_info_list_hpp
#define car_info_list_hpp

#include "binary_tree_sorting.hpp"
#include "car_info.hpp"
#include "car_model_type.hpp"
#include "ordered_linked_list.hpp"
#include <iostream>
#include <cmath>

class car_info_list : protected ordered_linked_list<car_info> {
private:
  
  ordered_linked_list<car_model_type> car_model_list;
  string sorted_mode = "default"; // the default is sorted by plate no. Other
                                  // option is sort by car model
  string car_model_list_sorted_mode = "default";

public:
  car_info_list();
  ~car_info_list();
  void insert_car(string plat_no_in, string car_model_in, string color_in,
                  float rental_prize_in);
  void insert_car(car_info);
  float during_insert_car_model(string, float, int);
  void edit_car(string, string, string, float, int);
  void edit_rental_prize(string, float, int);
  void car_model_changes_rental_prize(string car_model_in,
                                      float rental_prize_in, int rental_day_in);
  void delete_car(string plate_no);
  void delete_car(int);
  comparingNodeType<string, nodeType<car_info> *> *
  sort_inoder(comparingNodeType<string, nodeType<car_info> *> *current);
  comparingNodeType<string, nodeType<car_model_type> *> *
  sort_inoder(comparingNodeType<string, nodeType<car_model_type> *> *current);
  void sort_car_info_list(string);
  void sort_car_model_list(string);
  int length_of_list();
  int search(string);
  int search_car_model_list(string);
  nodeType<car_info> *get_car_by_index(int index);
  nodeType<car_info> *get_car(car_info);
  void display(); // display all the car info in a table.
  void display_selected(string mode, string, string);
  void display_car_model();
  car_model_type sum_of_all();
  car_info sum_of_selection();
};

#endif /* car_info_list_hpp */
