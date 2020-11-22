//Longest common subsequence using memoization
#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int dp[1001][1001];
int LCS(string x,string y,int m,int n)
{ 
    if(m==0||n==0)
    return 0;
    if(dp[m][n]!=-1)
    return dp[m][n];
    else if(x[m-1]==y[n-1])
    return (dp[m][n]=1+LCS(x,y,m-1,n-1));
    else 
    return(dp[m][n]=max(LCS(x,y,m-1,n),LCS(x,y,m,n-1)));

}
int main()
{  string x;
   string y;
   cout<<"Enter the first string"<<"\n";
   cin>>x;
   cout<<"Enter the second string"<<"\n";
   cin>>y;
   for(int i=0;i<x.size()+1;i++)
   {
       for(int j=0;j<y.size()+1;j++)
       dp[i][j]=-1;
   }
   int longest=LCS(x,y,x.size(),y.size());
   cout<<longest<<endl;
        return 0;
}