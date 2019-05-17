//
//  car_info.cpp
//  A2_CPT113
//
//  Created by <author> on 03/05/2019.
//
//
#include "car_info.hpp"
car_info::car_info() {}
car_info::car_info(string plat_no_in) {
  plat_no=plat_no_in;
}
car_info::car_info(string plat_no_in, string car_model_in, string color_in,
                   float rental_prize_in) {
  change(plat_no_in, car_model_in, color_in, rental_prize_in);
}
car_info::~car_info() {}

void car_info::change(string plat_no_in, string car_model_in, string color_in,
                      float rental_prize_in) {
  plat_no = plat_no_in;
  car_model = car_model_in;
  color = color_in;
  rental_prize = rental_prize_in;
}

void car_info::change_rental_day(int rental_day_added) {
  rental_day=+rental_day_added;
}

void car_info::display() {
  cout << plat_no << endl;
  cout << car_model << endl;
  cout << color << endl;
  cout << rental_prize << endl;
  cout << rental_sale << endl;
  return;
}
string car_info::getplat_no() { return plat_no; }

bool car_info::larger_car_modal(car_info comparing)
{
  return (car_model+plat_no)<(comparing.car_model+comparing.plat_no);
}

bool car_info::smaller_car_modal(car_info comparing)
{
  return (car_model+plat_no)<(comparing.car_model+comparing.plat_no);
}

bool car_info::operator==(car_info &comparing) {
  return plat_no == comparing.getplat_no();
}
bool car_info::operator!=(car_info &comparing) {
  return plat_no != comparing.getplat_no();
}
bool car_info::operator>=(car_info &comparing) {
  return plat_no >= comparing.getplat_no();
}
bool car_info::operator<=(car_info &comparing) {
  return plat_no <= comparing.getplat_no();
}

bool car_info::operator>(car_info &comparing) {
  return plat_no > comparing.getplat_no();
}
bool car_info::operator<(car_info &comparing) {
  return plat_no < comparing.getplat_no();
}
ostream &operator<<(ostream &out, const car_info &output) {
  out <<left<< '|' <<setw(20)<< output.car_model << '|' <<setw(10)<< output.plat_no << '|' <<setw(10)<< output.color
      << '|' <<setw(10)<< output.rental_prize;
  return out;
}
