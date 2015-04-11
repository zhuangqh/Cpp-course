#include "Vector.h"
#include "Base.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void Vector::set_one(int value, int pos_x, int pos_y) {
  Base::set_one(value, 0, pos_x);
}
int Vector::length() const{
  int length = 0;
  for (int i = 0; i < _col; ++i)
    length += _data[0][i] * _data[0][i];
  length = sqrt(length);
  return length;
}
void Vector::print() const{
  cout << '(';
  for (int i = 0; i < _col; ++i) {
    cout << _data[i];
    if (i != _col - 1) cout << ", ";
  }
  cout << ")\n";
}
Vector Vector::operator+(const Vector& other) const{
  Vector ans(_col);
  for (int i = 0; i < _col; ++i)
    ans._data[0][i] = other._data[0][i] + _data[0][i];
  return ans;
}
Vector Vector::operator-(const Vector& other) const {
  Vector ans(_col);
  for (int i = 0; i < _col; ++i)
    ans._data[0][i] = other._data[0][i] - _data[0][i];
  return ans;
}
Vector Vector::operator*(const Vector& other) const {
  Vector ans(1);
  for (int i = 0; i < _col; ++i)
    ans._data[0][0] += other._data[0][i] * _data[0][i];
  return ans;
}
