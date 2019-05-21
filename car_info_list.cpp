//
//  car_info_list.cpp
//  A2_CPT113
//
//  Created by <author> on 17/05/2019.
//
//

#include "car_info_list.hpp"

car_info_list::car_info_list() : ordered_linked_list<car_info>() {
  display_measurement = new display_item;
  car_model_list.set_display_item(display_measurement);
}

car_info_list::~car_info_list() {}

void car_info_list::insert_car(string plat_no_in, string car_model_in,
                               string color_in, float rental_prize_in) {
  insert_car(car_info(plat_no_in, car_model_in, color_in, rental_prize_in));
}

void car_info_list::insert_car(car_info content) {
  std::cout << "Going to Insert car info into the database." << '\n';
  int temp =
      during_insert_car_model(content.getcar_model(), content.getrental_prize(),
                              content.getrental_day());
  std::cout << content.getcar_model()<< " rental prize in database: RM"<<temp
            << '\n';
  content.change_rental_prize(temp);
  std::cout << "Rental Prize Checked." << '\n';
  sort_car_info_list(sorted_mode);
  content.set_display_item(display_measurement);
  ordered_linked_list::insert_item(content);
  if (((int)content.getplat_no().length() + 2) >
      display_measurement->max_length_of_plate_no) {
    display_measurement->max_length_of_plate_no =
        content.getplat_no().length() + 2;
  }
}

float car_info_list::during_insert_car_model(string car_model_in,
                                             float rental_prize_in,
                                             int rental_day_in) {
  int index = car_model_list.binary_search(car_model_type(car_model_in));
  cout << "Matching Car Model with the Car Model in the database. "
       << car_model_in << " " << index << endl;
  if (index == -1) {
    car_model_type content(car_model_in, rental_prize_in, rental_day_in);
    content.set_display_item(display_measurement);
    car_model_list.insert_item(content);
    if (((int)car_model_in.length() + 2) >
        display_measurement->max_length_of_car_model) {
      display_measurement->max_length_of_car_model = car_model_in.length() + 2;
    }
  } else {
    nodeType<car_model_type> *temp;
    temp = car_model_list.get_item_by_index(index);
    if (rental_prize_in != temp->content.getrental_prize()) {
      std::cerr
          << "The rental prize of the car is not the same as in the database."
          << '\n';
      std::cerr << "Changing the input data " << rental_prize_in << " to "
                << temp->content.getrental_prize() << '\n';
      rental_prize_in = temp->content.getrental_prize();
    }
    temp->content.add_rental_day(rental_day_in);
    temp->content.change_count(1);
    std::cout << "Model Car Search Found and Compare rental prize" << '\n';
  }
  return rental_prize_in;
}

void car_info_list::edit_car(string plat_no_in, string car_model_in,
                             string color_in, float rental_prize_in,
                             int rental_day_in) {
  std::cout << "Start editing "<< plat_no_in << '\n';
  nodeType<car_info> *temp = get_item(car_info(plat_no_in));
  if (temp->content.getrental_day() != rental_day_in) {
    car_model_list.get_item(car_model_type(car_model_in))
        ->content.change_rental_prize(rental_day_in -
                                      temp->content.getrental_day());
  } else if (temp->content.getcar_model() != car_model_in) {
    nodeType<car_model_type> *model_temp =
        car_model_list.get_item(car_model_type(temp->content.getcar_model()));
    model_temp->content.change_rental_prize(-temp->content.getrental_day());
    model_temp->content.change_count(-1);
    rental_prize_in =
        during_insert_car_model(car_model_in, rental_prize_in, rental_day_in);
  }
  temp->content.change(plat_no_in, car_model_in, color_in, rental_prize_in,
                       rental_day_in);
}

void car_info_list::car_model_changes_rental_prize(string car_model_in,
                                                   float rental_prize_in) {
  nodeType<car_model_type> *temp;
  temp = car_model_list.get_item(car_model_type(car_model_in));
  temp->content.change_rental_prize(rental_prize_in);
  sort_car_info_list("car model");
  nodeType<car_info> *current = first_node;
  while (current->content.getcar_model() != car_model_in) {
    current = current->next_node;
  }
  while (current->content.getcar_model() == car_model_in) {
    current->content.change_rental_prize(rental_prize_in);
    current = current->next_node;
  }
  sort_car_info_list("default");
}

