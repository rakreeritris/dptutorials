//Top down approach
#include<stdio.h>
#include<iostream>
using namespace std;
int knapsack(int*wt,int*val,int W,int n)
{
    int t[5][8];
    for(int i=0;i<5;i++)
    t[i][0]=0;
    for(int i=0;i<8;i++)
    t[0][i]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else
            {
            t[i][j]=t[i-1][j];
            }
            
        }
    }
return t[n][W];
}
int main()
{  int wt[4]={1,3,4,5};
   int val[4]={2,3,5,9};
    int p=knapsack(wt,val,7,4);
    cout<<p<<endl;
    return 0;
}