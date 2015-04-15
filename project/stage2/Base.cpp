#include "Base.h"
#include <iostream>
using namespace std;
Base::Base() {
  create(0, 1);
}
//help to well manage the memory
void Base::create(int col, int row) {
  _col = col;
  _row = row;
  _data = new int*[_row];
  _data[0] = NULL;
  for (int i = 0; i < _row; ++i)
    _data[i] = new int[_col];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = 0;
    }
  }
}
//help to well manage the memory
void Base::clean() {
  for (int i = 0; i < _row; ++i)
    delete[]_data[i];
  delete[]_data;
  _col = 0;
  _row = 1;
  _data = NULL;
}
Base::Base(const Base &other) {
  create(other._col, other._row);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = other._data[i][j];
    }
  }
}
Base::Base(int col, int row) {
  create(col, row);
}
Base::~Base() {
  clean();
}
void Base::set(const int **keys, int col, int row) {
  if (_data[0]) clean();
  create(col, row);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = *((int *)keys + i*_col + j);
    }
  }
}
void Base::set_one(int value, int pos_x, int pos_y) {
  if (pos_x < _row && pos_y < _col)
    _data[pos_x][pos_y] = value;
}
int *Base::size() const {
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
int Base::get(int pos_x, int pos_y) const {
  if (pos_x < _row && pos_x >= 0 && pos_y < _col && pos_y >= 0) {
    return _data[pos_x][pos_y];
  } else {
    cout << "out of range!" << endl;
    return 1 << 31;
  }
}
bool Base::all(int *keys, int length) const {
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
bool Base::any(int *keys, int length) const {
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