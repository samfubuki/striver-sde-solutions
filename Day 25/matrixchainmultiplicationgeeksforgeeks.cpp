using namespace std;
int static dp[105][105];
int solve(int arr[], int i, int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp = (solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]);
        mn = min(temp, mn);
    }
 return dp[i][j] = mn;
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(arr, 1, n-1);
        cout<<endl;
    }
	return 0;
}
