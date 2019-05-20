//
//  car_info.hpp
//  A2_CPT113
//
//  Created by <author> on 03/05/2019.
//
//

#ifndef car_info_hpp
#define car_info_hpp
#include "mystack.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

class car_info {
protected:
  string plat_no;
  string car_model;
  string color;
  float rental_prize = 0;
  int rental_day = 0;
  float rental_sales = 0;

public:
  void display();
  car_info();
  car_info(string);
  car_info(string, string, string, float);
  ~car_info();
  string getplat_no();
  string getcar_model();
  string getcar_color();
  float getrental_prize();
  int getrental_day();
  float getrental_sales();
  void change(string, string, string, float, int);
  void change_rental_prize(float);
  void change_rental_day(int);
  bool larger_car_modal(car_info);
  bool smaller_car_modal(car_info);
  bool operator==(car_info &comparing);
  bool operator!=(car_info &comparing);
  bool operator>=(car_info &comparing);
  bool operator<=(car_info &comparing);
  bool operator>(car_info &comparing);
  bool operator<(car_info &comparing);
  friend ostream &operator<<(ostream &, const car_info &);
};

#endif /* car_info_hpp */
