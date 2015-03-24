#ifndef TIME_H
#define TIME_H
class Time {
 public:
   Time();
   Time(int h, int m, int s);
   void tick();
   void setTime(int h, int m, int s);
   void printUniversal();
   void printStandard();
 private:
   int hour, minute, second;
};
#endif
