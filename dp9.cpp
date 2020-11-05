//Minimum no of ways for getting sum
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mininoofcoins(int*coin,int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<sum+1;i++)
    dp[0][i]=9999;
    for(int i=1;i<n+1;i++)
    dp[i][0]=0;
    for(int i=1;i<sum+1;i++)
    {
        if(i%coin[0]==0)
        dp[1][i]=i/coin[0];
        else
        dp[1][i]=9999;
    }
    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
            dp[i][j]=min(1+dp[i-1][j-coin[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int coin[3]={2,3,5};
    cout<<mininoofcoins(coin,3,8);
}