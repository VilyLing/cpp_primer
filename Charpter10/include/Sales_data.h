#pragma once
#include <iostream>
#include <istream>
#include <ostream>
#include <string>


class Sales_data {
public:
  Sales_data(const std::string &book, unsigned num, double price)
      : bookNo(book), units_sold(num), revenue(price * num) {}
  Sales_data(std::string const &book) : Sales_data(book, 0, 0.0) {}
  Sales_data() : Sales_data("", 0, 0.0) {}

public:
  std::string get_bookNo() const { return bookNo; }
  unsigned get_units_sold() const { return units_sold; }
  double get_revenue() const { return revenue; }

  std::ostream &print(std::ostream &os) const {
    os << "ISBN: " << bookNo << ", Units Sold: " << units_sold
       << ", Revenue: " << revenue;
    return os;
  }
private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.get_bookNo() < rhs.get_bookNo();
}

void practice10_12(){
        std::vector<Sales_data> data = {
        Sales_data("978-3-16-148410-0", 10, 29.99),
        Sales_data("978-1-60309-452-8", 5, 19.99),
        Sales_data("978-0-306-40615-7", 2, 39.99)
    };

    std::stable_sort(data.begin(), data.end(), [](Sales_data const & lhs , Sales_data const & rhs){
      return lhs.get_bookNo() < rhs.get_bookNo();
    });
    for (const auto &item : data) {
        item.print(std::cout);
        std::cout<<std::endl;
    }
}