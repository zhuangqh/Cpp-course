#include <iostream>
#include <fstream>
#include <list>
#include "Date.h"

int main() {
    Date d = Date::stringToDate("2013-12-12/12:12");
    std::cout << d.getYear() << " "
              << d.getMonth() << " "
              << d.getDay() << " "
              << d.getHour() << " "
              << d.getMinute() << std::endl;
}
