#include "binary_tree_sorting.hpp"
#include "book_info.hpp"
#include "car_info.hpp"
#include "car_info_list.hpp"
#include "mystack.hpp"
#include "ordered_linked_list.hpp"
#include "queue.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <thread>

int menu_selector_using_interger(int min, int max);
string get_string_from_user_input();
void clear_screen();
void pause();
string car_edit(int i, car_info_list &car_database);
void read_raw_info(queue<std::string> &to_stored, std::string file_to_open);
void erase_space_comer(string &input);
bool consist_alphabet_or_number(const std::string input);
bool validation_for_deciaml_number(const std::string input);
bool validation_for_alphabet(const std::string input);
bool validation_for_plate_number(const std::string input);
void extract_car_info_from_raw(car_info_list &car_database,
                               queue<string> &raw_info);
void write_2_file(car_info_list &car_database,string filename);


void generate_report(car_info_list &car_database) {
    string to_search;
  do
  {
    clear_screen();
    car_database.display_car_model();
    std::cout << "Search Car Model " << '\n';
    to_search=get_string_from_user_input();
    cout<< car_database.search_car_model_list(to_search)<<endl;
    pause();
  }while(to_search!="exit");
}

void menu2(car_info_list &car_database) {
  while (true) {
    clear_screen();
    std::cout << "Display/Edit Car Info & Booking Info Menu" << '\n';
    std::cout << "1. Display All" << '\n';
    std::cout << "2. Display Selected" << '\n';
    std::cout << "3. Edit/Delete Car Infomation + Add Booking Info" << '\n';
    std::cout << "4. Generate Summary" << '\n';
    std::cout << "5. Back to main menu" << '\n';
    std::cout << "Key in the menu number to go to" << '\n';
    int menu_no_selected = menu_selector_using_interger(1, 4);
    int menu_no_selected_2 = 0;
    int max_menu = 6;
    clear_screen();
    switch (menu_no_selected) {
    case 1:
      std::cout << "Display All Order By: " << '\n';
      std::cout << "1. Plate No." << '\n';
      std::cout << "2. Car Model" << '\n';
      std::cout << "3. Colour" << '\n';
      std::cout << "4. Rental Prize" << '\n';
      std::cout << "5. Rental Days" << '\n';
      std::cout << "6. Rental Sales" << '\n';
      break;
    case 2:
      std::cout << "Display Selected Order By: " << '\n';
      std::cout << "1. Plate No." << '\n';
      std::cout << "2. Car Model" << '\n';
      std::cout << "3. Colour" << '\n';
      std::cout << "4. Rental Prize" << '\n';
      std::cout << "5. Rental Days" << '\n';
      std::cout << "6. Rental Sales" << '\n';
      break;
    case 3:
      std::cout << "Car Info to be altered / delete?" << '\n';
      std::cout << "1. Provide the car plate no. " << '\n';
      std::cout << "2. Provide the index no. of the car" << '\n';
      std::cout << "Comment: Index number of the car is the counting number of "
                   "the car ordered in plate number."
                << '\n';
      std::cout << "Comment: Index number can be seen in Display All order by "
                   "plate no. in the most left side of the car."
                << '\n';
      max_menu = 2;
      break;
    case 4:
       generate_report(car_database);
      continue;
      break;
    case 5:
      return;
    }
    std::cout << "Key in the menu number to go to" << '\n';
    menu_no_selected_2 = menu_selector_using_interger(1, max_menu);
    clear_screen();
    if (menu_no_selected == 1) {
      std::cout << "Display All The Car in the Database" << '\n';
      switch (menu_no_selected_2) {
      case 1:
        car_database.sort_car_info_list("plate no");
        break;
      case 2:
        car_database.sort_car_info_list("car model");
        break;
      case 3:
        car_database.sort_car_info_list("color");
        break;
      case 4:
        car_database.sort_car_info_list("rental prize");
        break;
      case 5:
        car_database.sort_car_info_list("rental day");
        break;
      case 6:
        car_database.sort_car_info_list("rental sales");
        break;
      }
      car_database.display();
    } else if (menu_no_selected == 2) {
      string input_min, input_max;
      std::cout << "Selection Menu for ";
      switch (menu_no_selected_2) {
      case 1:
        std::cout << "Plate No." << '\n';
        break;
      case 2:
        std::cout << "Car Model" << '\n';
        break;
      case 3:
        std::cout << "Colour" << '\n';
        break;
      case 4:
        std::cout << "Rental Prize" << '\n';
        break;
      case 5:
        std::cout << "Rental Days" << '\n';
        break;
      case 6:
        std::cout << "Rental Sales" << '\n';
        break;
      }
      std::cout << "1. Specific" << '\n';
      std::cout << "2. Range" << '\n';
      int menu_no_selected_3 = menu_selector_using_interger(1, 2);
      bool validation = 0;
      do {
        switch (menu_no_selected_3) {
        case 1:
          std::cout << "Key in the value : " << '\n';
          break;
        case 2:
          std::cout << "Key in the minimum value: " << '\n';
          break;
        }
        input_min = get_string_from_user_input();
        switch (menu_no_selected_2) {
        case 1:
          if (validation_for_plate_number(input_min))
            validation = 1;
          else
            std::cerr
                << input_min << " -"
                << "the input must be alphabet and at least one number only"
                << '\n';
          break;
        case 2:
        case 3:
          if (validation_for_alphabet(input_min))
            validation = 1;
          else
            std::cerr << input_min
                      << " -the input must consist of alphabet only" << '\n';
          break;
        default:
          if (validation_for_deciaml_number(input_min))
            validation = 1;
          else
            std::cerr << input_min
                      << " -the input must consist of decimal number only"
                      << '\n';
        }
      } while (input_min != "exit" && input_min != "-1" && validation == 0);
      if (menu_no_selected_3 == 1) {
        input_max = input_min;
      } else if (menu_no_selected_3 == 2) {
        validation = 0;
        do {
          std::cout << "Key in the maximum value: " << '\n';
          input_max = get_string_from_user_input();
          switch (menu_no_selected_2) {
          case 1:
            if (validation_for_plate_number(input_max))
              validation = 1;
            else
              std::cerr
                  << input_max << " -"
                  << "the input must be alphabet and at least one number only"
                  << '\n';
            break;
          case 2:
          case 3:
            if (validation_for_alphabet(input_max))
              validation = 1;
            else
              std::cerr << input_max
                        << " -the input must consist of alphabet only" << '\n';
            break;
          default:
            if (validation_for_deciaml_number(input_max))
              validation = 1;
            else
              std::cerr << input_max
                        << " -the input must consist of decimal number only"
                        << '\n';
          }
        } while (input_max != "exit" && input_max != "-1" && validation == 0);
      }
      if (input_max == "exit" && input_max == "-1")
        continue;

      switch (menu_no_selected_2) {
      case 1:
        car_database.display_selected("plate no", input_min, input_max);
        break;
      case 2:
        car_database.display_selected("car model", input_min, input_max);
        break;
      case 3:
        car_database.display_selected("color", input_min, input_max);
        break;
      case 4:
        car_database.display_selected("rental prize", input_min, input_max);
        break;
      case 5:
        car_database.display_selected("rental day", input_min, input_max);
        break;
      case 6:
        car_database.display_selected("rental sales", input_min, input_max);
        break;
      }
    }

    else if (menu_no_selected == 3) {
      string input_1;
      int input_2;
      nodeType<car_info> *selected_car;
      switch (menu_no_selected_2) {
      case 1:
        do {
          clear_screen();
          std::cout << "Key in the Plate No. if the car: " << '\n';
          input_1 = get_string_from_user_input();
          if (validation_for_plate_number(input_1))
            break;
          else {
            std::cerr
                << input_1 << " -"
                << "plate number must be alphabet and at least one number only"
                << '\n';
          }
        } while (input_1 != "exit" && input_1 != "-1");
        selected_car = car_database.get_car(car_info(input_1));
        break;
      case 2:
        do {
          clear_screen();
          std::cout << "Key in the Index Number of the car: " << '\n';
          input_2 =
              menu_selector_using_interger(1, car_database.length_of_list());
        } while (input_2 == -99);
        selected_car = car_database.get_car_by_index(input_2 - 1);
        break;
      }
      do {
        clear_screen();
        selected_car->content.display();
        std::cout << "Key in the number in front of the info to edit it.Press "
                     "-1 to go back."
                  << '\n';
        std::cout << "Rental sales cannot be edited." << '\n';
        std::cout << "Press 6. to delete the car info" << '\n';
        std::cout << "Press 6. to delete the car info" << '\n';
        input_2 = menu_selector_using_interger(1, 5);
        if (input_2 == -1)
          break;
        input_1 = car_edit(input_2, car_database);
        switch (input_2) {
        case 1:
          selected_car->content.change(input_1,
                                       selected_car->content.getcar_model(),
                                       selected_car->content.getcar_color(),
                                       selected_car->content.getrental_prize(),
                                       selected_car->content.getrental_day());
          break;
        case 2:
          car_database.edit_car(selected_car->content.getplat_no(), input_1,
                                selected_car->content.getcar_color(),
                                selected_car->content.getrental_prize(),
                                selected_car->content.getrental_day());
          break;
        case 3:
          car_database.edit_car(selected_car->content.getplat_no(),
                                selected_car->content.getcar_model(), input_1,
                                selected_car->content.getrental_prize(),
                                selected_car->content.getrental_day());
          break;
        case 4:
          car_database.edit_car(selected_car->content.getplat_no(),
                                selected_car->content.getcar_model(),
                                selected_car->content.getcar_color(),
                                stof(input_1),
                                selected_car->content.getrental_day());
          break;
        case 5:
          car_database.edit_car(selected_car->content.getplat_no(),
                                selected_car->content.getcar_model(),
                                selected_car->content.getcar_color(),
                                selected_car->content.getrental_prize(),
                                stoi(input_1));
          break;
        case 6:
          car_database.delete_car(selected_car->content.getplat_no());
        }
      } while (input_2 == -1);
      write_2_file(car_database,"car.txt");
    }
    pause();
  }
}

