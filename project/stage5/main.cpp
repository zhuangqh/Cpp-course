#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <typeinfo>
void BaseMethodOfMatrix();
void BaseMethodOfVector();
void MatrixAdvancedMethod();
void StreamOverloading();
void ShowExceptionHandle();
void FileInputOutputAndHandle();
int main() {
  std::cout << "Which part would you like to test?\n";
  std::cout << "0------The base methods of Matrix\n";
  std::cout << "1------The base methods of Vector\n";
  std::cout << "2------Matrix's advanced methods\n";
  std::cout << "3------Stream Overloading test\n";
  std::cout << "4------Show the Exception Handle\n";
  std::cout << "5------File input/output and handle\n";
  int mode;
  std::cin >> mode;
  try {
    switch(mode) {
    case 0: BaseMethodOfMatrix(); break;
    case 1: BaseMethodOfVector(); break;
    case 2: MatrixAdvancedMethod(); break;
    case 3: StreamOverloading(); break;
    case 4: ShowExceptionHandle(); break;
    case 5: FileInputOutputAndHandle(); break;
    }
  } catch (const std::out_of_range& e) {
    std::cout << "Exception occurred : "
         << e.what() << std::endl
         << "Error Type : " << typeid(e).name() << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cout << "Exception occurred : "
         << e.what() << std::endl
         << "Error Type : " << typeid(e).name() << std::endl;
  } catch (const std::logic_error& e) {
    std::cout << "Exception occurred : "
         << e.what() << std::endl
         << "Error Type : " << typeid(e).name() << std::endl;
  }
  return 0;
}

void BaseMethodOfMatrix() {
  //show the method of class Matrix
  std::cout << "**************************\n\n"
       << "The base methods of Matrix\n\n"
       << "**************************\n";
  const double C_2D_array[3][3] = {
    { 1.1, 2.3, 3.3 },
    { 4.5, 5.7, 6.8 },
    { 7.8, 8.2, 9.3 }
  };
  Matrix<double> example;
  //method #1
  std::cout << "example is \n";
  example.set(C_2D_array);
  std::cout << example << std::endl;
  //method #2
  std::cout << "example is \n";
  example.set_one(0, 0, 0);
  std::cout << example << std::endl
            << "after set index[0][0] to 0\n";
  //method #4
  int *row_col_message = example.size();
  std::cout << "The row of example is " << row_col_message[0] << std::endl
       << "The column of example is " << row_col_message[1] << std::endl;
  //free the memory
  delete row_col_message;
  //method #5
  std::cout << "Entry of row 1 col 1 is " << example.get(1, 1) << std::endl;
  //method #6
  std::cout << "row 1 is \n"
       << example.row(1) << std::endl;
  //method #7
  std::cout << "col 1 is \n"
       << example.col(1) << std::endl;
  //method #8
  std::cout << "The maxinum entry of example is "
       << example.max_entry() << std::endl;
  //method #9
  std::cout << "The mininum entry of example is "
       << example.min_entry() << std::endl;
  //method #10
  std::cout << "example + example =\n";
  Matrix<double> sum = example + example;
  std::cout << sum << std::endl;
  //method #11
  std::cout << "example - example =\n";
  Matrix<double> substract = example - example;
  std::cout << substract << std::endl;
  //method #12
  std::cout << "example * example =\n";
  Matrix<double> multiply = example * example;
  std::cout << multiply << std::endl;
}

