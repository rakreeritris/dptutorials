#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 int eboparen(string s,int i,int j,bool istrue)
 {
     if(i>j)
     return 0;
     if(i==j)
     {
         if(istrue==true)
         {
             if(s[i]=='T')
             return 1;
             else
             {
                 return 0;
             }
             
         }
         else
         {
              if(s[i]=='F')
             return 1;
             else
             {
                 return 0;
             }
         }
         
     }
     int ans=0;
     for(int k=i+1;k<=j-1;k+2)
     {
        int lt=eboparen(s,i,k-1,true);
        int lf=eboparen(s,i,k-1,false);
        int rt=eboparen(s,k+1,j,true);
        int rf=eboparen(s,k+1,j,false);
        if(s[k]=='|')
        ans=ans+lt*rt+lt*rf+rt*lf;
        else if(s[k]=='&')
        ans=ans+lt*rt;
        else if(s[k]=='^')
        ans=ans+lt*rf+lf*rt;
     }
     return ans;
}
 int main()
 {   string s="T|T&F^T";
     cout<<"Hello"<<endl;
      cout<<eboparen(s,0,7,true)<<endl;
     return 0;
 }





