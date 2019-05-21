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
void draw_line(display_item* display_measurement,string line);
string car_edit(int i, car_info_list &car_database);
void read_raw_info(queue<std::string> &to_stored, std::string file_to_open);
void erase_space_comer(string &input);
string string_to_upper(string input);
bool consist_alphabet_or_number(const std::string input);
bool consist_alphabet_or_number_only(const std::string input);
bool validation_for_deciaml_number(const std::string input);
bool validation_for_alphabet(const std::string input);
bool validation_for_plate_number(const std::string input);
string text_file_format(std::string input);
void extract_car_info_from_raw(car_info_list &car_database,
                               queue<string> &raw_info);
void write_2_file(car_info_list &car_database, string filename);

void calculator_for_rental_sales(car_info_list &car_database) {
  display_item* display_measurement=car_database.get_display_measurement();
  int menu_no_selected;
  int menu_no_selected_2;
  string to_search;
  int index_to_search;
  car_database.sort_car_model_list("default");
  ordered_linked_list<car_model_type> model_temp_list;
  model_temp_list.set_display_item(display_measurement);
  do {
    clear_screen();
    std::cout << "List Of All Car Model " << '\n';
    car_database.display_car_model();
    draw_line(display_measurement,"=");
    std::cout << "Calculator for rental sales" << '\n';
    draw_line(display_measurement,"=");
    if(!model_temp_list.is_empty())
    {
      std::cout << "Workspace for Calculator" << '\n';
      draw_line(display_measurement,"*");
      car_database.table_form_display("header", car_model_type(), 0);
      model_temp_list.display();
      draw_line(display_measurement,"*");
    }
    std::cout << "1. Add Car Model" << '\n';
    std::cout << "2. Edit Car Model" << '\n';
    std::cout << "3. Total Up" << '\n';
    std::cout << "Key in the menu number to go to" << '\n';
    menu_no_selected = menu_selector_using_interger(1, 3);
    if (menu_no_selected == 1) {
      std::cout << "Get Details of One Car Model + Edit" << '\n';
      std::cout << "1. Provide the car model " << '\n';
      std::cout << "2. Provide the index no. of the car model" << '\n';
      std::cout << "Comment: Index number of the car is the counting number of "
                   "the car model ordered in car model."
                << '\n';
      std::cout << "Comment: Index number can be seen in List Of All Car Model "
                   "order by "
                   "car model. in the most left side of the car model."
                << '\n';
      std::cout << "Key in the menu number to go to" << '\n';
      menu_no_selected_2 = menu_selector_using_interger(1, 2);
      switch (menu_no_selected_2) {
      case 1:
        do {
          std::cout << "Key in the car model: " << '\n';
          to_search = string_to_upper(get_string_from_user_input());
          if (consist_alphabet_or_number_only(to_search))
            break;
          else {
            std::cerr << to_search << " -"
                      << "car model must be alphabet or number only" << '\n';
          }
        } while (to_search != "EXIT" && to_search != "-1");
        index_to_search = car_database.search_car_model_list(to_search);
        if (index_to_search == -1) {
          std::cerr << "The car model is not found." << '\n';
        }
        break;
      case 2:
        do {

          std::cout << "Key in the Index Number of the car: " << '\n';
          index_to_search =
              menu_selector_using_interger(1, car_database.length_of_list());
        } while (index_to_search == -99);
        index_to_search--;
        break;
      }
      if(index_to_search>=0)
      {
        nodeType<car_model_type> *to_add = car_database.get_car_model_type_by_index(index_to_search);
        car_model_type adding(to_add->content.getcar_model(),to_add->content.getrental_prize());
        std::cout << "Key in the Rental day of the car model: " << '\n';
        int rental_day=menu_selector_using_interger(0, std::numeric_limits<int>::max());
        if(rental_day>0){
          adding.add_rental_day(rental_day);
          adding.set_display_item(display_measurement);
          model_temp_list.insert_item(adding);
        }
      }
    }
    else if(menu_no_selected==2){
      std::cout<<"Key in the Line Number of the Workspace"<<'\n';
      menu_no_selected_2=menu_selector_using_interger(1,model_temp_list.length_of_list());
      menu_no_selected_2--;
      cout<<"Change the Rental Day to: "<<'\n';
      cout<<"Comment to delete key in 0"<<'\n';
      int rental_day=menu_selector_using_interger(0, std::numeric_limits<int>::max());
      nodeType<car_model_type> *to_edit = model_temp_list.get_item_by_index(menu_no_selected_2-1);
      if(rental_day>0){
        int rental_day_to_change=rental_day-to_edit->content.getrental_day();
        to_edit->content.add_rental_day(rental_day_to_change);
      }
      else if(rental_day==0)
      {
        model_temp_list.delete_index(menu_no_selected_2);
      }

    }
    else
    {
      if(!model_temp_list.is_empty())
      {
        car_model_type total;
        for (int i = 0; i < model_temp_list.length_of_list(); i++) {
          total=total+model_temp_list.get_item_by_index(i)->content;
        }
        std::cout << "Total Rental Sales = "<< total.getrental_sales()<< '\n';
      }
      std::cout << "Leaving this calculator." << '\n';
      pause();
      return;
    }
    pause();
  } while (true);
}

