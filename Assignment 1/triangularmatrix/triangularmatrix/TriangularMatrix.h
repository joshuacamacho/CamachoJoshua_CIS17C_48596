#ifndef TRIANGULARMATRIX
#define TRIANGULARMATRIX
#include <cstdlib>
#include <ctime>
#include <iostream>
template<class T>

class TriangularMatrix{
private:
  int nRows;
  int* colAry;
  T** triArray;
  //fill the column array
  int* fillArray(int cols){
    int* ary = new int[cols];
    for (int i = 0; i<cols; i++){
      ary[i] = rand() % 10 + 1;
    }
    return ary;
  };
  //fill the triangle array
  T** fillArray(int rows, int* colAry){
      
    T** array = new T*[rows];
    for (int row = 0; row<rows; row++){
      array[row] = new T[colAry[row]];
    }
    //fill the array with random 2digit numbers
    for (int row = 0; row<rows; row++){
      for (int col = 0; col<colAry[row]; col++){
        array[row][col] = rand() % 90 + 10;
      }
    }
    return array;
  };


public:
  TriangularMatrix(int rows){
    //fill colAry;
    this->nRows = rows;
    srand(time(NULL));
    this->colAry = fillArray(5);
    //fill triangle array
    this->triArray = fillArray(rows, this->colAry);
  };

  void print(){

    
    

    std::cout << "\n";
    for (int row = 0; row<this->nRows; row++){
      for (int col = 0; col<this->colAry[row]; col++){
        std::cout << this->triArray[row][col] << " ";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  };
  ~TriangularMatrix(){
    delete[] this->colAry;//single array delete
    //triangle array delete
    for (int row = 0; row<this->nRows; row++){
      delete[]this->triArray[row];
    }
    delete[]this->triArray;
  };
};


#endif // !TRIANGULARMATRIX