void car_info_list::car_model_changes_car_model_in(string car_model_ori,string car_model_change) {
  sort_car_info_list("car model");
  nodeType<car_info> *current = first_node;
  while (current->content.getcar_model() != car_model_ori) {
    current = current->next_node;
  }
  while (current->content.getcar_model() == car_model_ori) {
    current->content.change(current->content.getplat_no(), car_model_change, current->content.getcar_color(),current->content.getrental_prize() , current->content.getrental_day());
    current = current->next_node;
  }
  sort_car_info_list("default");
}

void car_info_list::delete_car(string plate_no) {
  sort_car_info_list("default");
  nodeType<car_info> *temp;
  temp = ordered_linked_list::get_item(car_info(plate_no));
  nodeType<car_model_type> *model_temp =
      car_model_list.get_item(car_model_type(temp->content.getcar_model()));
  model_temp->content.change_count(-1);
  model_temp->content.add_rental_day(-1 * temp->content.getrental_day());
  model_temp->content.change_rental_prize(-temp->content.getrental_day());
  ordered_linked_list::delete_item(car_info(plate_no));
}

void car_info_list::delete_car(int index) {
  sort_car_info_list("default");
  nodeType<car_info> *temp;
  temp = ordered_linked_list::get_item_by_index(index);
  nodeType<car_model_type> *model_temp =
      car_model_list.get_item(car_model_type(temp->content.getcar_model()));
  model_temp->content.change_count(-1);
  model_temp->content.add_rental_day(-1 * temp->content.getrental_day());
  model_temp->content.change_rental_prize(-temp->content.getrental_day());
  ordered_linked_list::delete_index(index);
}

comparingNodeType<string, nodeType<car_info> *> *car_info_list::sort_inoder(
    comparingNodeType<string, nodeType<car_info> *> *current) {
  comparingNodeType<string, nodeType<car_info> *> *temp = current;
  if (current != NULL) {
    if (current->left != NULL) {
      temp = sort_inoder(current->left);
      temp->content->next_node = current->content;
    }
    if (current->right != NULL) {
      temp = current->right;
      if (current->right->left != NULL) {
        while (temp->left != NULL) {
          temp = temp->left;
        }
      }
      current->content->next_node = temp->content;
      temp = sort_inoder(current->right);
      return temp;
    }
    return current;
  }
  return NULL;
}

