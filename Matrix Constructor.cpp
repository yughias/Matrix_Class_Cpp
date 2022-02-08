#include "Matrix.h"


Matrix::Matrix(int r, int c) {
    row = r;
    col = c;
    matrix = new float[row * col];
}


Matrix::Matrix(float val) {
    row = 1;
    col = 1;
    matrix = new float[1];
    matrix[0] = val;
}

Matrix::Matrix(int r, int c, const float *mat) {
    row = r;
    col = c;
    matrix = new float[row * col];
    for (int i = 0; i < row * col; i++)
        matrix[i] = mat[i];
}

//copy constructor

Matrix::Matrix(const Matrix &mat) {
    row = mat.row;
    col = mat.col;
    matrix = new float[row * col];
    for (int i = 0; i < row * col; i++)
        matrix[i] = mat.matrix[i];
}


Matrix::~Matrix() {
    delete[] matrix;
}

