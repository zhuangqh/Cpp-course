#include <iostream>
#include "Time.h"
using namespace std;
int main() {
  //create Time object
  Time clock;
  //print the current time
  cout << "The universal time is : ";
  clock.printUniversal();
  cout << "The standard time is : ";
  clock.printStandard();
}
