// minimum no of insertion  and deletion to  convert string a to string b
# include<stdio.h>
# include<bits/stdc++.h>
using namespace std;
int lcs(string x,string y ,int m,int n)
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
            dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"deletion are"<<m-dp[m][n]<<endl;
    cout<<"Insertion are"<<n-dp[m][n]<<endl;
    return dp[m][n];
}
int main()
{  
    string x, y;
    cout << "Enter the first string" << "\n";
    cin >> x;
    cout << "Enter the second string"<< "\n";
    cin >> y;
    int m = lcs(x, y, x.size(), y.size());
    cout << m << endl;
    return 0;
}