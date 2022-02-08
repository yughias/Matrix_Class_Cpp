#include <iostream>

using namespace std;

class Matrix {
private:
    int row, col;
    float *matrix;

public:
    Matrix();

    Matrix(float);

    Matrix(const Matrix &);

    Matrix(int, int);

    Matrix(int, int, const float *);

    ~Matrix();

    //matrix function
    void init(int);

    Matrix &transposed();

    Matrix &inverse();

    Matrix &swapRows(int, int, bool= false);

    Matrix &gaussMove(int, int, float, float, bool= false);

    Matrix &gaussReduction(bool= false);

    Matrix &rowEchelonForm(bool= false);

    float det();

    //static function
    static Matrix dot(const Matrix &, const Matrix &);

    static Matrix subMatrix(int, int, const Matrix &);

    static Matrix round(const Matrix &);

    static Matrix transposed(const Matrix &);

    static Matrix coeff(const Matrix &);

    static Matrix inverse(Matrix &);

    static Matrix gaussReduction(Matrix &m, bool= false);

    static Matrix rowEchelonForm(Matrix &, bool= false);


    //operator overloading
    Matrix &operator=(const Matrix &);

    Matrix &operator=(float);

    Matrix operator+(const Matrix &);

    Matrix operator+(float);

    Matrix operator-(const Matrix &);

    Matrix operator-(float);

    Matrix operator-();

    Matrix operator*(float);

    Matrix operator*(const Matrix &);

    Matrix operator/(float);

    Matrix operator/(Matrix &);

    Matrix &operator+=(const Matrix &);

    Matrix &operator+=(float);

    Matrix &operator-=(const Matrix &);

    Matrix &operator-=(float);

    Matrix &operator*=(const Matrix &);

    Matrix &operator*=(float);

    Matrix &operator/=(float);

    Matrix &operator/=(Matrix &);

    float *operator[](int);

    friend ostream &operator<<(ostream &os, const Matrix &mat);
};
