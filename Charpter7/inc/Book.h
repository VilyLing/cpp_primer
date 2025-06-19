#pragma once

#include <istream>
#include <string>

class Book {

public:
  // 委托构造函数
  Book(std::string const &bookName, std::string const &author,
       std::string const &pubilsh, std::string const &isbn, double const price)
      : bookName(bookName), author(author), publish(pubilsh), isbn(isbn),
        price(price) {}

  Book() : Book("", "", "", "", 0) {}
  Book(std::string const &name) : Book(name, "", "", "", 0) {}
  Book(std::string const &name, std::string const &author)
      : Book(name, author, "", "", 0) {}
  Book(std::string const &name, std::string const &author,
       std::string const &publish)
      : Book(name, author, publish, "", 0) {}
  Book(std::string const &name, std::string const &author,
       std::string const &publish, std::string const &isbn)
      : Book(name, author, publish, isbn, 0) {}
  Book(std::istream &is) : Book() { read(is, *this); }

public:
    inline std::istream &read(std::istream &is, Book &b) {
    is >> b.bookName >> b.author >> b.publish >> b.isbn >> b.price;
    return is;
  }

private:
  std::string bookName;
  std::string author;
  std::string publish;
  std::string isbn;
  double price;
};