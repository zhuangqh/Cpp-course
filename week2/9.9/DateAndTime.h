#ifndef DATEANDTIME_H
#define DATEANDTIME_H
class DateAndTime {
 public:
   DateAndTime(int = 1, int = 1, int = 2000, int = 12, int = 0, int = 0);
   void setDateAndTime(int = 1, int = 1, int = 2000, int = 12, int = 0, int = 0);
   void tick();
   void nextDay();
   void printStandard();
   void printUniversal();
 private:
   bool isLeapYear();
   int month, day, year;
   int hour, minute, second;
};
#endif
