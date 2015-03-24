#ifndef DATE_H
#define DATE_H
class Date {
 public:
   //month/day/year
   Date(int = 1, int = 1, int = 2000);
   void setDate(int month, int day, int year);
   void print();
   void nextDay();
 private:
   bool isLeapYear();
   int month, day, year;
};
#endif
