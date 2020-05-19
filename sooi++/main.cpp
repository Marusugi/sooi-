#include <iostream>
using namespace std;

void cHar(char a[]){
    for(int x=0;x<(int)sizeof a;x++){
        a[x]=2*x;
        cout<<(int)a[x]<<endl;
    }
}

int main(){
    char a[6]={0};     //variable
    
    cout<<(int)sizeof a<<endl;
    cHar(a);
}
