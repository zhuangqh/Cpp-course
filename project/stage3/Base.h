#ifndef BASE_H
#define BASE_H
#include <iostream>
using namespace std;
template <typename T>
class Base {
 protected:
  T **_data;
  int _col, _row;
  void create(int row, int col = 1);
  void clean();
 public:
  Base();
  Base(const Base &);
  Base(int row, int col);
  ~Base();
  //the common method
  void set(const T **, int row, int col);
  void set_one(T value, int pos_x, int pos_y = 0);
  int *size() const;
  T get(int pos_x , int pos_y = 0) const;
  bool all(T *keys, int length) const;
  bool any(T *keys, int length) const;
  T operator()(int row, int col = 0) const;
};
template <typename T>
Base<T>::Base() {
  create(1, 1);
}
//help to well manage the memory
template <typename T>
void Base<T>::create(int row, int col) {
  _col = col;
  _row = row;
  _data = new T*[_row];
  _data[0] = NULL;
  for (int i = 0; i < _row; ++i)
    _data[i] = new T[_col];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = 0;
    }
  }
}
//help to well manage the memory
template <typename T>
void Base<T>::clean() {
  for (int i = 0; i < _row; ++i)
    delete[]_data[i];
  delete[]_data;
  _col = 1;
  _row = 1;
  _data = NULL;
}
template <typename T>
Base<T>::Base(const Base<T> &other) {
  create(other._row, other._col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = other._data[i][j];
    }
  }
}
template <typename T>
Base<T>::Base(int row, int col) {
  create(row, col);
}
template <typename T>
Base<T>::~Base() {
  clean();
}
template <typename T>
void Base<T>::set(const T **keys, int row, int col) {
  //if (_data[0]) clean();
  create(row, col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = *((T *)keys + i*_col + j);
    }
  }
}
template <typename T>
void Base<T>::set_one(T value, int pos_x, int pos_y) {
  if (pos_x < _row && pos_y < _col)
    _data[pos_x][pos_y] = value;
}
template <typename T>
int *Base<T>::size() const {
  int *ans;
  if (_row == 1) {
    ans = new int[1];
    ans[0] = _col;
    return ans;
  } else {
    ans = new int[2];
    ans[0] = _row;
    ans[1] = _col;
    return ans;
  }
}
template <typename T>
T Base<T>::get(int pos_x, int pos_y) const {
  if (pos_x < _row && pos_x >= 0 && pos_y < _col && pos_y >= 0) {
    return _data[pos_x][pos_y];
  } else {
    cout << "out of range!" << endl;
    return 1 << 31;
  }
}
template <typename T>
bool Base<T>::all(T *keys, int length) const {
  for (int i = 0; i < length; ++i) {
    bool ans = false;
    for (int k = 0; k < _row; ++k) {
      for (int l = 0; l < _col; ++l) {
        if (_data[k][l] == keys[i])
          ans = true;
      }
    }
    if (!ans) return false;
  }
  return true;
}
template <typename T>
bool Base<T>::any(T *keys, int length) const {
  for (int i = 0; i < length; ++i) {
    for (int k = 0; k < _row; ++k) {
      for (int l = 0; l < _col; ++l) {
        if (_data[k][l] == keys[i])
          return true;
      }
    }
  }
  return false;
}
template <typename T>
T Base<T>::operator()(int row, int col) const {
  if (row >= 0 && row < _row && col >= 0 && col < _col)
    return _data[row][col];
}
#endif
