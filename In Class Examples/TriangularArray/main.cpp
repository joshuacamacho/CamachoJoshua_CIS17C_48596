/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on August 27, 2014, 8:02 PM
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* fillArray(int);
int** fillArray(int,int);
int** fillArray(int,int*);//triangular fill
void printArray(int**,int,int);
void printArray(int*,int,int);
void printArray(int**,int,int*);//triangle print
void destroy(int**,int);
void destroy(int*);
void destroy(int**,int*,int);//triangular delete

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    int rows=5,cols=10,perLine=10;
    int cls=5;
    int **array=fillArray(rows,cols);
    int *colAry=fillArray(cls);
    int **triAry=fillArray(rows,colAry);
    printArray(array,rows,cols);
    printArray(colAry,cls,perLine);
    printArray(triAry,rows,colAry);
    destroy(array,rows);
    destroy(colAry);
    destroy(triAry,rows);
    return 0;
}
void printArray(int** array, int rows, int cols){
    cout<<"\n";
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            cout<<array[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void printArray(int* array, int cols,int perline){
    cout<<"\n";
    for(int col=0; col<cols; col++){
        
            cout<<array[col]<<" ";
            if(col%perline==(perline-1))cout<<"\n";
        
    }
    cout<<"\n";
}
void printArray(int** array, int rows, int* cols){
    cout<<"\n";
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols[row]; col++){
            cout<<array[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int** fillArray(int rows,int *colAry){
    int** array = new int*[rows];
    for(int row=0; row<rows; row++){
        array[row]=new int[colAry[row]];
    }
    //fill the array with random 2digit numbers
    for(int row=0; row<rows; row++){
        for(int col=0; col<colAry[row]; col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}

int** fillArray(int rows,int cols){
    int** array = new int*[rows];
    for(int row=0; row<rows; row++){
        array[row]=new int[cols];
    }
    //fill the array with random 2digit numbers
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}
int* fillArray(int cols){
    int * array=new int[cols];
    for(int col=0; col<cols; col++){
        array[col]=rand()%10+1;
    }
    return array;
}
void destroy(int** array,int rows){
    
      for(int row=0; row<rows; row++){
          delete []array[row];
      }
      delete []array;
}
void destroy(int* array){
    delete []array;
}