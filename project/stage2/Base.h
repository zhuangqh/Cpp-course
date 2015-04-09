#ifndef BASE_H
#define BASE_H
class Base {
 private:
  int **_data;
  int _size;
 public:
  void set(int **value);
  void set_one(int value, int pos_x, int pos_y);
  int size();
  int get(int pos_x, int pos_y);
  bool all(int **keys);
  bool any(int **keys);
}
#endif
