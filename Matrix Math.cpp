#include "Matrix.h"
#include <cmath>

void Matrix::init(int val){
    for(int i = 0; i < row*col; i++)
        matrix[i] = val;
}

Matrix& Matrix::transposed() {
    int tmp = 0;
    type* mat = new type[row*col];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++){
            mat[tmp] = matrix[j + i*col];
            tmp++;
        }

    delete[] matrix;
    matrix = mat;
    tmp = row;
    row = col;
    col = tmp;
    return *this;
}

Matrix Matrix::transposed(const Matrix& m){
    Matrix out(m.col, m.row);
    int tmp = 0;
    for(int i = 0; i < m.row; i++)
        for(int j = 0; j < m.col; j++){
            out.matrix[tmp] = m.matrix[i + j*m.col];
            tmp++;
        }
    return out;
}

Matrix Matrix::round(const Matrix& m){
    Matrix out(m.row, m.col);
    for(int i = 0; i < m.row*m.col; i++)
        out.matrix[i] = int(m.matrix[i]+0.5);
    return out;
}

Matrix Matrix::subMatrix(int r, int c, const Matrix & m) {
    Matrix out(m.row-1, m.col-1);
    for(int i = 0; i < m.row; i++)
        for(int j = 0; j < m.col; j++){
            if(i == r || j == c)
                continue;
            int idxI = i;
            int idxJ = j;
            if(idxI > r) idxI--;
            if(idxJ > c) idxJ--;
            out.matrix[idxJ + idxI*out.col] = m.matrix[j + i*m.col];
        }
    return out;
}

type Matrix::det() {
    if(this->row == 1 && this->col == 1)
        return this->matrix[0];
    if(this->row == 2 && this->col == 2)
        return this->matrix[0]*this->matrix[3]-this->matrix[1]*this->matrix[2];
    type det = 0;
    for(int i = 0; i < this->row; i++){
        Matrix sub = subMatrix(0, i, *this);
        det += pow(-1, i) * this->matrix[i] * sub.det();
    }
    return det;
}

Matrix Matrix::dot(const Matrix& m1, const Matrix& m2) {
    if(m1.col != m2.row) {
        return m1;
    }
    Matrix out(m1.row, m2.col);
    out.init(0);

    for(int i = 0; i < m1.row; i++){
        for(int j = 0; j < m2.col; j++){
            type value = 0;
            for(int k = 0; k < m2.row; k++) {
                value += m1.matrix[k + i * m1.col] * m2.matrix[j + k * m2.col];
            }
            out.matrix[j + i*out.col] = value;
        }
    }
    return out;
}

Matrix Matrix::coeff(const Matrix& m){
    Matrix out(m.row, m.col);
    for(int i = 0; i < out.row; i++)
        for(int j = 0; j < out.col; j++){
            out.matrix[j + i*out.col] = pow(-1, i+j) * subMatrix(i, j, m).det();
        }
    return out;
}

Matrix Matrix::inverse(Matrix& m) {
    if(m.row == 1 && m.col == 1)
        return Matrix(1/m[0][0]);
    return transposed(coeff(m))*(1/m.det());
}

Matrix& Matrix::inverse(){
    if(this->row == 1 && this->col == 1){
        (*this)[0][0] = 1/(*this)[0][0];
        return *this;
    }
    *this = inverse(*this);
    return *this;
}

Matrix& Matrix::swapRows(int r1, int r2, bool printable) {
    for(int i = 0; i < col; i++){
        type tmp = (*this)[r1][i];
        (*this)[r1][i] = (*this)[r2][i];
        (*this)[r2][i] = tmp;
    }
    if(printable){
        cout << "R" << r1 << " <-> " "R" << r2 << endl;
    }
    return *this;
}

Matrix& Matrix::gaussMove(int r1, int r2, type a, type b, bool printable) {
    for(int i = 0; i < col; i++){
        (*this)[r1][i] = a*(*this)[r1][i] + b*(*this)[r2][i];
    }
    if(printable && !(a == 1 && b == 0)){
        cout << "R" << r1 << " -> " << a << "*R" << r1;
        if(b> 0)
            cout << " + ";
        else
            cout << " - ";
        cout << abs(b) << "*R" << r2 << endl;
    }
}

Matrix Matrix::gaussReduction(Matrix & m, bool printable) {
    Matrix out = m;
    for(int i = 0; i < out.row; i++){
        if(out[i][i] == 0) {
            bool skip = true;
            for (int j = i + 1; j < out.row; j++)
                if (out[j][i] != 0) {
                    out.swapRows(i, j, printable);
                    skip = false;
                    break;
                }
            if(skip) continue;
        }
        for(int j = i+1; j < out.row; j++){
            out.gaussMove(j, i, out[i][i], -out[j][i], printable);
        }
    }
    return out;
}

Matrix Matrix::rowEchelonForm(Matrix & m, bool printable) {
    Matrix out = gaussReduction(m);
    for(int i = out.row-1; i >= 0; i--){
        for(int j = 0; j < out.col; j++){
            if(out[i][j] != 0){
                type tmp = out[i][j];
                for(int k = j; k < out.col; k++)
                    out[i][k] /= tmp;
                if(printable && tmp != 1)
                    cout << "R" << i << " -> " << " R" << i << "/" << tmp << endl;
                for(int k = i-1; k >= 0; k--)
                    out.gaussMove(k, i, 1, -out[k][j], printable);
                break;
            }
        }
    }
    return out;
}

Matrix& Matrix::gaussReduction(bool printable) {
    *this = gaussReduction(*this, printable);
    return *this;
}

Matrix& Matrix::rowEchelonForm(bool printable) {
    *this = rowEchelonForm(*this, printable);
    return *this;
}