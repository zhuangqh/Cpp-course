#include <iostream>
#include <string>
#include "Time.h"
using namespace std;
const string errorMessage[3] = {"The value of hour is invalid",
                                "The value of minute is invalid",
                                "The value of second is invalid"};
void errorManager(int errorValue) {
  switch(errorValue) {
  case 1: cout << errorMessage[0] << endl;
  case 2: cout << errorMessage[1] << endl;
  case 3: cout << errorMessage[0] << endl << errorMessage[1] << endl;
  case 4: cout << errorMessage[2] << endl;
  case 5: cout << errorMessage[0] << endl << errorMessage[2] << endl;
  case 6: cout << errorMessage[1] << endl << errorMessage[2] << endl;
  case 7: cout << errorMessage[0] << endl << errorMessage[1] << endl
               << errorMessage[2] << endl;
  }
}
int main() {
  //create Time object
  Time clock;
  //display the error message
  errorManager(clock.setTime(-1, -1, -1));
  return 0;
}
