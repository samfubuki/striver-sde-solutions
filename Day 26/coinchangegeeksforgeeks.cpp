sing namespace std;
int main() {
 int t;
 cin>>t;
 while(t--)
 {
     int n;
     cin>>n;
     int coin[n+1];
     coin[0]=0;
     for(int i=1;i<=n;i++)
     {
         cin>>coin[i];
     }
     int sum;
     cin>>sum;
     int t[n+1][sum+1];
     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=sum;j++)
         {
             if(i==0 && j==0)
             {
                 t[i][j]=1;
             }
             else if(i==0 && j>0)
             {
                 t[i][j]=0;
             }
             else
             {
                 if(coin[i]>j)
                 {
                     t[i][j] = t[i-1][j];
                 }
                 else
                 {
                     t[i][j] = t[i-1][j] + t[i][j-coin[i]];
                 }
             }
         }
     }
 cout<<t[n][sum];
 cout<<endl;
 }
}
