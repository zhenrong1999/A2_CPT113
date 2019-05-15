#include "main.hpp"


void read_raw_info(queue<std::string>& to_stored, std::string file_to_open) {
  std::ifstream openfile;
  openfile.open(file_to_open, std::ios::in);
  if (!openfile.is_open()) {
    std::cerr << "Unable to open file named "<< file_to_open <<"!\n";
  } else {
    std::string line;
    while (std::getline(openfile, line)) {
      to_stored.addQueue(line);
    }
    openfile.close();
  }
}

bool validation()
{
  
  return false;
}

int main()
{
  ordered_linked_list<car_info> car_database;
  //car_info *abc=new car_info;
  //abc->change("PBU6629","Proton Saga","Red",120);
  //car_database.insert_item(*abc);
  //car_database.get_item(0).display();
  queue<string> car_info_raw;
  read_raw_info(car_info_raw,"car info.txt");
  while(!car_info_raw.is_empty())
  {
    cout<<car_info_raw.front()<<endl;
    car_info_raw.delQueue();
  }
}
