#ifndef BASE_H
#define BASE_H
class Base {
 protected:
  int **_data;
  int _col, _row;
  void create(int col, int row = 1);
  void clean();
public:
  Base();
  Base(const Base &);
  Base(int col, int row);
  ~Base();
  //the common method
  void set(const int **, int col, int row);
  void set_one(int value, int pos_x, int pos_y);
  int *size() const;
  int get(int pos_x , int pos_y) const;
  bool all(int *keys, int length) const;
  bool any(int *keys, int length) const;
};
#endif
