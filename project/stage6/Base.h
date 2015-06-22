#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
template <typename T>
class Base {
 protected:
  T **_data;
  int _col, _row;
  void create(int row, int col = 1);
  void clean();
 public:
  Base();
  explicit Base(const Base &);
  Base(int row, int col);
  template <unsigned N, unsigned M>
    Base(const T (&)[N][M]);
  ~Base();
  //the common method
  template <unsigned N, unsigned M>
    void set(const T (&)[N][M]);
  void set_one(T value, int pos_x, int pos_y = 0);
  int *size() const;
  T get(int pos_x , int pos_y = 0) const;
  template <unsigned N>
    bool all(T (&)[N]) const;
  template <unsigned N>
    bool any(T (&)[N]) const;
  T operator()(int row, int col = 0) const;
  void operator<<(const char*);
  void operator=(const Base&);
  void setByFile(const char*, int row, int col);
  void printToFile(const char*);
  void sort(const std::string &);
};

template <typename T>
Base<T>::Base() {
  create(1, 1);
}

//help to well manage the memory
template <typename T>
void Base<T>::create(int row, int col) {
  _col = col;
  _row = row;
  _data = new T*[_row];
  _data[0] = NULL;
  for (int i = 0; i < _row; ++i)
    _data[i] = new T[_col];
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = 0;
    }
  }
}

//help to well manage the memory
template <typename T>
void Base<T>::clean() {
  for (int i = 0; i < _row; ++i)
    delete[]_data[i];
  delete[]_data;
  _col = 1;
  _row = 1;
  _data = NULL;
}

template <typename T>
Base<T>::Base(const Base<T> &other) {
  create(other._row, other._col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = other._data[i][j];
    }
  }
}

template <typename T>
Base<T>::Base(int row, int col) {
  create(row, col);
}

template <typename T>
template <unsigned N, unsigned M>
Base<T>::Base(const T(&keys)[N][M]) {
  set(keys);
}

template <typename T>
Base<T>::~Base() {
  clean();
}

template <typename T>
template <unsigned N, unsigned M>
  void Base<T>::set(const T (&keys)[N][M]) {
  //if (_data[0]) clean();
  create(N, M);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = *((T *)keys + i*_col + j);
    }
  }
}

template <typename T>
void Base<T>::set_one(T value, int pos_x, int pos_y) {
  if (pos_x < _row && pos_x >= 0 && pos_y >= 0 && pos_y < _col)
    _data[pos_x][pos_y] = value;
  else
    throw std::out_of_range("Can't set a value in this position.");
}

template <typename T>
int *Base<T>::size() const {
  int *ans;
  if (_row == 1) {
    ans = new int[1];
    ans[0] = _col;
    return ans;
  } else {
    ans = new int[2];
    ans[0] = _row;
    ans[1] = _col;
    return ans;
  }
}

template <typename T>
T Base<T>::get(int pos_x, int pos_y) const {
  if (pos_x < _row && pos_x >= 0 && pos_y < _col && pos_y >= 0)
    return _data[pos_x][pos_y];
  else
    throw std::out_of_range("Can't get a value out of the Matrix.");
}

template <typename T>
template <unsigned N>
  bool Base<T>::all(T (&keys)[N]) const {
  for (int i = 0; i < N; ++i) {
    bool ans = false;
    for (int k = 0; k < _row; ++k) {
      for (int l = 0; l < _col; ++l) {
        if (_data[k][l] == keys[i])
          ans = true;
      }
    }
    if (!ans) return false;
  }
  return true;
}

template <typename T>
template <unsigned N>
  bool Base<T>::any(T (&keys)[N]) const {
  for (int i = 0; i < N; ++i) {
    for (int k = 0; k < _row; ++k) {
      for (int l = 0; l < _col; ++l) {
        if (_data[k][l] == keys[i])
          return true;
      }
    }
  }
  return false;
}

template <typename T>
T Base<T>::operator()(int row, int col) const {
  if (row >= 0 && row < Base<T>::_row && col >= 0 && col < Base<T>::_col)
    return _data[row][col];
  else
    throw std::out_of_range("Can't get a value out of the range.");
}

template <typename T>
void Base<T>::operator<<(const char* cstr) {
  int comma_num = 0,
    semicolon_num = 0,
    row, col;
  std::string str(cstr);
  std::stringstream ss;  //used to convert string to numbers
  std::vector<T> num_container;  //used to save the numbers
  T temp;  //save the number temporary

  //get the number of the row and the column and values
  int head, tail;
  head = tail = 0;
  for (; tail != str.size(); ++tail) {
    if (tail == str.size() - 1) {
      ss << str.substr(head);
      ss >> temp;
      num_container.push_back(temp);
    }
    if (str[tail] == ',' || str[tail] == ';') {
      str[tail] == ',' ? comma_num++ : semicolon_num++;
      ss << str.substr(head, tail - head);
      ss >> temp;
      ss.clear();
      num_container.push_back(temp);
      head = tail + 1;
    }
  }
  row = semicolon_num + 1;
  col = (comma_num / row) + 1;
  create(row, col);
  //assign the value to the matrix
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      Base<T>::_data[i][j] = num_container[i * col + j];
    }
  }
}

template <typename T>
void Base<T>::operator=(const Base<T>& other) {
  clean();
  create(other._row, other._col);
  for (int i = 0; i < _row; ++i) {
    for (int j = 0; j < _col; ++j) {
      _data[i][j] = other._data[i][j];
    }
  }
}
template <typename T>
void Base<T>::setByFile(const char *filename, int row, int col) {
  std::ifstream fs;
  fs.open(filename, std::fstream::in);
  if (!fs.is_open()) {
    std::cout << "Error opening file\n";
    exit(1);
  }

  _row = row;
  _col = col;
  create(_row, _col);

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      fs >> _data[i][j];
    }
  }
  fs.close();
}

template <typename T>
void Base<T>::printToFile(const char *filename) {
  std::ofstream fs;
  fs.open(filename, std::fstream::out);
  if (!fs.is_open()) {
    std::cout << "Error opening file\n";
    exit(1);
  }

  for (int i = 0; i < _row; ++i) {
    bool is_first = true;
    for (int j = 0; j < _col; ++j) {
      if (is_first) is_first = false;
      else fs << ' ';
      fs << _data[i][j];
    }
    fs << std::endl;
  }
  fs.close();
}

template <typename T>
void Base<T>::sort(const std::string &str) {
  int size = _row * _col;
  bool is_increase;
  //confirm the mode is valid
  if (str == "descending") {
    is_increase = false;
  } else if (str == "ascending") {
    is_increase = true;
  } else {
    return;
  }
  while (size--) {
    for (int i = 0; i < _row*_col - 1; ++i) {
      T &p = _data[i/_col][i%_col],
        &q = _data[(i+1)/_col][(i+1)%_col];
      if (is_increase && p > q)
        std::swap(p, q);
      if (!is_increase && p < q)
        std::swap(p, q);
    }
  }
}
#endif