void generate_report(car_info_list &car_database,string filename_to_write) {
  int menu_no_selected;
  int menu_no_selected_2;
  int max_menu = 5;
  string to_search;
  int index_to_search;
  do {
    clear_screen();
    car_database.sort_car_model_list("default");
    std::cout << "List Of All Car Model " << '\n';
    car_database.display_car_model();
    draw_line(car_database.get_display_measurement(),"-");
    std::cout << "1. Get Details of One Car Model + Edit" << '\n';
    std::cout << "2. Calculate Rental Sales for Car Models without "
                 "saving.(Calculator)"
              << '\n';
    std::cout << "3. Display List Of All Car Model with different order. "
              << '\n';
    std::cout << "4. Back" << '\n';
    std::cout << "Key in the menu number to go to" << '\n';
    menu_no_selected = menu_selector_using_interger(1, 4);
    clear_screen();
    switch (menu_no_selected) {
    case 1:
      std::cout << "Get Details of One Car Model + Edit" << '\n';
      std::cout << "1. Provide the car model " << '\n';
      std::cout << "2. Provide the index no. of the car model" << '\n';
      std::cout << "Comment: Index number of the car is the counting number of "
                   "the car model ordered in car model."
                << '\n';
      std::cout << "Comment: Index number can be seen in List Of All Car Model "
                   "order by "
                   "car model. in the most left side of the car model."
                << '\n';
      max_menu = 2;
      break;
    case 2:
      calculator_for_rental_sales(car_database);
      break;
    case 3:

      std::cout << "Display List Of All Car Model with different order. "
                << '\n';
      std::cout << "Order by:" << '\n';
      std::cout << "1. Car Model" << '\n';
      std::cout << "2. Rental Prize" << '\n';
      std::cout << "3. Rental Days" << '\n';
      std::cout << "4. Rental Sales" << '\n';
      std::cout << "5. Go Back" << '\n';
      break;
    case 4:
      return;
    }
    if (menu_no_selected == 2)
      continue;

    std::cout << "Key in the menu number to go to" << '\n';
    menu_no_selected_2 = menu_selector_using_interger(1, max_menu);

    if (menu_no_selected == 1) {
      switch (menu_no_selected_2) {
      case 1:
        do {
          clear_screen();
          std::cout << "Key in the car model: " << '\n';
          to_search = string_to_upper(get_string_from_user_input());
          if (consist_alphabet_or_number_only(to_search))
            break;
          else {/* message */
            std::cerr << to_search << " -"
                      << "car model must be alphabet or number only" << '\n';
          }
        } while (to_search != "EXIT" && to_search != "-1");
        index_to_search = car_database.search_car_model_list(to_search);
        if (index_to_search == -1) {
          std::cerr << "The car model is not found." << '\n';
        }
        break;
      case 2:
        do {
          clear_screen();
          std::cout << "Key in the Index Number of the car: " << '\n';
          index_to_search =
              menu_selector_using_interger(1, car_database.length_of_list());
        } while (index_to_search == -99);
        index_to_search--;
        break;
      }
      if (index_to_search >= 0) {
        nodeType<car_model_type> *temp =
            car_database.get_car_model_type_by_index(index_to_search);
        temp->content.display();
        car_database.display_selected("car model", temp->content.getcar_model(),
                                      temp->content.getcar_model());
        std::cout << "Editing Instruction" << '\n';
        std::cout << "You are allowed to change the car model name and the rental prize only." << '\n';
        std::cout << "Key in 1 for car model name" << '\n';
        std::cout << "Key in 2 for car rental prize" << '\n';
        std::cout << "Key in 3 for going back to last menu" << '\n';
        std::cout << "Key in the menu number to go to" << '\n';
        menu_no_selected_2=menu_selector_using_interger(1,3);
        string to_change=car_edit(menu_no_selected_2*2,car_database);
        if(to_change != "EXIT" && to_change != "-1")
          {switch (menu_no_selected_2) {
            case 1:
            car_database.car_model_changes_car_model_in(temp->content.getcar_model(),to_change);
            temp->content.change_car_model(to_change);
            break;
            case 2:
            car_database.car_model_changes_rental_prize( temp->content.getcar_model(), stof(to_change));
            temp->content.change_rental_prize(stof(to_change));
            case 3:
            break;
          }
          write_2_file(car_database, filename_to_write);
        }

      }
    } else if (menu_no_selected == 3) {
      switch (menu_no_selected_2) {
      case 1:
        car_database.sort_car_model_list("car model");
        break;
      case 2:
        car_database.sort_car_model_list("rental prize");
        break;
      case 3:
        car_database.sort_car_model_list("rental day");
        break;
      case 4:
        car_database.sort_car_model_list("rental sales");
        break;
      }
      car_database.display_car_model();
    }

    pause();
  } while (menu_no_selected != -1);
}

