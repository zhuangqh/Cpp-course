#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
Matrix::Matrix() {
  create(2, 2);
}
Matrix::Matrix(const Matrix &otherMatrix) {
  create(otherMatrix._row, otherMatrix._col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      matrix[i][j] = otherMatrix.matrix[i][j];
    }
  }
}
Matrix::Matrix(int row_num, int col_num) {
  create(row_num, col_num);
}
Matrix::~Matrix() {
  for (int i = 0; i < _row; ++i)
    delete[] matrix[i];
  delete[] matrix;
}
void Matrix::create(int row_num, int col_num) {
  _row = row_num;
  _col = col_num;
  matrix = new int*[_row];
  for (int i = 0; i < _row; ++i)
    matrix[i] = new int[_col];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      matrix[i][j] = 0;
    }
  }
}
void Matrix::set(const int **C_2D_array, int row_num, int col_num) {
  _row = row_num;
  _col = col_num;
  matrix = new int*[_row];
  for (int i = 0; i < _row; ++i)
    matrix[i] = new int[_col];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      matrix[i][j] = *((int*)C_2D_array + i*col_num + j);
    }
  }
}
void Matrix::set_one(int row_num, int col_num, int parameter) {
  if (row_num < _row && col_num < _col)
    matrix[row_num][col_num] = parameter;
}
void Matrix::print() const{
  for (int i = 0; i < _row; ++i) {
    cout << '|';
    for (int j = 0; j < _col; ++j) {
      cout << setw(4) << setfill(' ') << matrix[i][j];
    }
    cout << setw(4) << setfill(' ') << '|' << endl;
  }
}
int *Matrix::size() const{
  int *ans = new int[2];
  ans[0] = _row;
  ans[1] = _col;
  return ans;
}
int Matrix::get(int row_num, int col_num) const{
  return matrix[row_num][col_num];
}
Matrix Matrix::row(int row_num) const{
  Matrix ans(1, _col);
  for (int i = 0; i < _col; ++i)
    ans.matrix[0][i] = matrix[row_num][i];
  return ans;
}
Matrix Matrix::col(int col_num) const{
  Matrix ans(_row, 1);
  for (int i = 0; i < _row; ++i)
    ans.matrix[i][0] = matrix[i][col_num];
  return ans;
}
int Matrix::max_entry() const{
  int max_entry = matrix[0][0];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      max_entry = max(max_entry, matrix[i][j]);
    }
  }
  return max_entry;
}
int Matrix::min_entry() const{
  int min_entry = matrix[0][0];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      min_entry = min(min_entry, matrix[i][j]);
    }
  }
  return min_entry;
}
Matrix Matrix::operator+(const Matrix &other) const{
  Matrix ans(_row, _col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      ans.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
    }
  }
  return ans;
}
Matrix Matrix::operator-(const Matrix &other) const{
  Matrix ans(_row, _col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      ans.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
    }
  }
  return ans;
}
Matrix Matrix::operator*(const Matrix &other) const{
  Matrix ans(_row, other._col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < other._col; ++j) {
      for (int k = 0; k < _col; ++k) {
        ans.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
      }
    }
  }
  return ans;
}
