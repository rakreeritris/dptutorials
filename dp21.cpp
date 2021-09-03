// palindrome partitioning memoized and slightly optimized code
#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int memo[1001][1001];
int palindrome(string s,int i,int j)
{
  int c=1;
  while(i<=j)
  {
      if(s[i]!=s[j])
      {
          c=0;
          break;
      }
      i++;
      j--;
  }
  return c;
}
int ppr(string s,int i,int j)
{
    if(i>=j)
    return 0;
    if(memo[i][j]!=-1)
    return memo[i][j];
    if(palindrome(s,i,j))
    return 0;
    int min=INT16_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=1+ppr(s,i,k)+ppr(s,k+1,j);
        if(temp<min)
        min=temp;
    }
    return min;
}
int main()
{
    string s="abdeba";
    memset(memo,-1,sizeof(memo));
    int p=ppr(s,0,s.size()-1);
    cout<<p<<endl;
    return 0;
}