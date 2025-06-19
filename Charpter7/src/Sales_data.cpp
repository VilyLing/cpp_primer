#include <iostream>
#include <istream>
#include <ostream>

#include "Sales_data.h"

using namespace std;

Sales_data &Sales_data::combine(Sales_data const &item) {
  units_sold += item.units_sold;
  revenue += item.revenue;
  return *this;
}

// Sales_data::Sales_data(istream &is) { read(is, *this); }

Sales_data add(Sales_data const &lhs, Sales_data  &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.bookNo << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}