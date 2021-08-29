// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n)
{
   unordered_map<int, int> mp;
   int maxi=0;
   int sum = 0;
   for(int i=0;i<n;i++)
   {
       sum = sum + A[i];
       if(sum==0)
       {
           maxi=i+1;
       }
       else
       {
           if(mp.find(sum)!=mp.end())
           {
               maxi = max(maxi,i-mp[sum]);
           }
           else
           {
               mp[sum]=i;
           }
       }
   }
  return maxi;
}
