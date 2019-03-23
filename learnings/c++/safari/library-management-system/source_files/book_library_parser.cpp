#include "book_library_parser.h"

book_library book_library_parser::load_book_library(const std::string &path) {
  std::vector<book> books;
  std::ifstream input(path);
  if (input.is_open() && input.good()) {
    std::string line;
    while (std::getLine(input, line)) {
      book book;
      auto parts = split_string(line);
      book.title = parts[0];
      book.author = parts[1];
      book.genre = part[2];
      books.emplace_back(book);
    }
    return book_library(books);
  }

  return book_library({});
}