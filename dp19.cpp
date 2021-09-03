// matrix chain multiplication
#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int memo[1001][1001];
int mcm(int*arr,int i,int j)
{
    if(i>=j)
    return 0;
    if(memo[i][j]!=-1)
    return memo[i][j];
    int q=INT16_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp<q)
        q=temp;
    }
    return memo[i][j]=q;
}
int main()
{    int arr[5]={40,20,30,10,30};
    memset(memo,-1,sizeof(memo));
     int p=mcm(arr,1,4);
     cout<<p<<endl;
    return 0;
}