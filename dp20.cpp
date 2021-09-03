// Palindrome partitioning recursive...

#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
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
    if(palindrome(s,i,j))
    return 0;
    int q=INT16_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=ppr(s,i,k)+ppr(s,k+1,j)+1;
        if(temp<q)
        q=temp;
    }
    return q;
}
int main()
{   string s="abdeba";
   int p=ppr(s,0,5);
   cout<<p<<endl;
    return 0;
}
