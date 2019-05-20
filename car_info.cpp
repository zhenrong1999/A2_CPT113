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
car_info::car_info(string plat_no_in, string car_model_in, string color_in,
                   float rental_prize_in,int rental_day_in, float rental_sales_in) {
  plat_no=plat_no_in;
  car_model=car_model_in;
  color=color_in;
  rental_prize=rental_prize_in;
  rental_day=rental_day_in;
  rental_sales=rental_sales_in;
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

void car_info::set_display_item(display_item* display_item_in){
  display_measurement=display_item_in;
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

car_info car_info::operator+(car_info &comparing) {
  car_info total("Total","Total","no info", rental_prize + comparing.rental_prize,
                       rental_day + comparing.rental_day,
                       rental_sales + comparing.rental_sales);
  return total;
}

ostream &operator<<(ostream &out, const car_info &output) {
  out << left << '|' << setw(output.display_measurement->max_length_of_car_model) << output.car_model << '|' << setw(output.display_measurement->max_length_of_plate_no)
      << output.plat_no << '|' << setw(output.display_measurement->max_length_of_colour) << output.color << '|' << setw(output.display_measurement->max_length_of_rental_prize)
      << output.rental_prize << '|' << setw(output.display_measurement->max_length_of_rental_day) << output.rental_day << '|'
      << setw(output.display_measurement->max_length_of_rental_sales) << output.rental_sales << '|';
  return out;
}
