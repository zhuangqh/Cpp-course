#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <typeinfo>
using namespace std;
void BaseMethodOfMatrix();
void BaseMethodOfVector();
void MatrixAdvancedMethod();
void StreamOverloading();
void ShowExceptionHandle();
int main() {
  cout << "Which part would you like to test?\n";
  cout << "0------The base methods of Matrix\n";
  cout << "1------The base methods of Vector\n";
  cout << "2------Matrix's advanced methods\n";
  cout << "3------Stream Overloading test\n";
  cout << "4------Show the Exception Handle\n";
  int mode;
  cin >> mode;
  try {
    switch(mode) {
    case 0: BaseMethodOfMatrix(); break;
    case 1: BaseMethodOfVector(); break;
    case 2: MatrixAdvancedMethod(); break;
    case 3: StreamOverloading(); break;
    case 4: ShowExceptionHandle(); break;
    }
  } catch (const out_of_range& e) {
    cout << "Exception occurred : "
         << e.what() << endl
         << "Error Type : " << typeid(e).name() << endl;
  } catch (const invalid_argument& e) {
    cout << "Exception occurred : "
         << e.what() << endl
         << "Error Type : " << typeid(e).name() << endl;
  } catch (const logic_error& e) {
    cout << "Exception occurred : "
         << e.what() << endl
         << "Error Type : " << typeid(e).name() << endl;
  }
  return 0;
}

void BaseMethodOfMatrix() {
  //show the method of class Matrix
  cout << "**************************\n\n"
       << "The base methods of Matrix\n\n"
       << "**************************\n";
  const double C_2D_array[3][3] = {
    { 1.1, 2.3, 3.3 },
    { 4.5, 5.7, 6.8 },
    { 7.8, 8.2, 9.3 }
  };
  Matrix<double> example;
  //method #1
  cout << "example is " << endl;
  example.set(C_2D_array);
  cout << example << endl;
  //method #2
  cout << "example is " << endl;
  example.set_one(0, 0, 0);
  cout << example << endl
       << "after set index[0][0] to 0" << endl;
  //method #4
  int *row_col_message = example.size();
  cout << "The row of example is " << row_col_message[0] << endl
       << "The column of example is " << row_col_message[1] << endl;
  //free the memory
  delete row_col_message;
  //method #5
  cout << "Entry of row 1 col 1 is " << example.get(1, 1) << endl;
  //method #6
  cout << "row 1 is " << endl
       << example.row(1) << endl;
  //method #7
  cout << "col 1 is " << endl
       << example.col(1) << endl;
  //method #8
  cout << "The maxinum entry of example is "
       << example.max_entry() << endl;
  //method #9
  cout << "The mininum entry of example is "
       << example.min_entry() << endl;
  //method #10
  cout << "example + example =" << endl;
  Matrix<double> sum = example + example;
  cout << sum << endl;
  //method #11
  cout << "example - example =" << endl;
  Matrix<double> substract = example - example;
  cout << substract << endl;
  //method #12
  cout << "example * example =" << endl;
  Matrix<double> multiply = example * example;
  cout << multiply << endl;
}

void BaseMethodOfVector() {
  //show the method of class Vector;
  cout << "\n**************************\n\n"
       << "The base methods of Vector\n\n"
       << "**************************\n";
  Vector<int> vec;
  const int C_2D_array2[3][1] = { 1, 2, 3 };
  //method #1
  cout << "vec is ";
  vec.set(C_2D_array2);
  cout << vec << endl;
  //mrthod #2
  cout << "vec is ";
  vec.set_one(0, 0);
  cout << vec << endl;
  cout << "after set index 0 to 0" << endl;
  //method #3
  cout << "The dimension of vec is " << vec.dimension() << endl;
  //method #4
  cout << "The length of vec is " << vec.length() << endl;
  //method #5
  cout << "vec + vec = ";
  Vector<int> sum2 = vec + vec;
  cout << sum2 << endl;
  //method #6
  cout << "vec - vec = ";
  Vector<int> substract2 = vec - vec;
  cout << substract2 << endl;
  //method #7
  cout << "vec * vec = ";
  Vector<int> multiply2(vec * vec);
  cout << multiply2 << endl;

  //show the new method "all" and "any"
  Matrix<int> base;
  base.set(C_2D_array2);
  //method "all"
  int check_for_all[3] = { 1, 2, 3 };
  cout << (base.all(check_for_all) ? "True\n" : "False\n");
  //method "any"
  int check_for_any[3] = { 11, 22, 33 };
  cout << (base.any(check_for_any) ? "True\n" : "False\n");
}

void MatrixAdvancedMethod() {
    //show the new method "determinant", "transpose" and "inverse"
  cout << "*************************\n\n"
       << "Matrix's advanced methods\n\n"
       << "*************************\n";
  double C_2D_array3[5][5] = {{1, 0, 1, 1, 1},
                              {0, 1, 0, 0, 0},
                              {2, 0, 3, 5, 2},
                              {0, 4, 0, 1, 4},
                              {0, 2, 0, 0, 1}};
  Matrix<double> example2;
  example2.set(C_2D_array3);
  cout << "Matrix example2 is " << endl
       << example2 << endl;
  //show the method "inverse"
  cout << "The inverse of 'example2' is " << endl
       << example2.inverse() << endl;
  cout << endl << "example2 * example2-1 is " << endl
       << example2 * example2.inverse() << endl;
  //show the method "determinant"
  cout << "The determinant of example2 is "
       << example2.determinant() << endl;
  //show the method "transpose"
  cout << "The transpose form of example2 is " << endl
       << example2.transpose() << endl;
  //show the overload of operator ()
  cout << "example2(2, 2) is " << example2(2, 2) << endl;
}

void StreamOverloading() {
  cout << "******************\n"
       << "Stream Overloading\n"
       << "******************\n";
  Matrix<double> o1;
  o1 << "1.1,2.2,3.3;4.4,5,6;7,8,9";
  cout << o1 << endl;
  Vector<double> o2;
  o2 << "1.2,2.3,3.4";
  cout << o2 << endl;
}

void ShowExceptionHandle() {
  cout << "*************************\n"
       << "Show the exception handle\n"
       << "*************************\n";
    double value[2][2] = {{1, 2},
                          {2, 4}};
    double value2[1][2] = {1, 2};
    Matrix<double> m1, m2;
    m1.set(value);
    m2.set(value2);
    //Please comment or uncomment some of the statement
    //to test the exception handle  :)
    cout << "m1 + m2 = " << m1 + m2 << endl;
    cout << "inverse of m1 " << m1.inverse() << endl;
    //cout << m1(2, 2) << endl;

}
