#include<stdio.h>
#include<iostream>
using namespace std;

class Matrix{
    friend Matrix operator+(const Matrix& m1,const Matrix& m2);
    friend Matrix operator-(const Matrix& m1,const Matrix& m2);
    friend Matrix operator*(const Matrix& m1,const Matrix& m2);
    friend void operator+=(Matrix& m1,const Matrix& m2);
    friend void print(const Matrix& );
public:
    Matrix(float m1[4][4]);
    Matrix( float a11 = 1,float a12 = 0,float a13 =0,float a14 =0,
            float a21 = 1,float a22 = 0,float a23 =0,float a24 =0,
            float a31 = 1,float a32 = 0,float a33 =0,float a34 =0,
            float a41 = 1,float a42 = 0,float a43 =0,float a44 =0){
                _matrix[0][0] = a11;_matrix[0][1] = a12;_matrix[0][2] = a13;_matrix[0][3] = a14;
                _matrix[1][0] = a21;_matrix[1][1] = a22;_matrix[1][2] = a23;_matrix[1][3] = a24;
                _matrix[2][0] = a31;_matrix[2][1] = a32;_matrix[2][2] = a33;_matrix[2][3] = a34;
                _matrix[3][0] = a41;_matrix[3][1] = a42;_matrix[3][2] = a43;_matrix[3][3] = a44;
            }
    float& operator()(int row,int column){
        return _matrix[row][column];
    }
    float operator()(int row,int column) const{
        return _matrix[row][column];
    }
private:
    float _matrix[4][4];
};

Matrix operator+(const Matrix& m1,const Matrix& m2){ 
    Matrix m3;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            m3._matrix[i][j] = m1._matrix[i][j] + m2._matrix[i][j];
        }
    }
    return m3;
}
Matrix operator-(const Matrix& m1,const Matrix& m2){
    Matrix m3;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            m3._matrix[i][j] = m1._matrix[i][j] - m2._matrix[i][j];
        }
    }
    return m3;
}
Matrix operator*(const Matrix& m1,const Matrix& m2){
    Matrix m3;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            m3._matrix[i][j] = m1._matrix[i][j] * m2._matrix[i][j];
        }
    }
    return m3;
}
void operator+=(Matrix& m1,const Matrix& m2){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            m1._matrix[i][j] += m2._matrix[i][j];
        }
    }
}
void print(const Matrix& m1){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << m1._matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    Matrix m1(  1,2,3,4,
                5,6,7,8,
                9,10,1,2,
                3,4,5,6
    );
    Matrix m2(  12,2,3,4,
                5,6,7,8,
                9,10,1,2,
                3,4,5,6
    );
    m1 += m2;
    // 括号操作符是被重载过的，这叫函数对象，用类名实现函数功能
    cout << m1(1,2) << endl;
    print(m1);
}