void BaseMethodOfVector() {
  //show the method of class Vector;
  std::cout << "\n**************************\n\n"
       << "The base methods of Vector\n\n"
       << "**************************\n";
  Vector<int> vec;
  const int C_2D_array2[3][1] = { 1, 2, 3 };
  //method #1
  std::cout << "vec is ";
  vec.set(C_2D_array2);
  std::cout << vec << std::endl;
  //mrthod #2
  std::cout << "vec is ";
  vec.set_one(0, 0);
  std::cout << vec << std::endl;
  std::cout << "after set index 0 to 0\n";
  //method #3
  std::cout << "The dimension of vec is " << vec.dimension() << std::endl;
  //method #4
  std::cout << "The length of vec is " << vec.length() << std::endl;
  //method #5
  std::cout << "vec + vec = ";
  Vector<int> sum2 = vec + vec;
  std::cout << sum2 << std::endl;
  //method #6
  std::cout << "vec - vec = ";
  Vector<int> substract2 = vec - vec;
  std::cout << substract2 << std::endl;
  //method #7
  std::cout << "vec * vec = ";
  Vector<int> multiply2(vec * vec);
  std::cout << multiply2 << std::endl;

  //show the new method "all" and "any"
  Matrix<int> base;
  base.set(C_2D_array2);
  //method "all"
  int check_for_all[3] = { 1, 2, 3 };
  std::cout << (base.all(check_for_all) ? "True\n" : "False\n");
  //method "any"
  int check_for_any[3] = { 11, 22, 33 };
  std::cout << (base.any(check_for_any) ? "True\n" : "False\n");
}

void MatrixAdvancedMethod() {
    //show the new method "determinant", "transpose" and "inverse"
  std::cout << "*************************\n\n"
       << "Matrix's advanced methods\n\n"
       << "*************************\n";
  double C_2D_array3[5][5] = {{1, 0, 1, 1, 1},
                              {0, 1, 0, 0, 0},
                              {2, 0, 3, 5, 2},
                              {0, 4, 0, 1, 4},
                              {0, 2, 0, 0, 1}};
  Matrix<double> example2;
  example2.set(C_2D_array3);
  std::cout << "Matrix example2 is \n"
       << example2 << std::endl;
  //show the method "inverse"
  std::cout << "The inverse of 'example2' is \n"
       << example2.inverse() << std::endl;
  std::cout << std::endl << "example2 * example2-1 is \n"
       << example2 * example2.inverse() << std::endl;
  //show the method "determinant"
  std::cout << "The determinant of example2 is "
       << example2.determinant() << std::endl;
  //show the method "transpose"
  std::cout << "The transpose form of example2 is \n"
       << example2.transpose() << std::endl;
  //show the overload of operator ()
  std::cout << "example2(2, 2) is " << example2(2, 2) << std::endl;
}

void StreamOverloading() {
  std::cout << "******************\n"
       << "Stream Overloading\n"
       << "******************\n";
  Matrix<double> o1;
  o1 << "1.1,2.2,3.3;4.4,5,6;7,8,9";
  std::cout << o1 << std::endl;
  Vector<double> o2;
  o2 << "1.2,2.3,3.4";
  std::cout << o2 << std::endl;
}

void ShowExceptionHandle() {
  std::cout << "*************************\n"
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
    std::cout << "m1 + m2 = " << m1 + m2 << std::endl;
    std::cout << "inverse of m1 " << m1.inverse() << std::endl;
    //std::cout << m1(2, 2) << std::endl;

}

void FileInputOutputAndHandle() {
  Matrix<double> example3, example4;
  example3.setByFile("/home/zhuangqh/Cpp_homework/project/stage5/matrix1.txt",
                     3, 3);
  example4.setByFile("/home/zhuangqh/Cpp_homework/project/stage5/matrix2.txt",
                     3, 3);
  std::cout << example3 << std::endl << example4 << std::endl;
  example3.sort("descending");
  std::cout << "After sort \"descending\"\n" << example3 << std::endl;
  example3.printToFile("/home/zhuangqh/Cpp_homework/project/stage5/matrixout.txt");
  std::cout << "example3 hate example4\n";
  example3.hear("I hate", example4);
  std::cout << example3 << std::endl;
  std::cout << "example3 love example4\n";
  example3.hear("I love", example4);
  std::cout << example3 << std::endl;

  Vector<int> vec1;
  vec1.setByFile("/home/zhuangqh/Cpp_homework/project/stage5/vector1.txt", 6);
  std::cout << "The vector is \n"
            << vec1 << std::endl;
}
