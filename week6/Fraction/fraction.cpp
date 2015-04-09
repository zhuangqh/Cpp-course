#include "fraction.h"
#include <iostream>
int fraction::gcd(const int &n, const int &d) const {
  if (d == 0)
    return n;
  return gcd(d, n % d);
}
void fraction::simp() {
  int g = gcd(_numerator, _denominator);
  _numerator /= g;
  _denominator /= g;
  if (_denominator < 0) {
    _numerator *= -1;
    _denominator *= -1;
  }
}
fraction::fraction(const int &n, const int &d) {
  _numerator = n;
  _denominator = d;
  simp();
}
fraction::fraction(const fraction &other) {
  _numerator = other._numerator;
  _denominator = other._denominator;
  simp();
}
void fraction::operator=(const fraction &other) {
  _numerator = other._numerator;
  _denominator = other._denominator;
  simp();
}
fraction fraction::operator+(const fraction &other) const {
  int n = _numerator*other._denominator + _denominator*other._numerator;
  int d = _denominator*other._denominator;
  fraction ans(n, d);
  ans.simp();
  return ans;
}
fraction fraction::operator-(const fraction &other) const {
  int n = _numerator*other._denominator - _denominator*other._numerator;
  int d = _denominator*other._denominator;
  fraction ans(n, d);
  ans.simp();
  return ans;
}
fraction fraction::operator*(const fraction &other) const {
  int n = _numerator*other._numerator;
  int d = _denominator*other._denominator;
  fraction ans(n, d);
  ans.simp();
  return ans;
}
fraction fraction::operator/(const fraction &other) const {
  int n = _numerator*other._denominator;
  int d = _denominator*other._numerator;
  fraction ans(n, d);
  ans.simp();
  return ans;
}
void fraction::operator+=(const fraction &other) {
}
void fraction::operator-=(const fraction &other) {
}
void fraction::operator*=(const fraction &other) {
}
void fraction::operator/=(const fraction &other) {
}
bool fraction::operator==(const fraction &other) const {
  if (_numerator == other._numerator && _denominator == other._denominator)
    return true;
  else
    return false;
}
bool fraction::operator!=(const fraction &other) const {
  if (_numerator != other._numerator || _denominator != other._denominator)
    return true;
  else
    return false;
}
bool fraction::operator<(const fraction &other) const {
  int ans = _numerator*other._denominator - _denominator*other._numerator;
  if (ans < 0)
    return true;
  else
    return false;
}
bool fraction::operator>(const fraction &other) const {
  int ans = _numerator*other._denominator - _denominator*other._numerator;
  if (ans > 0)
    return true;
  else
    return false;
}
bool fraction::operator<=(const fraction &other) const {
  int ans = _numerator*other._denominator - _denominator*other._numerator;
  if (ans <= 0)
    return true;
  else
    return false;
}
bool fraction::operator>=(const fraction &other) const {
  int ans = _numerator*other._denominator - _denominator*other._numerator;
  if (ans >= 0)
    return true;
  else
    return false;
}
std::istream & operator>>(std::istream &in, fraction &a) {
  in >> a._numerator >> a._denominator;
  a.simp();
  return in;
}
std::ostream & operator<<(std::ostream &out, const fraction &a) {
  if (a._denominator == 1) {
    out << a._numerator;
  } else if (a._denominator == 0) {
    out << "NaN";
  } else {
    if (a._denominator < 0) {
      out << '-';
      out << a._numerator << '/' << a._denominator*-1;
    } else {
      out << a._numerator << '/' << a._denominator;
    }
  }
  return out;
}
