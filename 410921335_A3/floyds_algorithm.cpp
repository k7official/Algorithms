#include<iostream>
using namespace std;
#define I 99999
#define N 7

int W[7][7] = {{0, 4, I, I, I, 10, I},
                {3, 0, I, 18, I, I, I},
                {I, 6, 0, I, I, I, I},
                {I, 5, 15, 0, 2, 19, 5},
                {I, I, 12, 1, 0, I, I},
                {I, I, I, I, I, 0, 10},
                {I, I, I, 8, I, I, 0}};
int D[7][7] = {{0, 4, I, I, I, 10, I},
                {3, 0, I, 18, I, I, I},
                {I, 6, 0, I, I, I, I},
                {I, 5, 15, 0, 2, 19, 5},
                {I, I, 12, 1, 0, I, I},
                {I, I, I, I, I, 0, 10},
                {I, I, I, 8, I, I, 0}};

void print(int a[7][7]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(a[i][j]>=I)
                cout <<  "∞" << " ";
            else
                cout<< a[i][j] << " ";
        }
        cout << endl;
    }
}

void floyd(){
    
    int P[N][N];
    //int D[N][N];
    int i, j, k;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            P[i][j] = 0;
            //D[i][j] = W[i][j];
        }
    }
    
    for(k=0; k<N; k++){
        //need utility function to print D matrix
        cout << "-----------------------" <<endl;
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(D[i][k] + D[k][j] < D[i][j]&& (D[k][j] != I && D[i][k] != I)){
                    P[i][j] = k+1;//since index start from 0
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
        print(P);
    }
    //cout << "------------------------" <<endl;
    //print(P);
}

int main(){

    floyd();

    return 0;
}