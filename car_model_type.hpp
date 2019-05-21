//
//  car_model_type.hpp
//  A2_CPT113
//
//  Created by <author> on 19/05/2019.
//
//

#ifndef car_model_type_hpp
#define car_model_type_hpp

#include <iomanip>
#include <iostream>
#include "nodeType.hpp"

class car_model_type {
private:
  std::string car_model;
  float rental_prize = 0;
  int count = 0;
  int rental_day = 0;
  float rental_sales = 0;
  display_item* display_measurement;
public:
  car_model_type();
  car_model_type(std::string);
  car_model_type(std::string, float);
  car_model_type(std::string, float, int);
  car_model_type(std::string, float, int, float);
  void set_display_item(display_item*);
  ~car_model_type();
  std::string getcar_model();
  float getrental_prize();
  int getrental_day();
  float getrental_sales();
  int getnumber_of_car();
  void change_car_model(std::string);
  void change_rental_prize(float);
  void change_count(int);
  void add_rental_day(int);
  void display();
  bool operator==(car_model_type &comparing);
  bool operator!=(car_model_type &comparing);
  bool operator>=(car_model_type &comparing);
  bool operator<=(car_model_type &comparing);
  bool operator>(car_model_type &comparing);
  bool operator<(car_model_type &comparing);
  car_model_type operator+(car_model_type &comparing);
  friend std::ostream &operator<<(std::ostream &, const car_model_type &);
};

#endif /* car_model_type_hpp */
