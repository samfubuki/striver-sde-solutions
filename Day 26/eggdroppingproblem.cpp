#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to get minimum number of trials needed in worst
  case with n eggs and k floors */
static int t[11][51];
int solve(int e , int f)
{
    if(f==0 || f==1)
    {
        return f;
    }
    if(e==1)
    {
        return f;
    }
    if(t[e][f]!=-1)
    {
      return t[e][f];
    }

    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));
        mn = min(mn,temp);
    }
 return t[e][f]=mn;
}
int eggDrop(int n, int k)
{
   memset(t,-1,sizeof(t));
   return solve(n,k);
}

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
