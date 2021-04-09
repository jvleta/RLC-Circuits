#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "circuits.h"

struct MainMenuOption {
  int choice_index{};
  const std::string choice_name{};
  std::function<void()> processing_function;
};

struct MenuOption {
  int choice_index{};
  const std::string choice_name{};
  std::function<Circuit*()> processing_function;
};

void CreateNewCircuitMenu() {
  std::vector<MenuOption> main_menu_options{
      {1, "Create RC Circuit",
       []() {
         double r = 1.0;
         double c = 1.0;
         return Circuit::make_RC_circuit(r, c);
         std::cout << "\n";
       }},
      {2, "Create LC Circuit",
       []() {
         double l = 1.0;
         double c = 1.0;
         return Circuit::make_LC_circuit(l, c);
         std::cout << "\n";
       }},
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
      auto input = InputValues();
      // TODO: circuit objects need to be able to subscribe
      //       to InputValues object.
      break;
    }
  }
}

void MainMenu() {
  std::vector<MainMenuOption> menu_options{
      {1, "Create new Circuit", []() { CreateNewCircuitMenu(); }},
      {2, "Quit", []() { std::exit(EXIT_SUCCESS); }}};

  std::cout << "What woud you like to do?\n";
  for (const auto& option : menu_options) {
    std::cout << option.choice_index << " " << option.choice_name << "\n";
  }
  while (true) {
    std::cout << "Enter option:\n";
    int value{};
    std::cin >> value;
    std::cout << "You entered " << value << "\n";
    auto result =
        std::find_if(menu_options.begin(), menu_options.end(),
                     [&](auto opt) { return opt.choice_index == value; });
    if (result == menu_options.end()) {
      std::cout << "invalid option\n";
    } else {
      result->processing_function();
      break;
    }
  }
}
