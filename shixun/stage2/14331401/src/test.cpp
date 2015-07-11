#include <iostream>
#include <fstream>
#include <list>
#include "Date.h"

int main() {
  Date fuck = Date::stringToDate("2010-07-01/20:01");
  std::cout << fuck.getYear() << " "
            << fuck.getMonth() << " "
            << fuck.getDay() << " "
            << fuck.getHour() << " "
            << fuck.getMinute() << std::endl;

}
