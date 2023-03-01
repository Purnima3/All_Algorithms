#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int h[N];
int dp[N];
int frog1(int i)
{
    if(i==0)return 0;
     int cost = INT_MAX;
    if(dp[i]!=-1)return dp[i];
    
 
 //way 1
 cost = min(cost,frog1(i-1)+abs(h[i] - h[i-1]));
  //way 2
  if(i>1)
 cost = min(cost,frog1(i-2)+abs(h[i] - h[i-2]));
 return dp[i]=cost;
}
int main()
{
  memset(dp,-1,sizeof(dp));
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>h[i];
  }
  cout<<frog1(n-1);
}