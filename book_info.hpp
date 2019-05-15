//
//  book_info.hpp
//  Projects
//
//  Created by <author> on 03/05/2019.
//
//

#ifndef book_info_hpp
#define book_info_hpp
#include <iostream>
#include <string.h>
using namespace std;

class book_info {
protected:
  string IC_number;
  string name;
  string Phone_number;
  int date;             // use time lib??
  int renting_duration; // Unit in day
  string car_model;
  float total_rental_fee;
  float deposit;

public:
  book_info();
  book_info(string, string, string, int, int, string, float);
  ~book_info();
  void display();

};

#endif /* book_info_hpp */
