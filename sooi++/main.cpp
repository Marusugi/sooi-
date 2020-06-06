#include "Matrix.hpp"
#include <iostream>
using namespace std;

int main(){
    Matrix mat1(2,2),mat2(2,2);
    CalcMatrix proto;
    
    mat1.mtrx[0]=1;
    mat1.mtrx[1]=0;
    mat1.mtrx[2]=0;
    mat1.mtrx[3]=1;
    mat2.mtrx[0]=1;
    mat2.mtrx[1]=0;
    mat2.mtrx[2]=0;
    mat2.mtrx[3]=1;
    
    cout<<proto.calc(&mat1,&mat2)<<endl;
}
