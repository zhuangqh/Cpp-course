#include <iostream>
#include <iomanip>
#include <ctime>
#include "Time.h"
using namespace std;
Time::Time() {
  const time_t currentTime = time(NULL);
  const tm *localTime = localtime(&currentTime);
  setTime(localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}
Time::Time(int h, int m, int s) {
  hour = h;
  minute = m;
  second = s;
}
int Time::setTime(int h, int m, int s) {
  int errorMessage = 0;
  if (h >= 0 && h <= 24) {
    hour = h;
  } else {
    errorMessage += 1;
  }
  if (m >= 0 && m <= 60) {
    minute = m;
  } else {
    errorMessage += 2;
  }
  if (s >= 0 && s <= 60) {
    second = s;
  } else {
    errorMessage += 4;
  }
  return errorMessage;
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
