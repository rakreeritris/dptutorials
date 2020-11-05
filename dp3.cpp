//subset sum problem
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int subsetsum(int*arr,int n,int s)
{
    int ssum[n+1][s+1];
    for(int i=0;i<s+1;i++)
    ssum[0][i]=0;
    for(int i=0;i<n+1;i++)
    ssum[i][0]=1;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<s+1;j++)
        {
            if(arr[i-1]<=j)
            ssum[i][j]=max(ssum[i-1][j-arr[i-1]],ssum[i-1][j]);
            else
            ssum[i][j]=ssum[i-1][j];
        }
    }
    return(ssum[n][s]);
}
int main()
{
    int set[5]={2,3,7,8,10};
    int p=subsetsum(set,5,11);
    if(p==1)
    cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
