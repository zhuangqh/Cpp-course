#include "Date.h"
#include <sstream>

using std::string;
using std::stringstream;

Date::Date() {
  year_ = 2015;
  month_ = 7;
  day_ = 8;
  hour_ = 0;
  minute_ = 0;
}

Date::Date(int y, int m, int d, int h, int mi) {
  year_ = y;
  month_ = m;
  day_ = d;
  hour_ = h;
  minute_ = mi;
}

int Date::getYear() const {
  return year_;
}

void Date::setYear(int year) {
  year_ = year;
}

int Date::getMonth() const {
  return month_;
}

void Date::setMonth(int month) {
  month_ = month;
}

int Date::getDay() const {
  return day_;
}

void Date::setDay(int day) {
  day_ = day;
}

int Date::getHour() const {
  return hour_;
}

void Date::setHour(int hour) {
  hour_ = hour;
}

int Date::getMinute() const {
  return minute_;
}

void Date::setMinute(int minute) {
  minute_ = minute;
}

bool Date::isValid(Date date) {
    int year = date.getYear(),
        month = date.getMonth(),
        day = date.getDay(),
        hour = date.getHour(),
        minute = date.getMinute();

    if (year < 1000 || year > 9999) return false;
    if (month < 1 || month > 12) return false;
    if (hour < 0 || hour > 23) return false;
    if (minute < 0 || minute > 59) return false;

    int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31,
                              30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0))
        dayOfMonth[2] = 29;

    if (day < 0 || day > dayOfMonth[month]) return false;
    return true;
}

Date Date:: stringToDate(string dateString) {
  // convert string to date
  int time[5], temp = 0, count = 0;
  string::iterator it = dateString.begin();
  for (; it != dateString.end(); ++it) {
      if (it == --dateString.end()) {
          temp = temp * 10 + *it - '0';
          time[count] = temp;
          break;
      }
    if (*it == '-' || *it == '/' || *it == ':') {
      time[count++] = temp;
      temp = 0;
    } else {
      temp = temp * 10 + *it - '0';
    }
  }

  // assign value to date
  Date ans(time[0], time[1], time[2], time[3], time[4]);
  return ans;
}

string int2string(int n) {
    // n would only be xx or xxxx
    string ans;
    stringstream ss;
    ss << n;
    ss >> ans;
    if (ans.size() == 1) {
        ans[0] = '0';
        ans += n + '0';
    }

    return ans;
}

string Date::dateToString(Date date) {
    string ans;
    if (!isValid(date)) {
        return ans;
    }
    ans += int2string(date.getYear());
    ans += '-';
    ans += int2string(date.getMonth());
    ans += '-';
    ans += int2string(date.getDay());
    ans += '/';
    ans += int2string(date.getHour());
    ans += ':';
    ans += int2string(date.getMinute());
    return ans;
}

Date& Date::operator=(const Date& date) {
    year_ = date.getYear();
    month_ = date.getMonth();
    day_ = date.getDay();
    hour_ = date.getHour();
    minute_ = date.getMinute();
    return *this;
}

bool Date::operator==(const Date& date) const {
    if (year_ == date.getYear() && month_ == date.getMonth() &&
        day_ == date.getDay() && hour_ == date.getHour() &&
        minute_ == date.getMinute())
        return true;
    return false;
}

bool Date::operator>(const Date& date) const {
    if (year_ > date.getYear()) {
        return true;
    } else if (year_ == date.getYear()) {
        if (month_ > date.month_) {
            return true;
        } else if (month_ == date.getMonth()) {
            if (day_ > date.day_) {
                return true;
            } else if (day_ == date.getDay()) {
                if (hour_ > date.hour_) {
                    return true;
                } else if (hour_ == date.getHour()) {
                    if (minute_ > date.getMinute()) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Date::operator<(const Date& date) const {
    if (year_ < date.getYear()) {
        return true;
    } else if (year_ == date.getYear()) {
        if (month_ < date.month_) {
            return true;
        } else if (month_ == date.getMonth()) {
            if (day_ < date.day_) {
                return true;
            } else if (day_ == date.getDay()) {
                if (hour_ < date.hour_) {
                    return true;
                } else if (hour_ == date.getHour()) {
                    if (minute_ < date.getMinute()) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Date::operator>=(const Date& date) const {
  return !(*this < date);
}

bool Date::operator<=(const Date& date) const {
  return !(*this > date);
}
