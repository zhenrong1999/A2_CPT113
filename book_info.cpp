//
//  book_info.cpp
//  Projects
//
//  Created by <author> on 03/05/2019.
//
//

#include "book_info.hpp"

book_info::book_info(char IC_number_in[], string name_in,
                     char Phone_number_in[],
                     int date_in,             // use time lib??
                     int renting_duration_in, // Unit in day
                     string car_model_in, float total_rental_fee_in) {
  int IC_number_length = 9;
  int Phone_number_in_length = 9;
  IC_number = new char[IC_number_length];
  for (int i = 0; i < IC_number_length; i++)
    IC_number[i] = IC_number_in[i];
  name = name_in;
  Phone_number = new char[Phone_number_in_length];
  for (int i = 0; i < Phone_number_in_length; i++)
    Phone_number[i] = Phone_number_in[i];
  date = date;
  renting_duration = renting_duration_in;
  car_model = car_model_in;
  total_rental_fee = total_rental_fee_in;
  deposit = total_rental_fee_in * 0.1;
}
book_info::~book_info() {}

void book_info::display() {
  cout << IC_number << endl;
  cout << name << endl;
  cout << Phone_number << endl;
  cout << date << endl;
  cout << renting_duration << endl;
  cout << car_model << endl;
  cout << total_rental_fee << endl;
  cout << deposit << endl;
}
