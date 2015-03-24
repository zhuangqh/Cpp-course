#include <iostream>
#include "DateAndTime.h"
using namespace std;
int main() {
  //create DateAndTime object
  DateAndTime clock(2, 28, 1996, 23, 59, 58);
  //display the time incrementing
  for (int i = 0; i < 3; ++i) {
    cout << "-----------" << endl;
    clock.tick();
    //display the universal time
    clock.printUniversal();
    //display the standard time
    clock.printStandard();
  }
  return 0;
}
