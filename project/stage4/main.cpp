#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <assert.h>
using namespace std;
int main() {
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
  example.print();
  //method #2
  cout << "example is " << endl;
  example.set_one(0, 0, 0);
  example.print();
  cout << "after set index[0][0] to 0" << endl;
  //method #4
  int *row_col_message = example.size();
  cout << "The row of example is " << row_col_message[0] << endl
       << "The column of example is " << row_col_message[1] << endl;
  //free the memory
  delete row_col_message;
  //method #5
  cout << "Entry of row 1 col 1 is " << example.get(1, 1) << endl;
  //method #6
  cout << "row 1 is " << endl;
  example.row(1).print();
  //method #7
  cout << "col 1 is " << endl;
  example.col(1).print();
  //method #8
  cout << "The maxinum entry of example is ";
  cout << example.max_entry() << endl;
  //method #9
  cout << "The mininum entry of example is ";
  cout << example.min_entry() << endl;
  //method #10
  cout << "example + example =" << endl;
  Matrix<double> sum = example + example;
  sum.print();
  //method #11
  cout << "example - example =" << endl;
  Matrix<double> substract = example - example;
  substract.print();
  //method #12
  cout << "example * example =" << endl;
  Matrix<double> multiply = example * example;
  multiply.print();


  //show the method of class Vector;
  cout << "\n**************************\n\n"
       << "The base methods of Vector\n\n"
       << "**************************\n";
  Vector<int> vec;
  const int C_2D_array2[3][1] = { 1, 2, 3 };
  //method #1
  cout << "vec is ";
  vec.set(C_2D_array2);
  vec.print();
  //mrthod #2
  cout << "vec is ";
  vec.set_one(0, 0);
  vec.print();
  cout << "after set index 0 to 0" << endl;
  //method #3
  cout << "The dimension of vec is " << vec.dimension() << endl;
  //method #4
  cout << "The length of vec is " << vec.length() << endl;
  //method #5
  cout << "vec + vec = ";
  Vector<int> sum2 = vec + vec;
  sum2.print();
  //method #6
  cout << "vec - vec = ";
  Vector<int> substract2 = vec - vec;
  substract2.print();
  //method #7
  cout << "vec * vec = ";
  Vector<int> multiply2(vec * vec);
  multiply2.print();

  //show the new method "all" and "any"
  Matrix<int> base;
  base.set(C_2D_array2);
  //method "all"
  int check_for_all[3] = { 1, 2, 3 };
  cout << (base.all(check_for_all) ? "True\n" : "False\n");
  //method "any"
  int check_for_any[3] = { 11, 22, 33 };
  cout << (base.any(check_for_any) ? "True\n" : "False\n");

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
  cout << "Matrix example2 is " << endl;
  example2.print();
  //show the method "inverse"
  cout << "The inverse of 'example2' is " << endl;
  example2.inverse().print();
  cout << endl << "example2 * example2-1 is " << endl;
  (example2 * example2.inverse()).print();
  //show the method "determinant"
  cout << "The determinant of example2 is "
       << example2.determinant() << endl;
  //show the method "transpose"
  cout << "The transpose form of example2 is " << endl;
  example2.transpose().print();
  //show the overload of operator ()
  cout << "example2(2, 2) is " << example2(2, 2) << endl;

  ///////////////////////
  Matrix<double> hey;
  hey << "1.1,2.2,3.3;4.4,5,6;7,8,9";
  hey.print();
  return 0;
}
