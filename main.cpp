//#include "car_info.hpp"
#include "book_info.hpp"
#include "car_info.hpp"

int main() {
  car_info car1("PBU6629", "Proton Saga", "white", 100);
  car1.display();
  char ic[12]={'9','9','0','4','2','2','0','7','6','6','7','7'};
  char phone[]={'0','1','2','3','4','5','6','7','8','9'};
  book_info acb(ic, "Teh Zhen Rong", phone, 12092019, 1,"Proton Saga", 100);
  ic[0]='a';
  phone[0]='a';
  acb.display();
}
