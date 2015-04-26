#ifndef VECTOR_H
#define VECTOR_H
#include "Base.h"
#include <cmath>
template<typename T>
class Vector : public Base<T> {
 public:
  Vector() : Base<T>() {}
  Vector(const Vector<T> &other) : Base<T>(other) {}
  Vector(int row) : Base<T>(row, 1) {}
  T length() const;
  void print() const;
  int dimension() const;
  Vector<T> operator+(const Vector<T>&) const;
  Vector<T> operator-(const Vector<T>&) const;
  Vector<T> operator*(const Vector<T>&) const;
};
template<typename T>
T Vector<T>::length() const{
  T length = 0;
  for (int i = 0; i < Base<T>::_row; ++i)
    length += Base<T>::_data[i][0] * Base<T>::_data[i][0];
  length = sqrt(length);
  return length;
}
template<typename T>
void Vector<T>::print() const{
  cout << '(';
  for (int i = 0; i < Base<T>::_row; ++i) {
    cout << Base<T>::_data[i][0];
    if (i != Base<T>::_row - 1) cout << ", ";
  }
  cout << ")\n";
}
template<typename T>
int Vector<T>::dimension() const {
  return Base<T>::_row;
}
template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const{
  Vector ans(Base<T>::_row);
  for (int i = 0; i < Base<T>::_row; ++i)
    ans._data[i][0] = other._data[i][0] + Base<T>::_data[i][0];
  return ans;
}
template<typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
  Vector<T> ans(Base<T>::_row);
  for (int i = 0; i < Base<T>::_row; ++i)
    ans._data[i][0] = other._data[i][0] - Base<T>::_data[i][0];
  return ans;
}
template<typename T>
Vector<T> Vector<T>::operator*(const Vector<T>& other) const {
  Vector<T> ans(1);
  for (int i = 0; i < Base<T>::_row; ++i)
    ans._data[0][0] += other._data[i][0] * Base<T>::_data[i][0];
  return ans;
}
#endif
