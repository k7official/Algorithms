#include<iostream>
using namespace std;

//return max of two integers
int max(int a, int b){
    return (a > b) ? a : b;
}

//return the maximum value that can be put in budget
int solution(int budget, int price[], int preference[], int n){
    int i, w;
    int dp[n+1][budget+1];
    //build table dp[][] in bottom up manner
    for(i=0; i<=n; i++){
        for(w=0; w <= budget; w++){
            if(i==0 || w==0){
                dp[i][w] = 0;
            }
            else if(price[i-1] <= w){
                dp[i][w] = max(preference[i-1] + dp[i-1][w-price[i-1]], dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=budget; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][budget];
}

//Driver code
int main(){

    int preference[] = {5, 3, 2, 6};
    int price[] = {4, 2, 3, 5};
    int budget = 10;
    int n = sizeof(preference)/sizeof(preference[0]);

    cout << solution(budget, price, preference, n) << endl;
    return 0;
}