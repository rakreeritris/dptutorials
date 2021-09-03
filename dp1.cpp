// top down approach
#include<stdio.h>
#include<iostream>
using namespace std;
int mem[5][8];
int knapsack(int*wt,int*val,int W,int n)
{
   if(n==0||W==0)
   {
       return 0;
   }
   if(mem[n][W]!=-1)
   {
       return mem[n][W];
   }
   else if(wt[n-1]<=W)
   {

       mem[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
   }
   else if(wt[n-1]>W)
   {
       mem[n][W]=knapsack(wt,val,W,n-1);
   }
   return mem[n][W];
}
int main()
{  int wt[4]={1,3,4,5};
   int val[4]={2,3,5,9};
   for(int i=0;i<5;i++)
   {
       for(int j=0;j<8;j++)
       {
           mem[i][j]=-1;
       }
   }
    int p=knapsack(wt,val,7,4);
    cout<<p<<endl;
    return 0;
}
