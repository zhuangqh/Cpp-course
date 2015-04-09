#include "myString.h"
#include <cstring>
#include <iostream>
#include <iomanip>
myString::myString() {
  _data = NULL;
  _length = 0;
}
myString::myString(const char *c) {
  int len = strlen(c);
  _length = len;
  _data = new char[_length + 1];
  strncpy(_data, c, _length + 1);
}
myString::myString(const myString &other) {
  _length = other._length;
  _data = new char[_length + 1];
  strncpy(_data, other._data, _length + 1);
}
myString::~myString() {
  delete[]_data;
}
void myString::clear() {
  delete[]_data;
  _data = NULL;
  _length = 0;
}
unsigned myString::length() const {
  return _length;
}
const char * myString::c_str() const {
  return _data;
}
void myString::operator=(const char *cstr) {
  _length = strlen(cstr);
  if (_data) delete[]_data;
  _data = new char[_length + 1];
  strncpy(_data, cstr, _length + 1);
}
void myString::operator=(const myString &other) {
  _length = other._length;
  if (_data) delete[]_data;
  _data = new char[_length + 1];
  strncpy(_data, other._data, _length + 1);
}
char myString::operator[](const unsigned &index) const {
  return _data[index];
}
char &myString::operator[](const unsigned &index) {
  return _data[index];
}
myString myString::operator+(const myString &other) const {
  myString ans;
  ans._length = _length + other._length;
  ans._data = new char[ans._length + 1];
  strncpy(ans._data, _data, _length);
  for (int i = _length; i < ans._length + 1; ++i) {
    ans._data[i] = other._data[i - _length];
  }
  return ans;
}
myString myString::operator+(const char *cstr) const {
  myString ans;
  ans._data = new char[_length + strlen(cstr) + 1];
  strncpy(ans._data, _data, _length);
  for (int i = _length; i < _length + strlen(cstr) + 1; ++i) {
    ans._data[i] = cstr[i - _length];
  }
  return ans;
}
void myString::operator+=(const myString &other) {
  *this = *this + other;
}
void myString::operator+=(const char *cstr) {
  *this = *this + cstr;
}
bool myString::operator==(const myString &other) const {
  return !strcmp(_data, other._data);
}
bool myString::operator==(const char *cstr) const {
  return !strcmp(_data, cstr);
}
bool myString::operator!=(const myString &other) const {
  return strcmp(_data, other._data);
}
bool myString::operator!=(const char *cstr) const {
  return strcmp(_data, cstr);
}
bool myString::operator<(const myString &other) const {
  return (strcmp(_data, other._data) < 0);
}
bool myString::operator<(const char *cstr) const {
  return (strcmp(_data, cstr) < 0);
}
bool myString::operator<=(const myString &other) const {
  return (strcmp(_data, other._data) <= 0);
}
bool myString::operator<=(const char *cstr) const {
  return (strcmp(_data, cstr) <= 0);
}
bool myString::operator>(const myString &other) const {
  return (strcmp(_data, other._data) > 0);
}
bool myString::operator>(const char *cstr) const {
  return (strcmp(_data, cstr) > 0);
}
bool myString::operator>=(const myString &other) const {
  return (strcmp(_data, other._data) >= 0);
}
bool myString::operator>=(const char *cstr) const {
  return (strcmp(_data, cstr) >= 0);
}
myString operator+(const char *cstr, const myString &a) {
  myString ans(cstr);
  ans += a;
  return ans;
}
bool operator==(const char *cstr, const myString &a) {
  return (strcmp(cstr, a._data) == 0);
}
bool operator!=(const char *cstr, const myString &a) {
  return (strcmp(cstr, a._data) != 0);
}
bool operator<(const char *cstr, const myString &a) {
  return (strcmp(cstr, a._data) < 0);
}
bool operator<=(const char *cstr, const myString &a) {
  return (strcmp(cstr, a._data) <= 0);
}
bool operator>(const char *cstr, const myString &a) {
  return (strcmp(cstr, a._data) > 0);
}
bool operator>=(const char *cstr, const myString &a) {
  return (strcmp(cstr, a._data) >= 0);
}
std::istream & operator>>(std::istream & in, myString &a) {
  char tmp[255];
  in >> std::setw(255) >> tmp;
  a = tmp;
  return in;
}
std::ostream & operator<<(std::ostream & out, const myString &a) {
  out << a.c_str();
  return out;
}
