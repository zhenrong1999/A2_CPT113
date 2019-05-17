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
  if (sorted_mode == "default")
    ordered_linked_list::insert_item(
        car_info(plat_no_in, car_model_in, color_in, rental_prize_in));
}

void car_info_list::insert_car(car_info content) {
  if (sorted_mode == "default")
    ordered_linked_list::insert_item(content);
}

void car_info_list::edit_car(string plat_no_in, string car_model_in,
                               string color_in, float rental_prize_in){
  get_item(car_info(plat_no_in)).change(plat_no_in, car_model_in, color_in, rental_prize_in);
}

void car_info_list::delete_car(string plate_no) {
  ordered_linked_list::delete_item(car_info(plate_no));
}
void car_info_list::delete_car(int index) {
  ordered_linked_list::delete_index(index);
}
void car_info_list::display() {}
