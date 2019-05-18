#include "main.hpp"

void read_raw_info(queue<std::string> &to_stored, std::string file_to_open) {
  std::ifstream openfile;
  openfile.open(file_to_open, std::ios::in);
  if (!openfile.is_open()) {
    std::cerr << "Unable to open file named " << file_to_open << "!\n";
  } else {
    std::string line;
    while (!openfile.eof()) {
      std::getline(openfile, line);
      if (openfile.eof())
        break;
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

bool consist_alphabet_or_number(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if (isalnum(input.at(i))) // check for digit & alphabet
      return true;
  }
  return false;
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

void extract_car_info_from_raw(car_info_list &car_database,
                               queue<string> &raw_info) {
  while (!raw_info.is_empty()) {
    string line = raw_info.front();
    if (!consist_alphabet_or_number(line)) {
      cout << line << endl;
      raw_info.delQueue();
      continue;
    }
    stringstream ss;
    ss.str(line);
    string plate_no, car_model, color, rental_prize;
    float rental_prize_float = 0;
    getline(ss, plate_no,',');
    if (!plate_no.empty()) {
      getline(ss, car_model, ',');
      getline(ss, color, ',');
      getline(ss, rental_prize);
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
      } else if (!validation_for_plate_number(plate_no)) {
        std::cerr<<plate_no<<" "
            << "plate number must be alphabet and at least one number only"
            << '\n';
      } else if (!validation_for_deciaml_number(rental_prize)) {
        std::cerr << "rental prize must be a decimal number" << '\n';
      } else {
        rental_prize_float = stof(rental_prize);
        car_database.insert_car(plate_no, car_model, color, rental_prize_float);
      }
    }
    raw_info.delQueue();
  }
  return;
}

int main() {
  car_info_list car_database;
  queue<string> car_info_raw;
  read_raw_info(car_info_raw, "test.txt");
  extract_car_info_from_raw(car_database, car_info_raw);

     car_database.display();
   car_database.sort_car_info_list("car model");
   std::cout << '\n';
   car_database.display();
}
