// Printing Shortest common subsequence

#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int lcs(string x,string y,int m,int n)
{
 int dp[m+1][n+1];
 for(int i=0;i<m+1;i++)
 dp[i][0]=0;
 for(int i=0;i<n+1;i++)
 dp[0][i]=0;
 for(int i=1;i<m+1;i++)
 {
     for(int j=1;j<n+1;j++)
     {
         if(x[i-1]==y[j-1])
         dp[i][j]=1+dp[i-1][j-1];
         else
         {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
         }
         
     }
 }
 int p=m,q=n;
 string k;
 while(p>0||q>0)
 {
     if(p==0)
    {
        k.push_back(y[q-1]);
        q--;
    }
     else if(q==0)
    {
        k.push_back(x[p-1]);
        p--;
    }
    else if(x[p-1]==y[q-1])
    {
        k.push_back(x[p-1]);
        p--;
        q--;
    }
    else
    {
        if(dp[p-1][q]>dp[p][q-1])
        {
            k.push_back(x[p-1]);
            p--;
        }
        else
        {
            k.push_back(y[q-1]);
            q--;
        }
        
        
    }
    
 }
 reverse(k.begin(),k.end());
 cout<<k<<endl;
 return dp[m][n];
}
int main()
{
    string x,y;
    cout<<"Enter the first string"<<endl;
    cin>>x;
    cout<<"Enter the second string"<<endl;
    cin>>y;
    int m=lcs(x,y,x.size(),y.size());
    cout<<m<<endl;
    return 0;
}