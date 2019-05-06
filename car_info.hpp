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

using namespace std;

class car_info {
protected:
  string plat_no;
  string car_model;
  string color;
  float rental_prize;
  float rental_sale = 0;

public:
  void display();
  car_info();
  car_info(string,string,string,float);
  ~car_info();

};

#endif /* car_info_hpp */
