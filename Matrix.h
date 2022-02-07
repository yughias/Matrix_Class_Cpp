#include <iostream>

using namespace std;

template <class type>
class Matrix {
private:
    int row, col;
    type* matrix;

public:
    Matrix();
    Matrix(type);
    Matrix(const Matrix<type>&);
    Matrix(int, int);
    Matrix(int, int, const type*);
    ~Matrix();

    //matrix function
    void init(int);
    Matrix<type>& transposed();
    Matrix<type>& inverse();
    Matrix<type>& swapRows(int, int, bool= false);
    Matrix<type>& gaussMove(int, int, type, type, bool= false);
    Matrix<type>& gaussReduction(bool=false);
    Matrix<type>& rowEchelonForm(bool=false);
    type det();

    //static function
    static Matrix<type> dot(const Matrix<type>&, const Matrix<type>&);
    static Matrix<type> subMatrix(int, int, const Matrix<type>&);
    static Matrix<type> round(const Matrix<type>&);
    static Matrix<type> transposed(const Matrix<type>&);
    static Matrix<type> coeff(const Matrix<type>&);
    static Matrix<type> inverse(Matrix<type>&);
    static Matrix<type> gaussReduction(Matrix<type>& m, bool= false);
    static Matrix<type> rowEchelonForm(Matrix<type>&, bool= false);


    //operator overloading
    Matrix<type>& operator=(const Matrix<type>&);
    Matrix<type>& operator=(type);
    Matrix<type> operator+(const Matrix<type>&);
    Matrix<type> operator+(type);
    Matrix<type> operator-(const Matrix<type>&);
    Matrix<type> operator-(type);
    Matrix<type> operator-();
    Matrix<type> operator*(type);
    Matrix<type> operator*(const Matrix<type>&);
    Matrix<type> operator/(type);
    Matrix<type> operator/(Matrix<type>&);
    Matrix<type>& operator+=(const Matrix<type>&);
    Matrix<type>& operator+=(type);
    Matrix<type>& operator-=(const Matrix<type>&);
    Matrix<type>& operator-=(type);
    Matrix<type>& operator*=(const Matrix<type>&);
    Matrix<type>& operator*=(type);
    Matrix<type>& operator/=(type);
    Matrix<type>& operator/=(Matrix<type>&);
    type* operator[](int);

    friend ostream& operator<<(ostream& os, const Matrix<type>& mat){
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
};

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
