#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
void Matrix::print() const{
  for (int i = 0; i < _row; ++i) {
    cout << '|';
    for (int j = 0; j < _col; ++j) {
      cout << setw(4) << setfill(' ') << _data[i][j];
    }
    cout << setw(4) << setfill(' ') << '|' << endl;
  }
}
Matrix Matrix::row(int row_num) const{
  Matrix ans(_col, 1);
  for (int i = 0; i < _col; ++i)
    ans._data[0][i] = _data[row_num][i];
  return ans;
}
Matrix Matrix::col(int col_num) const{
  Matrix ans(1, _row);
  for (int i = 0; i < _row; ++i)
    ans._data[i][0] = _data[i][col_num];
  return ans;
}
int Matrix::max_entry() const{
  int max_entry = _data[0][0];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      max_entry = max(max_entry, _data[i][j]);
    }
  }
  return max_entry;
}
int Matrix::min_entry() const{
  int min_entry = _data[0][0];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      min_entry = min(min_entry, _data[i][j]);
    }
  }
  return min_entry;
}
Matrix Matrix::operator+(const Matrix &other) const{
  Matrix ans(_row, _col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      ans._data[i][j] = _data[i][j] + other._data[i][j];
    }
  }
  return ans;
}
Matrix Matrix::operator-(const Matrix &other) const{
  Matrix ans(_row, _col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      ans._data[i][j] = _data[i][j] - other._data[i][j];
    }
  }
  return ans;
}
Matrix Matrix::operator*(const Matrix &other) const{
  Matrix ans(_row, other._col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < other._col; ++j) {
      for (int k = 0; k < _col; ++k) {
        ans._data[i][j] += _data[i][k] * other._data[k][j];
      }
    }
  }
  return ans;
}
