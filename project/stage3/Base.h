#ifndef BASE_H
#define BASE_H
template <typename T> 
class Base {
 protected:
  T **_data;
  T _col, _row;
  void create(int col, int row = 1);
  void clean();
public:
  Base();
  Base(const Base &);
  Base(int col, int row);
  ~Base();
  //the common method
  void set(const T **, int col, int row);
  void set_one(T value, int pos_x, int pos_y);
  int *size() const;
  T get(int pos_x , int pos_y) const;
  bool all(T *keys, int length) const;
  bool any(T *keys, int length) const;
};
#endif
