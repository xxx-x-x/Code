#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

template <typename elemType>
class Matrix{
    friend Matrix<elemType>& operator+(const Matrix<elemType>& m1,const Matrix<elemType>& );
    friend Matrix<elemType>& operator*(const Matrix<elemType>&m1,const Matrix<elemType>&);
public:
    Matrix(int rows,int cols):_rows(rows),_cols(cols){
        int size = rows * cols;
        _matrix = new elemType[size];
        for(int i=0;i<size;i++){
            _matrix[i] = elemType();
        }
    }
    // 深拷贝，创建同样大小的内存空间，然后存放过来。
    Matrix(const Matrix& rhs);
    Matrix& operator=(const Matrix &rhs);
    void operator+=(const Matrix&);
    elemType& operator ()(int row,int colum){
        return _matrix[row* cols() + colum];
    }
    int rows()const{return _rows;}
    int cols()const{return _cols;}
    virtual ~Matrix(){
        delete [] _matrix;
    }
    bool same_size(const Matrix &m) const{
        return this->_rows == m.rows() && this->_cols == m.cols();
    }
    bool comfortable(const Matrix&m) const{
        return this->_cols == m.rows();
    }
    ostream& operator<<(Matrix & m1)const;

    void print();
protected:
    int _rows;
    int _cols;
    int *_matrix;
};
template<typename elemType>
void Matrix<elemType>::print(){
    for(int i=0;i<rows();i++){
        for(int j=0;j<cols();j++){
            cout << _matrix[i* rows()+j] << " ";
        }
        cout << endl;
    }
}
template <typename elemType>
Matrix<elemType>::Matrix(const Matrix & rhs){
    _rows = rhs.rows();
    _cols = rhs.cols();
    _matrix = new elemType[_rows * _cols];
    for( int i=0;i<_rows * _cols;i++){
        _matrix[i] = rhs._matrix[i];
    }
}
//模板类要完整，实现加
template <typename elemType>
Matrix<elemType>& operator+(const Matrix<elemType>& m1,const Matrix<elemType>& m2){
    if(!m1.same_size(m2))return m1;
    Matrix<elemType> m3;
    m3._rows = m1.rows();
    m3._cols = m1.cols();
    int m3size =m3._rows * m3._cols;
    m3._matrix = new elemType[m3size];
    for( int i=0;i<m3size;i++){
        m3._matrix[i] = m1._matrix[i] + m2._matrix[i];
    }
    return m3;
}
//模板类要完整，实现乘
template<typename elemType>
Matrix<elemType>& operator*(const Matrix<elemType>&m1,const Matrix<elemType>&m2){
    if(!m1.comfortable(m2)) return m1;
    Matrix<elemType>& m3;
    m3._rows = m1.rows();
    m3._cols = m2.cols();
    int m3size = m3._rows * m3._cols;
    m3._matrix = new elemType[m3size];
    for(int i=0;i<m3.same_size;i++){
    }
}

template<typename elemType>
Matrix<elemType>& Matrix<elemType>::operator=(const Matrix &rhs){
    if(this!=&rhs){
        _rows = rhs._rows;
        _cols = rhs._cols;
        int tem_size = _rows * _cols;
        delete[] _matrix;
        _matrix = new elemType[tem_size];
        for(int i=0;i<tem_size;i++){
            _matrix[i] = rhs._matrix[i];
        }
    }
    return *this;
}

int main(){
    Matrix<int> m1(3,3);
    m1.print();
    return 0;

}