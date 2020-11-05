//count for subset of a particular sum problem
#include<stdio.h>
#include<iostream>
using namespace std;
int countsetsum(int*arr,int n,int s)
{
    int dp[n+1][s+1];
    for(int i=0;i<s+1;i++)
    dp[0][i]=0;
    for(int i=0;i<n+1;i++)
    dp[i][0]=1;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<s+1;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
            {
                dp[i][j]=dp[i-1][j];
            }  
            cout<<dp[i][j]<<" ";          
        }
        cout<<endl;
    }
    return dp[n][s];
}
int main()
{
    int arr[5]={1,1,2,3};
    int p=countsetsum(arr,4,7);
    cout<<p<<endl;
}