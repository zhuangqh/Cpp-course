#include <iostream>
#include "Date.h"
using namespace std;
int main() {
  int clockValue[3][3] = { { 2, 28, 1996 },
                           { 2, 29, 1997 },
                           { 12, 31, 1996 } };
  //create Date object
  Date clock;
  //display the date incrementing
  for (int i = 0; i < 3; ++i) {
    cout << "-----" << i + 1 << "-----" << endl;
    clock.setDate(clockValue[i][0], clockValue[i][1], clockValue[i][2]);
    //now
    clock.print();
    //next day
    clock.nextDay();
    clock.print();
  }
  return 0;
}