void car_info_list::sort_car_info_list(string mode) {
  if (mode == sorted_mode)
    return;

  binary_tree_sorting<string, nodeType<car_info> *> sorting;
  nodeType<car_info> *current = first_node;
  if (mode == "default" || mode == "plate no") {
    sorted_mode = "default";
    while (current != NULL) {
      sorting.insert(current->content.getplat_no(), current);
      current = current->next_node;
    }
  } else if (mode == "car model") {
    sorted_mode = "car model";
    while (current != NULL) {
      sorting.insert(current->content.getcar_model() +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  } else if (mode == "color") {
    sorted_mode = "color";
    while (current != NULL) {
      sorting.insert(current->content.getcar_color() +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  } else if (mode == "rental prize") {
    sorted_mode = "rental prize";
    while (current != NULL) {
      sorting.insert(to_string(int(current->content.getrental_prize() * 100)) +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  } else if (mode == "rental day") {
    sorted_mode = "rental day";
    while (current != NULL) {
      sorting.insert(to_string(current->content.getrental_day()) +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  } else if (mode == "rental sales") {
    sorted_mode = "rental sales";
    while (current != NULL) {
      sorting.insert(to_string(int(current->content.getrental_sales() * 100)) +
                         current->content.getplat_no(),
                     current);
      current = current->next_node;
    }
  } else {
    std::cerr << "invalid sorting method" << '\n';
    return;
  }
  comparingNodeType<string, nodeType<car_info> *> *root =
      sorting.get_root(); // get the root for the binary tree.
  sort_inoder(root);
  comparingNodeType<string, nodeType<car_info> *> *temp = root;
  // Getting the first node of the new sorted linked list.
  while (temp->left != NULL) {
    temp = temp->left;
  }
  first_node = temp->content;
  temp = root;
  // Getting the last node of the new sorted linked list.
  while (temp->right != NULL) {
    temp = temp->right;
  }
  last_node = temp->content;
  last_node->next_node = NULL;
}

nodeType<car_info> *car_info_list::get_car_by_index(int index) {
  return ordered_linked_list::get_item_by_index(index);
}
nodeType<car_info> *car_info_list::get_car(car_info to_search) {
  return ordered_linked_list::get_item(to_search);
}

nodeType<car_model_type> *
car_info_list::get_car_model_type_by_index(int index) {
  return car_model_list.get_item_by_index(index);
}

int car_info_list::length_of_list() {
  return ordered_linked_list::length_of_list();
}

int car_info_list::search(string plate_no_in) {
  return ordered_linked_list::binary_search(car_info(plate_no_in));
}

int car_info_list::search_car_model_list(string to_search) {
  return car_model_list.binary_search(car_model_type(to_search));
}

void car_info_list::table_form_display(string section, car_info total,
                                       int count) {
  if (section == "header") {
    cout << setw(display_measurement->max_length_of_list_no) << "No." << '|'
         << setw(display_measurement->max_length_of_car_model) << "Car Model"
         << '|' << setw(display_measurement->max_length_of_plate_no)
         << "Plat No" << '|' << setw(display_measurement->max_length_of_colour)
         << "Color" << '|'
         << setw(display_measurement->max_length_of_rental_prize)
         << "Rental Prize(RM)(Average)" << '|'
         << setw(display_measurement->max_length_of_rental_day) << "Rental Days"
         << '|' << setw(display_measurement->max_length_of_rental_sales)
         << "Rental Sales(RM)" << '|' << endl;
    return;
  } else if (section == "footer") {
    cout << setw(display_measurement->max_length_of_list_no) << count << '|'
         << setw(display_measurement->max_length_of_car_model) << "  " << '|'
         << setw(display_measurement->max_length_of_plate_no) << "<---Total--->"
         << '|' << setw(display_measurement->max_length_of_colour) << "  "
         << '|' << setw(display_measurement->max_length_of_rental_prize)
         << total.getrental_prize() / count << '|'
         << setw(display_measurement->max_length_of_rental_day)
         << total.getrental_day() << '|'
         << setw(display_measurement->max_length_of_rental_sales)
         << total.getrental_sales() << '|' << endl;
  }
}

void car_info_list::table_form_display(string section, car_model_type total,
                                       int count) {
  if (section == "header") {
    cout << setw(display_measurement->max_length_of_list_no) << "No." << '|'
         << setw(display_measurement->max_length_of_car_model) << "Car Model"
         << '|' << setw(display_measurement->max_length_of_rental_prize)
         << "Rental Prize(RM)(Average)" << '|'
         << setw(display_measurement->max_length_of_rental_day) << "Rental Days"
         << '|' << setw(display_measurement->max_length_of_rental_sales)
         << "Rental Sales(RM)" << '|' << endl;
  } else if (section == "footer") {
    cout << setw(display_measurement->max_length_of_list_no) << count << '|'
         << setw(display_measurement->max_length_of_car_model)
         << "<---Total--->" << '|'
         << setw(display_measurement->max_length_of_rental_prize)
         << total.getrental_prize() / count << '|'
         << setw(display_measurement->max_length_of_rental_day)
         << total.getrental_day() << '|'
         << setw(display_measurement->max_length_of_rental_sales)
         << total.getrental_sales() << '|' << endl;
  }
}

void car_info_list::display() {
  table_form_display("header", car_info(), 0);
  ordered_linked_list::display();
  car_info total = sum_of_all();
  table_form_display("footer", total, length_of_list());
}

void car_info_list::display_selected(string mode, string to_search_min,
                                     string to_search_max) {
  int count = 0;
  car_info total;
  sort_car_info_list(mode);
  nodeType<car_info> *current_node;
  compare_string comparing_string;
  if (mode == "plate no") {
    current_node = first_node;
    while (!comparing_string.larger_equal(current_node->content.getplat_no(),
                                          to_search_min) &&
           current_node != NULL)
      current_node = current_node->next_node;
    table_form_display("header", car_info(), 0);
    while (comparing_string.smaller_equal(current_node->content.getplat_no(),
                                          to_search_max) &&
           current_node != NULL) {
      cout << setw(display_measurement->max_length_of_list_no) << left << count
           << current_node->content << endl;
      total = total + current_node->content;
      count++;
      if (current_node->next_node == NULL)
        break;
      current_node = current_node->next_node;
    }
  } else if (mode == "car model") {
    current_node = first_node;
    while (!comparing_string.larger_equal(current_node->content.getcar_model(),
                                          to_search_min) &&
           current_node != NULL)
      current_node = current_node->next_node;
    if (current_node != NULL) {
      table_form_display("header", car_info(), 0);
      while (comparing_string.smaller_equal(
          current_node->content.getcar_model(), to_search_max)) {
        cout << setw(display_measurement->max_length_of_list_no) << left
             << count << current_node->content << endl;
        total = total + current_node->content;
        count++;
        if (current_node->next_node == NULL)
          break;
        current_node = current_node->next_node;
      }
    }
  } else if (mode == "color") {
    current_node = first_node;
    while (!comparing_string.larger_equal(current_node->content.getcar_color(),
                                          to_search_min) &&
           current_node != NULL)
      current_node = current_node->next_node;
    if (current_node != NULL) {
      table_form_display("header", car_info(), 0);
      while (comparing_string.smaller_equal(
          current_node->content.getcar_color(), to_search_max)) {
        cout << setw(display_measurement->max_length_of_list_no) << left
             << count << current_node->content << endl;
        total = total + current_node->content;
        count++;
        if (current_node->next_node == NULL)
          break;
        current_node = current_node->next_node;
      }
    }
  } else if (mode == "rental prize") {
    current_node = first_node;
    while (current_node->content.getrental_prize() < stof(to_search_min) &&
           current_node != NULL)
      current_node = current_node->next_node;
    if (current_node != NULL) {
      table_form_display("header", car_info(), 0);
      while (current_node->content.getrental_prize() <= stof(to_search_max)) {
        cout << setw(display_measurement->max_length_of_list_no) << left
             << count << current_node->content << endl;
        total = total + current_node->content;
        count++;
        if (current_node->next_node == NULL)
          break;
        current_node = current_node->next_node;
      }
    }
  } else if (mode == "rental day") {
    current_node = first_node;
    while (current_node->content.getrental_day() < stoi(to_search_min) &&
           current_node != NULL)
      current_node = current_node->next_node;
    if (current_node != NULL) {
      table_form_display("header", car_info(), 0);
      while (current_node->content.getrental_day() <= stoi(to_search_max)) {
        cout << setw(display_measurement->max_length_of_list_no) << left
             << count << current_node->content << endl;
        total = total + current_node->content;
        count++;
        if (current_node->next_node == NULL)
          break;
        current_node = current_node->next_node;
      }
    }
  } else if (mode == "rental sales") {
    current_node = first_node;
    while (current_node->content.getrental_sales() < stof(to_search_min) &&
           current_node != NULL)
      current_node = current_node->next_node;
    if (current_node != NULL) {
      table_form_display("header", car_info(), 0);
      while (current_node->content.getrental_sales() <= stof(to_search_max)) {
        cout << setw(display_measurement->max_length_of_list_no) << left
             << count << current_node->content << endl;
        total = total + current_node->content;
        count++;
        if (current_node->next_node == NULL)
          break;
        current_node = current_node->next_node;
      }
    }
  } else {
    std::cerr << "There is nothing within the range given." << '\n';
    return;
  }
  table_form_display("footer", total, count);
}

void car_info_list::display_car_model() {
  table_form_display("header", car_model_type(), 0);
  car_model_list.display();
  car_model_type total = sum_of_all_car_model();
  table_form_display("footer", total, car_model_list.length_of_list());
}

comparingNodeType<string, nodeType<car_model_type> *> *
car_info_list::sort_inoder(
    comparingNodeType<string, nodeType<car_model_type> *> *current) {
  comparingNodeType<string, nodeType<car_model_type> *> *temp = current;
  if (current != NULL) {
    if (current->left != NULL) {
      temp = sort_inoder(current->left);
      temp->content->next_node = current->content;
    }
    if (current->right != NULL) {
      temp = current->right;
      if (current->right->left != NULL) {
        while (temp->left != NULL) {
          temp = temp->left;
        }
      }
      current->content->next_node = temp->content;
      temp = sort_inoder(current->right);
      return temp;
    }
    return current;
  }
  return NULL;
}

void car_info_list::sort_car_model_list(string mode) {
  if (mode == car_model_list_sorted_mode)
    return;
  binary_tree_sorting<string, nodeType<car_model_type> *> sorting;
  nodeType<car_model_type> *current = car_model_list.get_item_by_index(0);
  if (mode == "default" || mode == "car model") {
    car_model_list_sorted_mode = "car model";
    while (current != NULL) {
      sorting.insert(current->content.getcar_model(), current);
      current = current->next_node;
    }
  } else if (mode == "rental prize") {
    car_model_list_sorted_mode = "rental prize";
    while (current != NULL) {
      sorting.insert(to_string(current->content.getrental_prize() * 100) +
                         current->content.getcar_model(),
                     current);
      current = current->next_node;
    }
  } else if (mode == "rental day") {
    car_model_list_sorted_mode = "rental day";
    while (current != NULL) {
      sorting.insert(to_string(current->content.getrental_day()) +
                         current->content.getcar_model(),
                     current);
      current = current->next_node;
    }
  } else if (mode == "rental sales") {
    car_model_list_sorted_mode = "rental sales";
    while (current != NULL) {
      sorting.insert(to_string(current->content.getrental_sales() * 100) +
                         current->content.getcar_model(),
                     current);
      current = current->next_node;
    }
  } else {
    std::cerr << "invalid sorting method" << '\n';
    return;
  }
  comparingNodeType<string, nodeType<car_model_type> *> *root =
      sorting.get_root(); // get the root for the binary tree.
  sort_inoder(root);
  comparingNodeType<string, nodeType<car_model_type> *> *temp = root;
  // Getting the first node of the new sorted linked list.
  while (temp->left != NULL) {
    temp = temp->left;
  }
  car_model_list.assign_first_node(temp->content);
  temp = root;
  // Getting the last node of the new sorted linked list.
  while (temp->right != NULL) {
    temp = temp->right;
  }
  car_model_list.assign_last_node(temp->content);
  temp->content->next_node = NULL;
}

car_info car_info_list::sum_of_all() {
  car_info total;
  nodeType<car_info> *current = get_item_by_index(0);
  while (current != NULL) {
    total = total + current->content;
    current = current->next_node;
  }
  if ((log10(total.getrental_prize()) + 4) >
      display_measurement->max_length_of_rental_prize) {
    display_measurement->max_length_of_rental_prize =
        log10(total.getrental_prize()) + 4;
  }
  if ((log10(total.getrental_day()) + 2) >
      display_measurement->max_length_of_rental_day) {
    display_measurement->max_length_of_rental_day =
        log10(total.getrental_day()) + 2;
  }
  if ((log10(total.getrental_sales()) + 4) >
      display_measurement->max_length_of_rental_sales) {
    display_measurement->max_length_of_rental_sales =
        log10(total.getrental_sales()) + 4;
  }
  return total;
}

car_model_type car_info_list::sum_of_all_car_model() {
  car_model_type total;
  nodeType<car_model_type> *current = car_model_list.get_item_by_index(0);
  while (current != NULL) {
    total = total + current->content;
    current = current->next_node;
  }
  if ((log10(total.getrental_prize()) + 4) >
      display_measurement->max_length_of_rental_prize) {
    display_measurement->max_length_of_rental_prize =
        log10(total.getrental_prize()) + 4;
  }
  if ((log10(total.getrental_day()) + 2) >
      display_measurement->max_length_of_rental_day) {
    display_measurement->max_length_of_rental_day =
        log10(total.getrental_day()) + 2;
  }
  if ((log10(total.getrental_sales()) + 4) >
      display_measurement->max_length_of_rental_sales) {
    display_measurement->max_length_of_rental_sales =
        log10(total.getrental_sales()) + 4;
  }
  return total;
}

display_item *car_info_list::get_display_measurement() {
  return display_measurement;
}