void menu2(car_info_list &car_database, string filename_to_write) {
  while (true) {
    clear_screen();
    std::cout << "Display/Edit Car Info & Booking Info Menu" << '\n';
    std::cout << "1. Display All" << '\n';
    std::cout << "2. Display Selected" << '\n';
    std::cout << "3. Edit/Delete Car Infomation + Add Booking Info" << '\n';
    std::cout << "4. Car Model Summary" << '\n';
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
      generate_report(car_database,filename_to_write);
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
        input_min = string_to_upper(get_string_from_user_input());
        switch (menu_no_selected_2) {
        case 1:
          if (consist_alphabet_or_number_only(input_min))
            validation = 1;
          else
            std::cerr
                << input_min << " -"
                << "the input must be an alphabet or a number only"
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
      } while (input_min != "EXIT" && input_min != "-1" && validation == 0);
      if (menu_no_selected_3 == 1) {
        input_max = input_min;
      } else if (menu_no_selected_3 == 2) {
        validation = 0;
        do {
          std::cout << "Key in the maximum value: " << '\n';
          input_max = string_to_upper(get_string_from_user_input());
          switch (menu_no_selected_2) {
          case 1:
            if (consist_alphabet_or_number_only(input_max))
              validation = 1;
            else
              std::cerr
                  << input_max << " -"
                  << "the input must be an alphabet or a number only"
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
        } while (input_max != "EXIT" && input_max != "-1" && validation == 0);
      }
      if (input_max == "EXIT" && input_max == "-1")
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
          std::cout << "Key in the Plate No. of the car: " << '\n';
          input_1 = string_to_upper(get_string_from_user_input());
          if (validation_for_plate_number(input_1))
            break;
          else {
            std::cerr
                << input_1 << " -"
                << "plate number must be alphabet and at least one number only"
                << '\n';
          }
        } while (input_1 != "EXIT" && input_1 != "-1");
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
      write_2_file(car_database, filename_to_write);
    }
    pause();
  }
}

