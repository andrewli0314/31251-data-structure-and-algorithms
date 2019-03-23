#include "application.h"
#include <iostream>

bool application::continue_running() {
  std::cout << "Anything else? (Y/N)";
  char response;
  std::cin >> response;
  return response == 'Y' || response == 'y';
}

char application::get_action() {
  std::cout << "What would you like to do next? (choose 1): " << std::endl;
  std::cout << "1 (show books)" << std::endl;
  std::cout << "2 (sort books)" << std::endl;
  std::cout << "3 (search book by title)" << std::endl;
  std::cout << "4 (search books by author)" << std::endl;
  char action;
  std::cin >> action;
}

application::app_action application::get_action_input(char input) {
  switch (input) {
    case 1:
      return app_action::none;
      break;
    case 2:
      return app_action::sort;
      break;
    case 3:
      return app_action::search_book;
      break;
    case 4:
      return app_action::search_author;
      break;

    default:
      return app_action::none;
      break;
  }
}