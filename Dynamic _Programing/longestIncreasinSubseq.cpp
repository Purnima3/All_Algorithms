  #include<bits/stdc++.h>
  using namespace std;

int lonIncSub(int i,int arr[],int n,int dp[])
{
    if(dp[i] != -1)return dp[i];
   int ans = 1;//there will be at least 1 longest increasing subsequese and this can never be zero;
   
   for(int j=0;j<i;j++)
   {
     if(arr[i]>arr[j])//the current element can be added to the jth longest subsequence value;
     {
        ans = max(ans,lonIncSub(j,arr,n,dp)+1);
     }
   }
   return dp[i] = ans;
}
   
  int main()
  {
    
    int n;
    cin>>n;
   int arr[n];
   int dp[n+1];
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<n;i++)
   {
     cin>>arr[i];
   }
   int ls = 0;
   for(int i=0;i<n;i++)
   {
      ls = max(ls,lonIncSub(i,arr,n,dp));
   }
   cout<<ls<<endl;
  }
