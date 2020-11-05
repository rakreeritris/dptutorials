// Mimimum subset sum difference
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int subsetsumdifference(int*arr,int s,int n)
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
        {
            dp[i][j]=max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
        }
        else
        {
            dp[i][j]=dp[i-1][j];
        }     
    }
}
vector<int>vect;
int m=100;
for(int i=0;i<=(s)/2;i++)
{  if(dp[n][i]==1)
    vect.push_back(i);
}
for(int i=0;i<vect.size();i++)
{
    m=min(m,s-2*vect[i]);
}
return m;
}
int main()
{
 int arr[5]={1,2,7,5,5};
 int p=subsetsumdifference(arr,20,5);
 cout<<p<<endl;
 return 0;    
}