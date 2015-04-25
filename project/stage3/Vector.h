#ifndef VECTOR_H
#define VECTOR_H
#include "Base.h"
#include <cmath>
template<typename T>
class Vector : public Base<T> {
public:
  Vector() : Base<T>() {}
  Vector(const Vector<T> &other) : Base<T>(other) {}
  Vector(int col) : Base<T>(col, 1) {}
  void set_one(int value, int pos_x, int pos_y = 0);
  T length() const;
  void print() const;
  int get(int pos_x, int pos_y = 0) const;
  int dimension() const;
  Vector<T> operator+(const Vector<T>&) const;
  Vector<T> operator-(const Vector<T>&) const;
  Vector<T> operator*(const Vector<T>&) const;
};
template<typename T>
void Vector<T>::set_one(int value, int pos_x, int pos_y) {
        Base<T>::set_one(value, pos_y, pos_x);
}
template<typename T>
T Vector<T>::length() const{
        T length = 0;
        for (int i = 0; i < Base<T>::_col; ++i)
          length += Base<T>::_data[0][i] * Base<T>::_data[0][i];
        length = sqrt(length);
        return length;
}
template<typename T>
void Vector<T>::print() const{
        cout << '(';
        for (int i = 0; i < Base<T>::_col; ++i) {
          cout << Base<T>::_data[0][i];
          if (i != Base<T>::_col - 1) cout << ", ";
        }
        cout << ")\n";
}
template<typename T>
int Vector<T>::get(int pos_x, int pos_y) const {
  return Base<T>::_data[pos_y][pos_x];
}
template<typename T>
int Vector<T>::dimension() const {
  return Base<T>::_col;
}
template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const{
  Vector ans(Base<T>::_col);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][i] = other._data[0][i] + Base<T>::_data[0][i];
  return ans;
}
template<typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
  Vector<T> ans(Base<T>::_col);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][i] = other._data[0][i] - Base<T>::_data[0][i];
  return ans;
}
template<typename T>
Vector<T> Vector<T>::operator*(const Vector<T>& other) const {
  Vector<T> ans(1);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][0] += other._data[0][i] * Base<T>::_data[0][i];
  return ans;
}
#endif
