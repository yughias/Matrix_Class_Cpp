#include <iostream>

using namespace std;

typedef double type;

class Matrix : public error_code {
private:
    int row, col;
    type* matrix;

public:
    Matrix();
    Matrix(type);
    Matrix(const Matrix&);
    Matrix(int, int);
    Matrix(int, int, const type*);
    ~Matrix();

    //matrix function
    void init(int);
    Matrix& transposed();
    Matrix& inverse();
    Matrix& swapRows(int, int, bool= false);
    Matrix& gaussMove(int, int, type, type, bool= false);
    Matrix& gaussReduction(bool=false);
    Matrix& rowEchelonForm(bool=false);
    type det();

    //static function
    static Matrix dot(const Matrix&, const Matrix&);
    static Matrix subMatrix(int, int, const Matrix&);
    static Matrix round(const Matrix&);
    static Matrix transposed(const Matrix&);
    static Matrix coeff(const Matrix&);
    static Matrix inverse(Matrix&);
    static Matrix gaussReduction(Matrix& m, bool= false);
    static Matrix rowEchelonForm(Matrix&, bool= false);


    //operator overloading
    Matrix& operator=(const Matrix&);
    Matrix& operator=(type);
    Matrix operator+(const Matrix&);
    Matrix operator+(type);
    Matrix operator-(const Matrix&);
    Matrix operator-(type);
    Matrix operator-();
    Matrix operator*(type);
    Matrix operator*(const Matrix&);
    Matrix operator/(type);
    Matrix operator/(Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator+=(type);
    Matrix& operator-=(const Matrix&);
    Matrix& operator-=(type);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(type);
    Matrix& operator/=(type);
    Matrix& operator/=(Matrix&);
    type* operator[](int);

    friend ostream& operator<<(ostream&, const Matrix&);
    friend Matrix operator+(type, const Matrix&);
    friend Matrix operator-(type, const Matrix&);
    friend Matrix operator*(type, const Matrix&);
    friend Matrix operator/(type, const Matrix&);
};