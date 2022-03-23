//divide and conquer approach
#include<iostream>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}
int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i=m; i>=l; i--)
    {
        sum = sum + arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    int  right_sum = INT_MIN;
    for(int i=m+1; i<=h; i++)
    {
        sum = sum + arr[i];
        right_sum = max(right_sum, sum);
    }

    return max(left_sum, right_sum, left_sum+right_sum);
}

int maxSubArraySum(int arr[], int l, int h)
{
    if(l == h)
        return arr[l];
    
    int m = (l+h)/2;
    return max(maxSubArraySum(arr, l, m), 
                maxSubArraySum(arr, m+1, h)),
                maxCrossingSum(arr, l, m, h);
}

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int Max_sum = maxSubArraySum(arr, 0, n-1);
    cout << "The maximum contiguous sum is " << Max_sum << endl;
    return 0;
}