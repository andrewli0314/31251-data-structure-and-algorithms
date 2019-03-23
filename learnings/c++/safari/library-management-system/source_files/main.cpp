#include <iostream>
#include <iterator>
#include <vector>
#include "application.h"
#include "book_library_parser.h"

void print_books(std::vector<book> &books) {
  std::copy(books.begin(), books.end(),
            std::ostream_iterator<book>(std::cout, "\n"));
}

int main() {
  std::cout << "--------- Book Library -------" << std::endl;
  application app;
  book_library_parser parser;

  //   Load our library
  auto library = parser.load_book_library();
  do {
    // get user input
    auto input = app.get_action();
    auto action = app.get_action_input(input);

    switch (action) {
      case application::app_action::none:
        if (input == '1') print_books(library.books());
        break;
      case application::app_action::sort:
        auto sorted_books = library.sort_books();
        print_books(sorted_books);
        break;
      default:
        break;
    }

  } while (app.continue_running());

  return 0;
}