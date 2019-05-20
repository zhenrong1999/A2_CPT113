//
//  car_model_type.cpp
//  A2_CPT113
//
//  Created by <author> on 19/05/2019.
//
//

#include "car_model_type.hpp"

car_model_type::car_model_type() {}

car_model_type::car_model_type(std::string car_model_in) {
  car_model = car_model_in;
}

car_model_type::car_model_type(std::string car_model_in,
                               float rental_prize_in) {
  car_model = car_model_in;
  rental_prize = rental_prize_in;
  rental_sales = rental_prize * rental_day;
}

car_model_type::car_model_type(std::string car_model_in, float rental_prize_in,
                               int rental_day_in) {
  car_model = car_model_in;
  rental_prize = rental_prize_in;
  rental_day = rental_day_in;
  rental_sales = rental_prize * rental_day;
  count++;
}

car_model_type::car_model_type(std::string car_model_in, float rental_prize_in,
                               int rental_day_in, float rental_sales_in) {
  car_model = car_model_in;
  rental_prize = rental_prize_in;
  rental_day = rental_day_in;
  rental_sales = rental_sales_in;
}

car_model_type::~car_model_type() {}

void car_model_type::set_display_item(display_item* display_item_in){
  display_measurement=display_item_in;
}


void car_model_type::change_rental_prize(float rental_prize_in) {
  rental_prize = rental_prize_in;
  rental_sales = rental_prize * rental_day;
}
void car_model_type::add_rental_day(int rental_day_in) {
  rental_day += rental_day_in;
  rental_sales = rental_prize * rental_day;
}
void car_model_type::change_count(int count_in) { count += count_in; }

std::string car_model_type::getcar_model() { return car_model; }

float car_model_type::getrental_prize() { return rental_prize; }

int car_model_type::getrental_day() { return rental_day; }

float car_model_type::getrental_sales() { return rental_sales; }

int car_model_type::getnumber_of_car() { return count; }

bool car_model_type::operator==(car_model_type &comparing) {
  //return car_model == comparing.car_model;
  if(car_model.compare(comparing.car_model)==0)
    return true;
  return false;
}

bool car_model_type::operator!=(car_model_type &comparing) {
  //return car_model != comparing.car_model;
  if(car_model.compare(comparing.car_model)!=0)
    return true;
  return false;
}

bool car_model_type::operator>=(car_model_type &comparing) {
  //return car_model >= comparing.car_model;
  if(car_model.compare(comparing.car_model)>=0)
    return true;
  return false;
}

bool car_model_type::operator<=(car_model_type &comparing) {
  //return car_model <= comparing.car_model;
  if(car_model.compare(comparing.car_model)<=0)
    return true;
  return false;
}

bool car_model_type::operator>(car_model_type &comparing) {
  //return car_model > comparing.car_model;
  if(car_model.compare(comparing.car_model)>0)
    return true;
  return false;
}

bool car_model_type::operator<(car_model_type &comparing) {
  //return car_model < comparing.car_model;
  if(car_model.compare(comparing.car_model)<0)
    return true;
  return false;
}
car_model_type car_model_type::operator+(car_model_type &comparing) {
  car_model_type total("Total", rental_prize + comparing.rental_prize,
                       rental_day + comparing.rental_day,
                       rental_sales + comparing.rental_sales);
  total.change_count(comparing.count);
  return total;
}

std::ostream &operator<<(std::ostream &out, const car_model_type &output) {
  out << std::left << '|' << std::setw(20) << output.car_model << '|' << std::setw(12) << output.rental_prize << '|' << std::setw(12)
      << output.rental_day << '|' << std::setw(12) << output.rental_sales
      << '|';
  return out;
}
