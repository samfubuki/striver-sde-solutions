// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
      int high = n-1;
      int low=0;
      int mid;
      if(high==0)
      {
          return arr[0];
      }
      else if(arr[0]!=arr[1])
      {
          return arr[0];
      }
      else if(arr[high]!=arr[high-1])
      {
          return arr[high];
      }
      while(low<=high)
      {
          mid = low + (high-low)/2;
          if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])
          {
              return arr[mid];
          }
          if(((mid%2)==0 && arr[mid]==arr[mid+1]) || ((mid%2)==1 && arr[mid]==arr[mid-1]))
          {
              low=mid+1;
          }
          else
          {
              high=mid-1;
          }
      }
     return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }

        Solution ob;

        int res = ob.findOnce(A,n);
        cout << res << endl;
    }

    return 0;
}  // } Driver Code Ends
