// minimum no of deletion to make a string a palindrome

# include<stdio.h>
# include<bits/stdc++.h>
using namespace std;
int lcs(string x,string y,int m ,int n )
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
 
 return m-dp[m][n];
}
int main()
{  
    string x, y;
    cout << "Enter the first string" << "\n";
    cin >> x;
    y=x;
    reverse(y.begin(),y.end());
    int m = lcs(x, y, x.size(), y.size());
    cout << m << endl;
    return 0;
}