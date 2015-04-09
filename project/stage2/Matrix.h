#ifndef MATRIX_H
#define MATRIX_H
class Matrix {
private:
  int _row, _col;
  int **matrix;
  void create(int, int);
public:
  Matrix();
  Matrix(const Matrix &);
  Matrix(int row_num, int column_num);
  ~Matrix();
  void set(const int **, int, int);
  void set_one(int, int, int parameter);
  void print() const;
  int *size() const;
  int get(int, int) const;
  Matrix row(int) const;
  Matrix col(int) const;
  int max_entry() const;
  int min_entry() const;
  Matrix operator+(const Matrix &) const;
  Matrix operator-(const Matrix &) const;
  Matrix operator*(const Matrix &) const;
};
#endif
