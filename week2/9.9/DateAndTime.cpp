#include <iostream>
#include <iomanip>
#include "DateAndTime.h"
using namespace std;
DateAndTime::DateAndTime(int m, int d, int y, int h, int min, int s) {
  setDateAndTime(m, d, y, h, min, s);
}
void DateAndTime::setDateAndTime(int m, int d, int y, int h, int min, int s) {
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
  if (h >= 0 && h <= 24) {
    hour = h;
  } else {
    cout << "The value of hour is invaild." << endl
      << "It was set to 12." << endl;
  }
  if (min >= 0 && min <= 60) {
    minute = min;
  } else {
    cout << "The value of minute is invaild." << endl
      << "It was set to 0." << endl;
  }
  if (s >= 0 && s <= 60) {
    second = s;
  } else {
    cout << "The value of second is invaild." << endl
      << "It was set to 0." << endl;
  }
}
void DateAndTime::tick() {
  second++;
  if (second >= 60) {
    minute++;
    second %= 60;
  }
  if (minute >= 60) {
    hour++;
    if (hour == 24) nextDay();
    minute %= 60;
  }
  hour %= 24;
}
void DateAndTime::nextDay() {
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

void DateAndTime::printStandard() {
  cout << month << '/' << day << '/' << year << endl
    << ((hour == 0 || hour == 12) ? 12 : hour % 12)
    << ":" << setfill('0') << setw(2) << minute
    << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") << endl;
}
void DateAndTime::printUniversal() {
  cout << month << '/' << day << '/' << year << endl
    << setfill('0') << setw(2) << hour << ":"
    << setw(2) << minute << ":" << setw(2) << second << endl;
}
bool DateAndTime::isLeapYear() {
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
