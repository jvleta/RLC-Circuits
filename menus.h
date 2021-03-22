#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

#include "components.h"

struct MenuOption {
  int choice_index{};
  const std::string choice_name{};
  std::function<Circuit*()> processing_function;
};

void MainMenu() {
  std::vector<MenuOption> main_menu_options{
      // {1, "Create RC Circuit", []() { std::cout << "you want to do what?\n";
      // }},
      // {2, "Create LC Circuit", []() { std::cout << "\n"; }},
      {3, "Create RLC Circuit", []() {
         double r = 1.0;
         double l = 1.0;
         double c = 1.0;
         return Circuit::make_RLC_circuit(r, l, c);
         std::cout << "\n";
       }}};

  std::cout << "What woud you like to do?\n";
  for (const auto& option : main_menu_options) {
    std::cout << option.choice_index << " " << option.choice_name << "\n";
  }
  while (true) {
    std::cout << "Enter option:\n";
    int value{};
    std::cin >> value;
    std::cout << "You entered " << value << "\n";
    auto result =
        std::find_if(main_menu_options.begin(), main_menu_options.end(),
                     [&](auto opt) { return opt.choice_index == value; });
    if (result == main_menu_options.end()) {
      std::cout << "invalid option\n";
    } else {
      std::cout << "yoooo\n";
      Circuit* c = result->processing_function();
      break;
    }
  }
}
