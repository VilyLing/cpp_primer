#pragma once
#include "Sales_data.h"
#include <iostream>
#include <string>

class Sales_data {
  friend Sales_data add(Sales_data const &lhs, Sales_data const &rhs);
  friend std::istream &read(std::istream &is, Sales_data &item);
  friend std::ostream &print(std::ostream &os, Sales_data const &item);

public:
  // 委托构造函数
  Sales_data(std::string const &s, unsigned n, double price)
      : bookNo(s), units_sold(n), revenue(price * n) {
    std::cout << "委托构造函数:" << std::endl;
  }

  Sales_data() : Sales_data("", 0, 0) {
    std::cout << "Sales_data()" << std::endl;
  }

  // explicit 
  Sales_data(std::string const &s) : Sales_data(s, 0, 0) {
    std::cout << "Sales_data(string const &s)" << std::endl;
  }

  explicit Sales_data(std::istream &is) : Sales_data() {
    std::cout << "Sales_data(istream&)" << std::endl;
    read(is, *this);
  }

public:
  std::string isbn() const { return bookNo; }
  Sales_data &combine(Sales_data const &item);

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0;

  inline double avg_price() const {
    return units_sold ? (revenue / units_sold) : 0;
  }
};

Sales_data add(Sales_data const &lhs, Sales_data const &rhs);

std::istream &read(std::istream &is, Sales_data &item);

std::ostream &print(std::ostream &os, Sales_data const &item);