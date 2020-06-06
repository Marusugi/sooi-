#include "Matrix.hpp"
#include <iostream>
using namespace std;

Matrix::Matrix(int tate,int yoko){
    m_tate=tate;
    m_yoko=yoko;
    
    if(tate*yoko<1) mtrx=NULL;
    else mtrx=new int[tate*yoko];
    
    cout<<"A matrix had been made."<<endl;
}

Matrix::~Matrix(){
    cout<<"deleeeeeeeeeeeeeeete"<<endl;
    delete[] mtrx;
}

void Matrix::assign(Matrix& mat){
    for(int a=0;a<mat.m_tate;a++){
        cout<<endl;
        for(int b=0;b<mat.m_yoko;b++){
            cout<<" "<<endl;
            cin>>mat.mtrx[a*mat.m_yoko+b];
        }
    }
}

CalcMatrix::CalcMatrix():Matrix(0,0),answer(0,0){
    
}

void CalcMatrix::calc(const Matrix& mat1,const Matrix& mat2){
    if(! check(mat1,mat2)) return;
    
    answer.m_tate=mat1.m_tate;
    answer.m_yoko=mat2.m_yoko;
    answer.mtrx=new int[answer.m_tate*answer.m_yoko];
    
    for(int a=0;a<answer.m_tate*answer.m_yoko;a++){
        answer.mtrx[a]=0;
    }
    
//assigning process
    for(int a=1;a<=mat1.m_tate;a++){
        for(int b=1;b<=mat2.m_yoko;b++){
            int imp=0;
            for(int c=1;c<=mat1.m_yoko;c++){
                imp+=mat1.mtrx[(a-1)*mat1.m_yoko+c-1]*mat2.mtrx[(c-1)*mat1.m_yoko+b-1];
            }
            answer.mtrx[(a-1)*mat1.m_yoko+b-1]=imp;
        }
    }
}

bool CalcMatrix::check(const Matrix& mat1,const Matrix& mat2) const{
    if(mat1.m_yoko==mat2.m_tate) return true;
    
    cout<<"killall yourself"<<endl;
    return false;
}

int ShwKaisu::count_kaisu(Matrix& mat){
    int table[mat.m_tate];
    
    for(int a=0;a<mat.m_yoko;a++){
        if(!(mat.mtrx[mat.m_yoko*(mat.m_tate-1)+a]==0)) kai++;
    }
    if(!(kai==0)) return -1;

//0 counter
    for(int a=0;a<mat.m_tate;a++){
        for(int b=0;b<mat.m_yoko;b++){
            if(!(mat.mtrx[a*mat.m_yoko+b]==0)){
                table[a]=b; break;
            }
        }
    }
    
    for(int a=1;a<mat.m_tate;a++){
        if(mat.mtrx[a-1]>mat.mtrx[a]) return-1;
        if(mat.mtrx[a-1]<mat.mtrx[a]) kai++;
    }
    return kai;
}
