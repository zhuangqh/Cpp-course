#include <iostream>
#include "Time.h"
using namespace std;
int main() {
  int clockValue[3][3] = { { 0, 0, 58 },
                           { 0, 59, 58 },
                           { 23, 59, 58 } };
  //create Time object
  Time clock;
  //display the time incrementing
  for (int i = 0; i < 3; ++i) {
    cout << "-----" << i + 1 << "-----" << endl;
    clock.setTime(clockValue[i][0], clockValue[i][1], clockValue[i][2]);
    for (int j = 0; j < 4; ++j) {
      clock.tick();
    }
  }
  return 0;
}
