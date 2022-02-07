#include "Matrix.h"

template <class type>
Matrix<type>::Matrix(){};

template <class type>
Matrix<type>::Matrix(int r, int c) {
    row = r;
    col = c;
    matrix = new type[row*col];
}

template <class type>
Matrix<type>::Matrix(type val){
    row = 1;
    col = 1;
    matrix = new type[1];
    matrix[0] = val;
}
template <class type>
Matrix<type>::Matrix(int r, int c, const type* mat){
    row = r;
    col = c;
    matrix = new type[row*col];
    for(int i = 0; i < row*col; i++)
        matrix[i] = mat[i];
}

//copy constructor
template <class type>
Matrix<type>::Matrix(const Matrix& mat) {
    row = mat.row;
    col = mat.col;
    matrix = new type[row*col];
    for(int i = 0; i < row*col; i++)
        matrix[i] = mat.matrix[i];
}

template <class type>
Matrix<type>::~Matrix(){
    delete[] matrix;
}

