#ifndef Matrixhpp
#define Matrixhpp

/*---------------------------------------------------------------------------------
 class aim to：BASE OF
              Make matrix.
              Calculating matrix.
              Showing KAISUU.
--------------- */
class Matrix{
public:
    Matrix(int tate,int yoko);
    virtual ~Matrix();
    void assign(Matrix& mat);
    int m_tate,m_yoko;
    int* mtrx;
};

/*---------------------------------------------------------------------------------
 class aim to：Calculate matrix
--------------- */
class CalcMatrix:public Matrix{
public:
    CalcMatrix();
    Matrix answer;
    void calc(const Matrix& mat1,const Matrix& mat2);
private:
    bool check(const Matrix& mat1,const Matrix& mat2) const;
};

/*---------------------------------------------------------------------------------
 class aim to：Showing KAISUU
--------------- */
class ShwKaisu:public Matrix{
public:
    int count_kaisu(Matrix& mat);
private:
    int kai=0;
};

#endif
