//
//  car_info.hpp
//  A2_CPT113
//
//  Created by <author> on 03/05/2019.
//
//

#ifndef car_info_hpp
#define car_info_hpp
#include <iostream>
#include <iomanip>
#include "book_info.hpp"
#include "mystack.hpp"
using namespace std;

class car_info {
protected:
  string plat_no;
  string car_model;
  string color;
  float rental_prize;
  float rental_sale = 0;
  mystack<book_info> booking_list;
public:
  void display();
  car_info();
  car_info(string,string,string,float);
  ~car_info();
  string getplat_no();
  void change(string,string,string,float);
  bool larger_car_modal(car_info);
  bool smaller_car_modal(car_info);
  bool operator==(car_info &comparing);
  bool operator!=(car_info &comparing);
  bool operator>=(car_info &comparing);
  bool operator<=(car_info &comparing);
  bool operator>(car_info &comparing);
  bool operator<(car_info &comparing);
  friend ostream& operator<< (ostream&, const car_info&);
};

#endif /* car_info_hpp */
