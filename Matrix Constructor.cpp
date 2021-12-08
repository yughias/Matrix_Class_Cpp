#include "Matrix.h"

Matrix::Matrix(){};

Matrix::Matrix(int r, int c) {
    row = r;
    col = c;
    matrix = new type[row*col];
}

Matrix::Matrix(type val){
    row = 1;
    col = 1;
    matrix = new type[1];a
    matrix[0] = val;
}

Matrix::Matrix(int r, int c, const type* mat){
    row = r;
    col = c;
    matrix = new type[row*col];
    for(int i = 0; i < row*col; i++)
        matrix[i] = mat[i];
}

//copy constructor
Matrix::Matrix(const Matrix& mat) {
    row = mat.row;
    col = mat.col;
    matrix = new type[row*col];
    for(int i = 0; i < row*col; i++)
        matrix[i] = mat.matrix[i];
}

Matrix::~Matrix(){
    delete[] matrix;
}

