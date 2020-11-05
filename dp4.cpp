//to divide array in two subsets such that sum of elements of two subsets are equal
#include<stdio.h>
#include<iostream>
using namespace std;
int equalsumpartition(int*arr,int sum,int size)
{
    int ssum[size+1][sum+1];
    for(int i=0;i<sum+1;i++)
    ssum[0][i]=0;
    for(int i=0;i<size+1;i++)
    ssum[i][0]=1;
    for(int i=1;i<size+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                ssum[i][j]=max(ssum[i-1][j-arr[i-1]],ssum[i-1][j]);
            }
            else
            {
                ssum[i][j]=ssum[i-1][j];
            }
        }
    }
    return ssum[size][sum];
}
int main()
{
    int arr[4]={2,5,5,8};
    int sum=0;
    for(int i=0;i<4;i++)
    {
        sum=sum+arr[i];
    }
    if(sum%2!=0)
    cout<<"No"<<endl;
    else
    {
        int p=equalsumpartition(arr,sum/2,4);
        if(p==1)
        cout<<"YES";
        else
        {
            cout<<"NO";
        }
        
    }
    
}