#include "Matrix.h"
#include <iostream>

using namespace std;


Matrix& Matrix::operator=(const Matrix& m){
    this->row = m.row;
    this->col = m.col;
    for(int i = 0; i < m.row*m.col; i++)
        this->matrix[i] = m.matrix[i];
    return *this;
}

Matrix& Matrix::operator=(type val) {
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            (*this)[i][j] = val;
    return *this;
}

ostream& operator<<(ostream& os, const Matrix& mat){
    if(mat.row == 1 && mat.col == 1){
        os << mat.matrix[0];
        return os;
    }
    for(int i = 0; i < mat.row; i++){
        os << "|\t";
        for(int j = 0; j < mat.col; j++){
            os << mat.matrix[j + i*mat.col] << "\t";
        }
        os << "|" << endl;
    }
    os << endl;
    return os;
}

Matrix Matrix::operator+(const Matrix& m){
    if(this->col != m.col || this->row != m.row)
        return *this;
    Matrix out(m.row, m.col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i] + m.matrix[i];
    return out;
}

Matrix Matrix::operator+(type val) {
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i]+val;
    return out;
}

Matrix Matrix::operator-(const Matrix & m) {
    if(this->col != m.col || this->row != m.row)
        return *this;
    Matrix out(m.row, m.col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i] - m.matrix[i];
    return out;
}

Matrix Matrix::operator-(type val) {
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i]-val;
    return out;
}

Matrix Matrix::operator*(type val) {
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i]*val;
    return out;
}

Matrix Matrix::operator*(const Matrix & m){
    return dot(*this, m);
}

Matrix Matrix::operator/(type val) {
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.row*out.col; i++)
        out.matrix[i] = this->matrix[i]/val;
    return out;
}

Matrix Matrix::operator/(Matrix& m){
    Matrix out = (*this)*inverse(m);
    return out;
}

Matrix& Matrix::operator+=(const Matrix& m){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] += m.matrix[i];
    return *this;
}

Matrix& Matrix::operator+=(type val) {
    for(int i = 0; i < this->row * this->col; i++)
        this->matrix[i] += val;
    return *this;
}


Matrix& Matrix::operator-=(const Matrix& m){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] -= m.matrix[i];
    return *this;
}

Matrix& Matrix::operator-=(type val){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] -= val;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m){
    *this = dot(*this, m);
    return *this;
}

Matrix& Matrix::operator*=(type val){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] *= val;
    return *this;
}

Matrix& Matrix::operator/=(type val){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] /= val;
    return *this;
}

Matrix& Matrix::operator/=(Matrix& m){
    return *this *= inverse(m);
}

Matrix Matrix::operator-(){
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.col*out.row; i++)
        out.matrix[i] = -this->matrix[i];
    return out;
}

type* Matrix::operator[](int index){
    type* p = &matrix[col*index];
    return p;
}

Matrix operator+(type val, const Matrix& m){
    Matrix out = m;
    return out+val;
}

Matrix operator-(type val, const Matrix& m){
    Matrix out = m;
    out = -out;
    return out+val;
}

Matrix operator*(type val, const Matrix& m){
    Matrix out = m;
    return out*val;
}

Matrix operator/(type val, const Matrix& m){
    Matrix out = m;
    out.inverse();
    return val*out;
}
