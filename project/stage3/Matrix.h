#ifndef MATRIX_H
#define MATRIX_H
#include "Base.h"
#include <iomanip>
#include <algorithm>
template<typename T>
class Matrix : public Base<T> {
 public:
  Matrix() : Base<T>() {}
  Matrix(const Matrix<T> &other) : Base<T>(other) {}
  Matrix(int row, int col) : Base<T>(row, col) {}
  ~Matrix() {}
  void print() const;
  Matrix row(int) const;
  Matrix col(int) const;
  T max_entry() const;
  T min_entry() const;
  Matrix transpose() const;
  Matrix determinant() const;
  Matrix inverse() const;
  Matrix operator+(const Matrix<T> &) const;
  Matrix operator-(const Matrix<T> &) const;
  Matrix operator*(const Matrix<T> &) const;
};
//print the matrix with a good layout
template<typename T>
void Matrix<T>::print() const{
  for (int i = 0; i < Base<T>::_row; ++i) {
    cout << '|';
    for (int j = 0; j < Base<T>::_col; ++j) {
      cout << setw(4) << setfill(' ') << Base<T>::_data[i][j];
    }
    cout << setw(4) << setfill(' ') << '|' << endl;
  }
}
template<typename T>
Matrix<T> Matrix<T>::row(int row_num) const{
  Matrix<T> ans(1, Base<T>::_col);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][i] = Base<T>::_data[row_num][i];
  return ans;
}
template<typename T>
Matrix<T> Matrix<T>::col(int col_num) const{
  Matrix<T> ans(Base<T>::_row, 1);
  for (int i = 0; i < Base<T>::_row; ++i)
    ans._data[i][0] = Base<T>::_data[i][col_num];
  return ans;
}
template<typename T>
T Matrix<T>::max_entry() const{
  T max_entry = Base<T>::_data[0][0];
  for (int i = 0; i < Base<T>::_row; ++i) {
    for (int j = 0; j < Base<T>::_col; ++j) {
      max_entry = max(max_entry, Base<T>::_data[i][j]);
    }
  }
  return max_entry;
}
template<typename T>
T Matrix<T>::min_entry() const{
  T min_entry = Base<T>::_data[0][0];
  for (int i = 0; i < Base<T>::_row; ++i) {
    for (int j = 0; j < Base<T>::_col; ++j) {
      min_entry = min(min_entry, Base<T>::_data[i][j]);
    }
  }
  return min_entry;
}
template <typename T>
Matrix<T> Matrix<T>::transpose() const {
  Matrix<T> ans(Base<T>::_col, Base<T>::_row);
  for (int i = 0; i < Base<T>::_col; ++i) {
    for (int j = 0; j < Base<T>::_row; ++j) {
      ans._data[i][j] = Base<T>::_data[j][i];
    }
  }
  return ans;
}
template <typename T>
Matrix<T> Matrix<T>::determinant() const {
  for (int i = 0; i < Base<T>::_col; ++i) {
    for (int j = 0; j < Base<T>::_row; ++j) {
      if (j == 0 && Base<T>::_data[j])
    }
  }
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const{
  Matrix<T> ans(Base<T>::_row, Base<T>::_col);
  for (int i = 0; i < Base<T>::_row; ++i) {
    for (int j = 0; j < Base<T>::_col; ++j) {
      ans._data[i][j] = Base<T>::_data[i][j] + other._data[i][j];
    }
  }
  return ans;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const{
  Matrix ans(Base<T>::_row, Base<T>::_col);
  for (int i = 0; i < Base<T>::_row; ++i) {
    for (int j = 0; j < Base<T>::_col; ++j) {
      ans._data[i][j] = Base<T>::_data[i][j] - other._data[i][j];
    }
  }
  return ans;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const{
  Matrix<T> ans(Base<T>::_row, other._col);
  for (int i = 0; i < Base<T>::_row; ++i) {
    for (int j = 0; j < other._col; ++j) {
      for (int k = 0; k < Base<T>::_col; ++k) {
        ans._data[i][j] += Base<T>::_data[i][k] * other._data[k][j];
      }
    }
  }
  return ans;
}

#endif
