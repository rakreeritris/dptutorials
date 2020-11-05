//count the number of subets with a given difference
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countsubsetdiff(int *arr,int n,int s,int s1)
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
          dp[i][j]=dp[i-1][j];
          cout<<dp[i][j]<<" ";
      }
      cout<<endl;
  } 
  return dp[n][s1];
}
int main()
{//s1-s2=diff
//s1+s2=sumof arrayelements

    int a[4]={1,1,3,2};
    int diff=1;
    int s1=(diff+7)/2;
    int p=countsubsetdiff(a,4,7,s1);
    cout<<p<<endl;
    return 0;

}