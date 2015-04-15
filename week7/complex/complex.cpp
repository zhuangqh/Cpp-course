#include "complex.h"
#include <iostream>
#include <cmath>
using namespace std;
Complex::Complex() {
  real = imag = 0.0;
}
Complex::Complex(double re, double im) {
  real = re;
  imag = im;
}
Complex::~Complex() {
}
const double Complex::getReal() const {
  return real;
}
const double Complex::getImaginary() const {
  return imag;
}
void Complex::setReal(double rm) {
  real = rm;
}
void Complex::setImaginary(double im) {
  imag = im;
}
void Complex::fromString(const string & complexString) {
  double sum = 0.0;
  bool dian = false;
  int cnt = 0, fuhao = 1;
  for (int i = 0; i < complexString.size(); ++i) {
    if (dian) {
      ++cnt;
    }
    if (complexString[i] == '.') {
      dian = true;
    } else if (complexString[i] == '+'){
      real = sum / pow(10, cnt - 1);
      cnt = 0;
      sum = 0.0;
      dian = false;
    } else if (complexString[i] == '-') {
      real = sum / pow(10, cnt - 1);
      cnt = 0;
      sum = 0.0;
      dian = false;
      fuhao = -1;
    } else if (complexString[i] == 'i') {
      imag = fuhao * sum / pow(10, cnt - 1);
    } else {
      sum = sum * 10 + complexString[i] - '0';
    }
  }
}
Complex Complex::operator+(const Complex& other) {
  double r = real + other.real;
  double i = imag + other.imag;
  Complex ans(r, i);
  return ans;
}
Complex Complex::operator-(const Complex& other) {
  double r = real - other.real;
  double i = imag - other.imag;
  Complex ans(r, i);
  return ans;
}
Complex Complex::operator*(const Complex& other) {
  double r = real*other.real - imag*other.imag;
  double i = real*other.imag + imag*other.real;
  Complex ans(r, i);
  return ans;
}
Complex Complex::operator/(const Complex& other) {
  double ku = other.real*other.real + other.imag*other.imag;
  double r = real*other.real + imag*other.imag;
  double i = -1*real*other.imag + imag*other.real;
  r /= ku;
  i /= ku;
  Complex ans(r, i);
  return ans;
}
ostream& operator<<(ostream& out, Complex& other) {
  out << other.getReal();
  if (other.getImaginary() < 0) {
    out << " - " << -1*other.getImaginary();
  } else {
    out << " + " << other.getImaginary();
  }
  out << 'i';
}
