//
//  car_info.cpp
//  A2_CPT113
//
//  Created by <author> on 03/05/2019.
//
//
#include "car_info.hpp"


car_info::car_info() {}
car_info::car_info(string plat_no_in) { plat_no = plat_no_in; }
car_info::car_info(string plat_no_in, string car_model_in, string color_in,
                   float rental_prize_in) {
  change(plat_no_in, car_model_in, color_in, rental_prize_in, 0);
}
car_info::~car_info() {}

void car_info::change(string plat_no_in, string car_model_in, string color_in,
                      float rental_prize_in, int rental_day_in) {
  plat_no = plat_no_in;
  car_model = car_model_in;
  color = color_in;
  rental_prize = rental_prize_in;
  rental_day = rental_day_in;
  rental_sales = rental_prize * rental_day;
}

void car_info::change_rental_prize(float rental_prize_in) {
  rental_prize = rental_prize_in;
  rental_sales = rental_day * rental_prize;
}

void car_info::change_rental_day(int rental_day_added) {
  rental_day += rental_day_added;
  rental_sales += rental_day_added * rental_prize;
}

void car_info::display() {
  cout << left << setw(18) << "1. Car Plate no: " << plat_no << endl;
  cout << left << setw(18) << "2. Car Model: " << car_model << endl;
  cout << left << setw(18) << "3. Car Colour: " << color << endl;
  cout << left << setw(18) << "4. Rental Prize: " << rental_prize << endl;
  cout << left << setw(18) << "5. Rental Day: " << rental_day << endl;
  cout << left << setw(18) << "6. Rental Sales: " << rental_sales << endl;
  return;
}
string car_info::getplat_no() { return plat_no; }
string car_info::getcar_model() { return car_model; }
float car_info::getrental_prize() { return rental_prize; }
string car_info::getcar_color() { return color; }
int car_info::getrental_day() { return rental_day; }
float car_info::getrental_sales() { return rental_sales; }

bool car_info::larger_car_modal(car_info comparing) {
  return (car_model + plat_no) < (comparing.car_model + comparing.plat_no);
}

bool car_info::smaller_car_modal(car_info comparing) {
  return (car_model + plat_no) < (comparing.car_model + comparing.plat_no);
}

bool car_info::operator==(car_info &comparing) {
  //return plat_no == comparing.getplat_no();
  if(plat_no.compare(comparing.plat_no)==0)
    return true;
  return false;
}
bool car_info::operator!=(car_info &comparing) {
  //return plat_no != comparing.getplat_no();
  if(plat_no.compare(comparing.plat_no)!=0)
    return true;
  return false;
}
bool car_info::operator>=(car_info &comparing) {
  //return plat_no >= comparing.getplat_no();
  if(plat_no.compare(comparing.plat_no)>=0)
    return true;
  return false;
}
bool car_info::operator<=(car_info &comparing) {
  //return plat_no <= comparing.getplat_no();
  if(plat_no.compare(comparing.plat_no)<=0)
    return true;
  return false;
}

bool car_info::operator>(car_info &comparing) {
  //return plat_no > comparing.getplat_no();
  if(plat_no.compare(comparing.plat_no)>0)
    return true;
  return false;
}
bool car_info::operator<(car_info &comparing) {
  //return plat_no < comparing.getplat_no();
  if(plat_no.compare(comparing.plat_no)<0)
    return true;
  return false;
}
ostream &operator<<(ostream &out, const car_info &output) {
  out << left << '|' << setw(20) << output.car_model << '|' << setw(10)
      << output.plat_no << '|' << setw(10) << output.color << '|' << setw(12)
      << output.rental_prize << '|' << setw(12) << output.rental_day << '|'
      << setw(12) << output.rental_sales << '|';
  return out;
}
