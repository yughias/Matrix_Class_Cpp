#include "Matrix.h"
#include <iostream>

using namespace std;

template <class type>
Matrix<type>& Matrix<type>::operator=(const Matrix& m){
    this->row = m.row;
    this->col = m.col;
    for(int i = 0; i < m.row*m.col; i++)
        this->matrix[i] = m.matrix[i];
    return *this;
}

template <class type>
Matrix<type>& Matrix<type>::operator=(type val){
    row = 1;
    col = 1;
    for(int i = 0; i < row*col; i++)
        this->matrix[i] = val;
    return *this;
}

template <class type>
Matrix<type> Matrix<type>::operator+(const Matrix& m){
    if(this->col != m.col || this->row != m.row)
        return *this;
    Matrix out(m.row, m.col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i] + m.matrix[i];
    return out;
}

template <class type>
Matrix<type> Matrix<type>::operator+(type val) {
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i]+val;
    return out;
}

template <class type>
Matrix<type> Matrix<type>::operator-(const Matrix & m) {
    if(this->col != m.col || this->row != m.row)
        return *this;
    Matrix out(m.row, m.col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i] - m.matrix[i];
    return out;
}

template <class type>
Matrix<type> Matrix<type>::operator-(type val) {
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i]-val;
    return out;
}

template <class type>
Matrix<type> Matrix<type>::operator*(type val) {
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.row * out.col; i++)
        out.matrix[i] = this->matrix[i]*val;
    return out;
}

template <class type>
Matrix<type> Matrix<type>::operator*(const Matrix & m){
    return dot(*this, m);
}

template <class type>
Matrix<type> Matrix<type>::operator/(type val) {
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.row*out.col; i++)
        out.matrix[i] = this->matrix[i]/val;
    return out;
}

template <class type>
Matrix<type> Matrix<type>::operator/(Matrix& m){
    Matrix out = (*this)*inverse(m);
    return out;
}

template <class type>
Matrix<type>& Matrix<type>::operator+=(const Matrix& m){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] += m.matrix[i];
    return *this;
}

template <class type>
Matrix<type>& Matrix<type>::operator+=(type val) {
    for(int i = 0; i < this->row * this->col; i++)
        this->matrix[i] += val;
    return *this;
}

template <class type>
Matrix<type>& Matrix<type>::operator-=(const Matrix& m){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] -= m.matrix[i];
    return *this;
}

template <class type>
Matrix<type>& Matrix<type>::operator-=(type val){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] -= val;
    return *this;
}

template <class type>
Matrix<type>& Matrix<type>::operator*=(const Matrix& m){
    *this = dot(*this, m);
    return *this;
}

template <class type>
Matrix<type>& Matrix<type>::operator*=(type val){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] *= val;
    return *this;
}

template <class type>
Matrix<type>& Matrix<type>::operator/=(type val){
    for(int i = 0; i < this->col*this->row; i++)
        this->matrix[i] /= val;
    return *this;
}

template <class type>
Matrix<type>& Matrix<type>::operator/=(Matrix& m){
    return *this *= inverse(m);
}

template <class type>
Matrix<type> Matrix<type>::operator-(){
    Matrix out(this->row, this->col);
    for(int i = 0; i < out.col*out.row; i++)
        out.matrix[i] = -this->matrix[i];
    return out;
}

template <class type>
type* Matrix<type>::operator[](int index){
    type* p = &matrix[col*index];
    return p;
}

//template class Matrix<int>;