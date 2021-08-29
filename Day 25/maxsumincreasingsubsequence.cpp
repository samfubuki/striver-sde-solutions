#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{


	public:
	int maxSumIS(int arr[], int n)
	{
	    int i,j,max=0;
	    int maxis[n];
	    for(int i=0;i<n;i++)
	    {
	        maxis[i]=arr[i];
	    }
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j] && maxis[i]<maxis[j] + arr[i])
	            {
	                maxis[i] = maxis[j] + arr[i];
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(max<maxis[i])
	        {
	            max = maxis[i];
	        }
	    }
	  return max;
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

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];



	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";

    }
    return 0;
}
