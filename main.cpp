#include "main.hpp"

void read_raw_info(queue<std::string> &to_stored, std::string file_to_open) {
  std::ifstream openfile;
  openfile.open(file_to_open, std::ios::in);
  if (!openfile.is_open()) {
    std::cerr << "Unable to open file named " << file_to_open << "!\n";
  } else {
    std::string line;
    while (std::getline(openfile, line)) {
      to_stored.addQueue(line);
    }
    openfile.close();
  }
}

void erase_space_comer(string &input) {
  if (!isalnum(input.at(0))) {
    while (!isalnum(input.at(0))) {
      input.erase(0, 1);
    }
  }
  if (!isalnum(input.at(input.length() - 1))) {
    cout << input << ' ' << input.at(input.length() - 1) << endl;
    while (!isalnum(input.at(input.length() - 1))) {
      input.erase(input.length() - 1, 1);
    }
  }
}

bool validation_for_deciaml_number(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if ((!isdigit(input.at(i)) && (input.at(i) != '.'))) // check for digit
      return false;
  }
  return true;
}

bool validation_for_alphabet(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if (!(isalpha(input.at(i)) || isblank(input.at(i)))) // check for digit
      return false;
  }
  return true;
}

bool validation_for_plate_number(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if (!isalnum(input.at(i))) // check for digit & alphabet
      return false;
  }
  bool checked = 0;
  for (unsigned int i = 0; i < input.length(); i++)
    if (isalpha(input.at(i))) {
      checked = 1;
      break;
    }
  if (checked == 1)
    for (unsigned int i = 0; i < input.length(); i++)
      if (isdigit(input.at(i)))
        return true;
  return false;
}



void extract_car_info_from_raw(ordered_linked_list<car_info> &car_database,
                               queue<string> raw_info) {
   binary_tree_sorting<string,car_info> testing;
  while (!raw_info.is_empty()) {
    string line = raw_info.front();
    stringstream ss;
    ss.str(line);
    string plate_no, car_model, color, rental_prize;
    float rental_prize_float = 0;
    getline(ss, plate_no, ',');
    getline(ss, car_model, ',');
    getline(ss, color, ',');
    getline(ss, rental_prize, ',');
    if (!plate_no.empty())
      erase_space_comer(plate_no);
    if (!car_model.empty())
      erase_space_comer(car_model);
    if (!color.empty())
      erase_space_comer(color);

    if (rental_prize.empty()) {
      rental_prize = color;
      color = "-";
    } else
      erase_space_comer(rental_prize);

    if (!validation_for_alphabet(car_model)) {
      std::cerr << "car model must consist of alphabet only" << '\n';
      raw_info.delQueue();
      continue;
    }

    if (!validation_for_deciaml_number(rental_prize)) {
      std::cerr << "rental prize must be a decimal number" << '\n';
      raw_info.delQueue();
      continue;
    } else {
      rental_prize_float = stof(rental_prize);
    }
    if (!validation_for_plate_number(plate_no)) {
      std::cerr << "plate number must be alphabat and at least one number only"
                << '\n';
      raw_info.delQueue();
      continue;
    }
    car_database.insert_item(
        car_info(plate_no, car_model, color, rental_prize_float));
      testing.insert(plate_no,car_info(plate_no, car_model, color, rental_prize_float));
    raw_info.delQueue();
  }
  testing.display_inorder();
}



int main() {
  ordered_linked_list<car_info> car_database;
  // car_info *abc=new car_info;
  // abc->change("PBU6629","Proton Saga","Red",120);
  // car_database.insert_item(*abc);
  // car_database.get_item(0).display();
  queue<string> car_info_raw;
  read_raw_info(car_info_raw, "car info.txt");
  extract_car_info_from_raw(car_database, car_info_raw);
  // car_database.display();
}
