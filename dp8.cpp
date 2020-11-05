//coin problem maximum no of ways
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxwayscoinsum(int*coin,int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<sum+1;i++)
    dp[0][i]=0;
     for(int i=0;i<n+1;i++)
    dp[i][0]=1;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
            dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum];
}
int main()
{
    int coin[4]={1,2,3,5};
   int p=maxwayscoinsum(coin,4,8);
   cout<<p<<endl;
    return 0;
}