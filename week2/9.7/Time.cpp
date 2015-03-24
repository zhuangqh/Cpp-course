#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;
Time::Time() {
  hour = minute = second = 0;
}
Time::Time(int h, int m, int s) {
  setTime(h, m, s);
}
void Time::tick() {
  second++;
  if (second >= 60) {
    minute++;
    second %= 60;
  }
  if (minute >= 60) {
    hour++;
    minute %= 60;
  }
  hour %= 24;
  printStandard();
}
void Time::setTime(int h, int m, int s) {
  if (h >= 0 && h <= 24) {
    hour = h;
  } else {
    cout << "The value of hour is invaild." << endl
      << "It was set to 12." << endl;
  }
  if (m >= 0 && m <= 60) {
    minute = m;
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
void Time::printUniversal() {
  cout << setfill('0') << setw(2) << hour << ":"
    << setw(2) << minute << ":" << setw(2) << second << endl;
}
void Time::printStandard() {
  cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
    << ":" << setfill('0') << setw(2) << minute
    << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") << endl;
}
