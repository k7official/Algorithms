//Modify Algorithm 3.2 (Binomial coefficient using dynamic programming) so that 
//it uses only one-dimensional array indexed from 0 to k

#include<iostream>
using namespace std;

int min(int a, int b){
    return (a < b) ? a : b;
}

int bin(int n, int k){
    int i, j;
    int B[k+1];
    for(int i=0;i<k+1;i++)B[i]=0;
    //memset(B, 0, sizeof(B));
    B[0] = 1;

    for(i=1; i<=n;i++){
        for(j=min(i,k); j>0; j--){
                B[j] = B[j] + B[j-1];
        }
    }
    return B[k];
}

int main(){
    
    cout << bin(4, 2)<< endl;
    return 0;
}