//
//  nodeType.hpp
//  A2_CPT113
//
//  Created by <author> on 04/05/2019.
//
//

#ifndef nodeType_hpp
#define nodeType_hpp
#include <iostream>

template <class Type>
struct nodeType {
  Type content;
  nodeType<Type> *next_node;
};

struct display_item {
  int max_length_of_list_no = 3;
  int max_length_of_plate_no = 14;
  int max_length_of_car_model = 20;
  int max_length_of_colour = 12;
  int max_length_of_rental_prize = 25;
  int max_length_of_rental_day = 12;
  int max_length_of_rental_sales = 16;
};
struct compare_string
{
  bool larger(std::string a,std::string comparing){
    if(a.length()>comparing.length())
    {
      a.erase(comparing.length(),a.length()-comparing.length());
    }
  else if(a.length()<comparing.length())
      comparing.erase(a.length(),comparing.length()-a.length());
  return a>comparing;}

  bool larger_equal(std::string a,std::string comparing){
    if(a.length()>comparing.length())
    {
      a.erase(comparing.length(),a.length()-comparing.length());
    }
  else if(a.length()<comparing.length())
      comparing.erase(a.length(),comparing.length()-a.length());
  return a>=comparing;}

  bool smaller(std::string a,std::string comparing){
    if(a.length()>comparing.length())
    {
      a.erase(comparing.length(),a.length()-comparing.length());
    }
  else if(a.length()<comparing.length())
      comparing.erase(a.length(),comparing.length()-a.length());
  return a<comparing;}

  bool smaller_equal(std::string a,std::string comparing){
    if(a.length()>comparing.length())
    {
      a.erase(comparing.length(),a.length()-comparing.length());
    }
  else if(a.length()<comparing.length())
      comparing.erase(a.length(),comparing.length()-a.length());
  return a<=comparing;}

  bool equal(std::string a,std::string comparing){
    if(a.length()>comparing.length())
    {
      a.erase(comparing.length(),a.length()-comparing.length());
    }
  else if(a.length()<comparing.length())
      comparing.erase(a.length(),comparing.length()-a.length());
  return a==comparing;}
};


#endif /* nodeType_hpp */