int main() {
  car_info_list car_database;
  queue<string> car_info_raw;
  string filename;
  string plate_no, car_model, color;
  float rental_prize_float = 0;
  while (true) {
    clear_screen();
    std::cout << "Penang-Car-to-Rent" << '\n';
    std::cout << "Main menu" << '\n';
    std::cout << "1. Add Car Info Through Files" << '\n';
    std::cout << "2. Add Car Info Through Keyboard" << '\n';
    std::cout << "3. Display/Edit Car Info & Booking Info Menu" << '\n';
    std::cout << ". Exit" << '\n';
    std::cout << "Key in the menu number to go to" << '\n';
    int menu_no_selected = menu_selector_using_interger(1, 4);
    switch (menu_no_selected) {
    case 1:
      std::cout << "Key In the file name: " << '\n';
      filename = get_string_from_user_input();
      std::cout << "Reading file: " << filename << '\n';
      read_raw_info(car_info_raw, filename);
      extract_car_info_from_raw(car_database, car_info_raw);
      pause();
      break;
    case 2:
      clear_screen();
      std::cout << "Keyboard Mode" << '\n';
      for (int i = 1; i < 5; i++) {
        string temp = car_edit(i, car_database);
        if (temp == "-1" || temp == "exit") {
          std::cout << "Discarding the data key in just now" << '\n';
          break;
        } else {
          switch (i) {
          case 1:
            plate_no = temp;
            break;
          case 2:
            car_model = temp;
            break;
          case 3:
            color = temp;
            break;
          case 4:
            rental_prize_float = stod(temp);
            car_database.insert_car(
                car_info(plate_no, car_model, color, rental_prize_float));
            break;
          }
        }
      }
      clear_screen();
      std::cout << "The car infomation is saved into the database." << '\n';
      car_info(plate_no, car_model, color, rental_prize_float).display();
      pause();
      break;
    case 3:
      menu2(car_database);
      break;
    case 4:
      return 0;
    default:
      break;
    }
    std::cout << "Please wait..." << '\n';
    for (int i = 1; i > 0; i--) {
      std::cout << i << '\n';
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
}

int menu_selector_using_interger(int min, int max) {
  int nomenu;
  for (int count_error = 0; count_error < 5; count_error++) {

    cin >> nomenu;
    if ((min <= nomenu && nomenu <= max) || cin.good()) {
      cin.clear();
      cin.ignore();
      return nomenu;
    }
    if (nomenu == -1)
      return -1;
    cin.clear();
    cin.ignore();
    // Try delete this line and type character in selecting menu.
    // Avoid bug or infinite loop of  the cout forehand and skipping
    // cin afterward.
    cout << "Good try. Please try again with valid number.\n";
  }
  return -99;
}

string get_string_from_user_input() {
  string input;
  for (int count_error = 0; count_error < 5; count_error++) {
    getline(cin, input);
    if (cin.good()) {
      return input;
    }
    cin.clear();
    cin.ignore();
    // Try delete this line and type character in selecting menu.
    // Avoid bug or infinite loop of  the cout forehand and skipping
    // cin afterward.
    cout << "Good try. Please try again with valid input.\n";
  }
  return NULL;
}

void clear_screen() { system("clear"); }

void pause() {
  std::cout << "Press any key to continue..." << '\n';
  cin.get();
}

string car_edit(int i, car_info_list &car_database) {
  // To edit car infomation: 1 for plate number ; 2 for car model; 3 for car
  // colour ; 4 for car rental prize
  string to_change;
  switch (i) {
  case 1: // plate no.
    do {
      std::cout << "The car plate number: " << '\n';
      to_change = get_string_from_user_input();
      if (validation_for_plate_number(to_change))
        break;
      else
        std::cout << "Please try again." << '\n';
    } while (to_change != "exit" && to_change != "-1");
    if (car_database.search(to_change) != -1) {
      std::cout << "The same car plate number is in the database." << '\n';
      to_change = "-1";
    }
    break;
  case 2: // car model
    do {
      std::cout << "The car model: " << '\n';
      to_change = get_string_from_user_input();
      if (validation_for_alphabet(to_change))
        break;
      else
        std::cout << "Please try again." << '\n';
    } while (to_change != "exit" && to_change != "-1");
    break;
  case 3: // car colour
    do {
      std::cout << "The car colour: " << '\n';
      to_change = get_string_from_user_input();
      if (validation_for_alphabet(to_change))
        break;
      else
        std::cout << "Please try again." << '\n';
    } while (to_change != "exit" && to_change != "-1");
    break;
  case 4: // rental prize
    do {
      std::cout << "The car rental prize: " << '\n';
      to_change = get_string_from_user_input();
      if (validation_for_deciaml_number(to_change))
        break;
      else
        std::cout << "Please try again." << '\n';
    } while (to_change != "exit" && to_change != "-1");
    break;
  case 5:
    int day_to_change;
    do {
      std::cout << "The car rental days: " << '\n';
      day_to_change =
          menu_selector_using_interger(0, std::numeric_limits<int>::max());
      if (validation_for_deciaml_number(to_change)) {
        to_change = to_string(day_to_change);
        break;
      } else
        std::cout << "Please try again." << '\n';
    } while (day_to_change == -99);
  }
  return to_change;
}

void read_raw_info(queue<std::string> &to_stored, std::string file_to_open) {
  std::ifstream openfile;
  openfile.open(file_to_open, std::ios::in);
  if (!openfile.is_open()) {
    std::cerr << "Unable to open file named " << file_to_open << "!\n";
    return ;
  } else {
    std::string line;
    while (!openfile.eof()) {
      std::getline(openfile, line);
      if (openfile.eof())
        break;
      to_stored.addQueue(line);
    }
    std::cout << "Read File Finished" << '\n';
    openfile.close();
  }
}

void erase_space_comer(string &input) {
  if (!isalnum(input.at(0))) {
    while (!isalnum(input.at(0))) {
      input.erase(0, 1);
    }
  }
  if (!isalnum(input.at(input.length()-1))) {
    cout << input << ' ' << input.at(input.length()-1) << endl;
    while (!isalnum(input.at(input.length()-1))) {
      input.erase(input.length()-1, 1);
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
    if ((!isdigit(input.at(i)) &&
         (input.at(i) != '.'))) // check for digit&decimal point
      return false;
  }
  return true;
}

bool validation_for_alphabet(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if (!(isalpha(input.at(i)) || isblank(input.at(i) ))) // check for alphabet
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
    getline(ss, plate_no, ',');
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
        color = "no info";
      } else
        erase_space_comer(rental_prize);
      std::cout << "Erase Finished" << '\n';
      if (!validation_for_alphabet(car_model)) {
        std::cerr << car_model << " -car model must consist of alphabet only"
                  << '\n';
      } else if (!validation_for_plate_number(plate_no)) {
        std::cerr
            << plate_no << " -"
            << "plate number must be alphabet and at least one number only"
            << '\n';
      } else if (!validation_for_deciaml_number(rental_prize)) {
        std::cerr << rental_prize << " -rental prize must be a decimal number"
                  << '\n';
      } else {
        std::cout << "Validation Checked" << '\n';
        std::cout<<plate_no<<endl;
        rental_prize_float = stof(rental_prize);
        std::cout << "rental prize is converted into float" << '\n';
        car_database.insert_car(plate_no, car_model, color, rental_prize_float);
        std::cout << "Insert into Database Finished" << '\n';
        std::cout << "---------------------------------------------------------------------------" << '\n';
      }
    }
    raw_info.delQueue();
  }
  return;
}

void write_2_file(car_info_list &car_database,string filename){
  std::cout << "Saving into file named: "<<filename << '\n';
  std::ofstream writefile(filename, std::ios::trunc);
  if (writefile.is_open()) {
    car_database.sort_car_info_list("default");
    nodeType<car_info>* current = car_database.get_car_by_index(0);
    while(current!=NULL)
    {writefile << current->content.getplat_no()<<", "<<current->content.getcar_model()<<", "<<current->content.getcar_color()<<", "<<current->content.getrental_prize()<<endl;
    current=current->next_node;
    }
    writefile<<endl;
    writefile.close();
  }
}
