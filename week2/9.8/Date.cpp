#include <iostream>
#include "Date.h"
using namespace std;
Date::Date(int m, int d, int y) {
  setDate(m, d, y);
}
void Date::setDate(int m, int d, int y) {
  if (m >= 1 && m <= 12) {
    month = m;
  } else {
    cout << "The value of month is invaild." << endl
      << "It was set to 1." << endl;
  }
  if (d >= 1 && d <= 31) {
    day = d;
  } else {
    cout << "The value of day is invaild." << endl
      << "It was set to 1." << endl;
  }
  if (y >= 0) {
    year = y;
  } else {
    cout << "The value of year is invaild." << endl
      << "It was set to 2000." << endl;
  }
}
void Date::print() {
  cout << month << '/' << day << '/' << year << endl;
}
bool Date::isLeapYear() {
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
void Date::nextDay() {
  int monthList[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
  if (isLeapYear()) monthList[1] = 29;
  ++day;
  if (day > monthList[month - 1]) {
    day = 1;
    ++month;
  }
  if (month > 12) {
    month = 1;
    ++year;
  }
}
