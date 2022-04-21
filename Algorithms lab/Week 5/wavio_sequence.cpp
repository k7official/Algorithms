#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, a[10100], len1[10100], len2[10100], b[10100];
void L(int len[],int a[])
{
    int dp[10100];
    int t=0;
    dp[t]=-1;
    for(int i=1; i<=n; i++){
        if(a[i]>dp[t]){//If a[i]> the top element of the stack, push the stack
            dp[++t]=a[i];
            len[i]=t;
        }
        else{//If a[i] is not greater than the top element of the stack, binary search for the first element greater than a[i]
            int l=1,r=t;
            while(l<=r){
                int m=(l+r)/2;
                if(a[i]>dp[m])
                    l=m+1;
                else
                    r=m-1;
            }
            //replace a[i]
            dp[l]=a[i];
            len[i]=l;
        }
    }
//    for(int i=1; i<=n; i++)
//        cout<<dp[i]<<" ";
//    cout<<endl;
}
int main(){
    int i, j, s, mmax, ans;
    while(~scanf("%d",&n)){
        for(i=1; i<=n; i++){
            scanf("%d",&a[i]);
            b[n-i+1] = a[i];
            len1[i] = 0;
            len2[i] = 0;
        }
        L(len1,a);
        L(len2,b);
//        for(i=1; i<=n; i++)
//            cout<<len1[i]<<" ";
//        cout<<endl;
//        for(i=1; i<=n; i++)
//            cout<<len2[i]<<" ";
        mmax = -1;
        ans = 0;
        for(i=1; i<=n; i++){
            ans = min(len1[i],len2[n-i+1])*2-1;
            mmax = max(mmax, ans);
        }
        printf("%d\n",mmax);
    }
    return 0;
}
