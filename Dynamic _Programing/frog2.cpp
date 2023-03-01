#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int h[N];
int dp[N];
int k;
int frog2(int i)
{
    if(i==0)return 0;
     int cost = INT_MAX;
    if(dp[i]!=-1)return dp[i];
    
 for(int j=1;j<=k;j++)
 {
 //we will have k- ways here
    if(i-j >= 0)
     cost = min(cost,frog2(i-j)+abs(h[i] - h[i-j]));

 }
  
 return dp[i]=cost;
}
int main()
{
  memset(dp,-1,sizeof(dp));
  int n;
  cin>>n;
  cin>>k;
  for(int i=0;i<n;i++)
  {
    cin>>h[i];
  }
  cout<<frog2(n-1);
}