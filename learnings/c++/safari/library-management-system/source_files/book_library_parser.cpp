#include "book_library_parser.h"

book_library book_library_parser::load_book_library() {
  std::vector<book> books;
  for (auto i = 0; i < 10; i++) {
    book b;
    b.title = std::string("Title") + std::to_string(i + 1);
    b.author = std::string("Author") + std::to_string(i + 1);
    b.genre = "Fiction";
    books.emplace_back(b);
  }
  return book_library(books);
}