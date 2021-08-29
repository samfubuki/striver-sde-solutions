// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]
long long int mergesort1(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right)
{
    long long int i,j,k,inv=0;
    i=left;
    j=mid;
    k=left;
    while((i<=mid-1) && (j<=right))
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv = inv + (mid-i);
        }
    }
    while(i<=mid-1)
    {
      temp[k++] = arr[i++];
    }
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    for(long long int m = left;m<=right;m++)
    {
        arr[m]=temp[m];
    }
  return inv;
}
long long int mergesort(long long int arr[], long long int temp[], long long int left, long long int right)
{
    long long int inv=0;
    if(left<right)
    {
        long long int mid = (left+right)/2;
        inv = inv + mergesort(arr,temp,left,mid);
        inv = inv + mergesort(arr,temp,mid+1,right);
        inv = inv + mergesort1(arr,temp,left,mid+1,right);
    }
  return inv;
}
long long int inversionCount(long long arr[], long long N)
{
  long long int temp[N];
   mergesort(arr,temp,0,N-1);
}


// { Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }

        cout << inversionCount(A,N) << endl;
    }

    return 0;
}
  // } Driver Code Ends
