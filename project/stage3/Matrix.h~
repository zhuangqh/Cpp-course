#ifndef MATRIX_H
#define MATRIX_H
#include "Base.h"
class Matrix : public Base {
 public:
  Matrix() : Base() {}
  Matrix(const Matrix &other) : Base(other) {}
  Matrix(int col, int row) : Base(col, row) {}
  ~Matrix() {}
  void print() const;
  Matrix row(int) const;
  Matrix col(int) const;
  int max_entry() const;
  int min_entry() const;
  Matrix operator+(const Matrix &) const;
  Matrix operator-(const Matrix &) const;
  Matrix operator*(const Matrix &) const;
};
#endif