int main() {
  car_info_list car_database;
  queue<string> car_info_raw;
  string filename_to_read;
  string filename_to_write = "car.txt";
  string plate_no, car_model, color;
  float rental_prize_float = 0;
  while (true) {
    clear_screen();
    std::cout << "Penang-Car-to-Rent" << '\n';
    std::cout << "Main menu" << '\n';
    std::cout << "1. Add Car Info Through Files" << '\n';
    std::cout << "2. Add Car Info Through Keyboard" << '\n';
    std::cout << "3. Display/Edit Car Info & Booking Info Menu" << '\n';
    std::cout << "4. Change the filename to save to. Current save to: "
              << filename_to_write << '\n';
    std::cout << "5. EXIT" << '\n';
    std::cout << "Key in the menu number to go to" << '\n';
    int menu_no_selected = menu_selector_using_interger(1, 4);
    switch (menu_no_selected) {
    case 1:
      std::cout << "Key In the file name: " << '\n';
      filename_to_read = get_string_from_user_input();
      filename_to_read = text_file_format(filename_to_read);
      if (filename_to_read != "invalid") {
        std::cout << "Reading file: " << filename_to_read << '\n';
        read_raw_info(car_info_raw, filename_to_read);
        extract_car_info_from_raw(car_database, car_info_raw);
      } else {
        std::cerr << "The fileformat is invalid... (*.txt or *)" << '\n';
      }
      pause();
      break;
    case 2:
      clear_screen();
      std::cout << "Keyboard Mode" << '\n';
      for (int i = 1; i < 5; i++) {
        string temp = car_edit(i, car_database);
        if (temp == "-1" || temp == "EXIT") {
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
      menu2(car_database, filename_to_write);
      write_2_file(car_database, filename_to_write);
      break;
    case 4:
      std::cout << "Key In the file name to save to (Default: car.txt): "
                << '\n';
      filename_to_read = get_string_from_user_input();
      filename_to_read = text_file_format(filename_to_read);
      if (filename_to_read != "invalid") {
        filename_to_write = filename_to_read;
      } else {
        std::cerr << "The fileformat is invalid... (*.txt or *)" << '\n';
      }
      break;
    case 5:
      write_2_file(car_database, filename_to_write);
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

void draw_line(display_item* display_measurement,string line){
  int total_length_of_line=5;
  total_length_of_line+=display_measurement->max_length_of_list_no;
  total_length_of_line+=display_measurement->max_length_of_plate_no = 14;
  total_length_of_line+=display_measurement->max_length_of_car_model = 20;
  total_length_of_line+=display_measurement->max_length_of_colour = 12;
  total_length_of_line+=display_measurement->max_length_of_rental_prize = 25;
  total_length_of_line+=display_measurement->max_length_of_rental_day = 12;
  total_length_of_line+=display_measurement->max_length_of_rental_sales = 16;
  for (int i = 0; i < total_length_of_line; i++) {
    std::cout << line;
  }
  std::cout << '\n';
}

string car_edit(int i, car_info_list &car_database) {
  // To edit car infomation: 1 for plate number ; 2 for car model; 3 for car
  // colour ; 4 for car rental prize ; 5 for car rental day
  string to_change;
  switch (i) {
  case 1: // plate no.
    do {
      std::cout << "The car plate number: " << '\n';
      to_change = string_to_upper(get_string_from_user_input());
      if (validation_for_plate_number(to_change))
        break;
      else
        std::cout << "Please try again." << '\n';
    } while (to_change != "EXIT" && to_change != "-1");
    if (car_database.search(to_change) != -1) {
      std::cout << "The same car plate number is in the database." << '\n';
      to_change = "-1";
    }
    break;
  case 2: // car model
    do {
      std::cout << "The car model: " << '\n';
      to_change = string_to_upper(get_string_from_user_input());
      if (validation_for_alphabet(to_change))
        break;
      else
        std::cout << "Please try again." << '\n';
    } while (to_change != "EXIT" && to_change != "-1");
    break;
  case 3: // car colour
    do {
      std::cout << "The car colour: " << '\n';
      to_change = string_to_upper(get_string_from_user_input());
      if (validation_for_alphabet(to_change))
        break;
      else
        std::cout << "Please try again." << '\n';
    } while (to_change != "EXIT" && to_change != "-1");
    break;
  case 4: // rental prize
    do {
      std::cout << "The car rental prize: " << '\n';
      to_change = string_to_upper(get_string_from_user_input());
      if (validation_for_deciaml_number(to_change))
        break;
      else
        std::cout << "Please try again." << '\n';
    } while (to_change != "EXIT" && to_change != "-1");
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
    return;
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
  if (!isalnum(input.at(input.length() - 1))) {
    cout << input << ' ' << input.at(input.length() - 1) << endl;
    while (!isalnum(input.at(input.length() - 1))) {
      input.erase(input.length() - 1, 1);
    }
  }
}

string string_to_upper(string input){
  string temp;
  for (unsigned int i = 0; i < input.length(); i++){
    temp += toupper(input.at(i));
  }
  return temp;
}

bool consist_alphabet_or_number(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if (isalnum(input.at(i))) // check for digit & alphabet
      return true;
  }
  return false;
}

bool consist_alphabet_or_number_only(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if (!(isalnum(input.at(i))||isblank(input.at(i)))) // check for digit & alphabet
      return false;
  }
  return true;
}

bool validation_for_deciaml_number(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if ((!isdigit(input.at(i)) &&
         (input.at(i) != '.'))) // check for digit&decimal point
      return false;
  }
  if (stof(input) >= 0)
    return true;
  else
    return false;
}

bool validation_for_alphabet(const std::string input) {
  for (unsigned int i = 0; i < input.length(); i++) // check one by one.
  {
    if (!(isalpha(input.at(i)) || isblank(input.at(i)))) // check for alphabet
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

string text_file_format(std::string input) {
  if (consist_alphabet_or_number_only(input)) {
    return input + ".txt";
  }
  string temp = input.substr(input.length() - 4, 4);
  if (temp == ".txt") {
    return input;
  }
  return "invalid";
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
    line=string_to_upper(line);
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
        color = "NO INFO";
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
        std::cout << plate_no << endl;
        rental_prize_float = stof(rental_prize);
        std::cout << "rental prize is converted into float" << '\n';
        car_database.insert_car(plate_no, car_model, color, rental_prize_float);
        std::cout << "Insert into Database Finished" << '\n';
        draw_line(car_database.get_display_measurement(),"-");
      }
    }
    raw_info.delQueue();
  }
  return;
}

void write_2_file(car_info_list &car_database, string filename) {
  std::cout << "Saving into file named: " << filename << '\n';
  std::ofstream writefile(filename, std::ios::trunc);
  if (writefile.is_open()) {
    car_database.sort_car_info_list("default");
    nodeType<car_info> *current = car_database.get_car_by_index(0);
    while (current != NULL) {
      writefile << current->content.getplat_no() << ", "
                << current->content.getcar_model() << ", "
                << current->content.getcar_color() << ", "
                << current->content.getrental_prize() << endl;
      current = current->next_node;
    }
    writefile << endl;
    writefile.close();
  }
}
