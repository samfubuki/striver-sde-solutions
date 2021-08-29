// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
   bool ispalindrome(string s , int i, int j)
   {
       if(i==j)
       {
           return true;
       }
       if(i>j)
       {
           return true;
       }
       while(i<j)
       {
           if(s[i]!=s[j])
           {
               return false;
           }
           i++;
           j--;
       }
     return true;
   }
    int solve(string s, int i, int j)
    {
        int static t[501][501];
        memset(t,-1,sizeof(t));
        if(i>=j)
        {
            return 0;
        }
        if(ispalindrome(s,i,j)==true)
        {
            t[i][j]=0;
            return 0;
        }
        //int static t[501][501];
        //memset(t,-1,sizeof(t));
        int mn = INT_MAX;
        int left,right;
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        for(int k=i;k<=j-1;k++)
        {
           if(t[i][k]!=-1)
           {
              left = t[i][k];
           }
           else
           {
               left = solve(s,i,k);
               t[i][k]=left;
           }
           if(t[k+1][j]!=-1)
           {
               right = t[k+1][j];
           }
           else
           {
               right = solve(s,k+1,j);
               t[k+1][j] = right;
           }
          int temp = 1 + left + right;
          if(temp<mn)
          {
              mn=temp;
          }
        }

     return t[i][j]=mn;
    }
    int palindromicPartition(string str)
    {
        return solve(str,0,str.length()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;

        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
