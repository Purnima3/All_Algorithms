#include<bits/stdc++.h>
using namespace std;

int func(int amount,vector<int>&coins)
{
   if(amount == 0)return 0;
   int ans = INT_MAX;
   for(int &coin:coins)
  {
    if(amount - coin >=0)
     ans = min((func(amount - coin,coins) + 1),ans);
  }
  return ans;
}

int coinChange(vector<int>&coins,int amount)
{
  int ans = func(amount,coins);
  return ans == INT_MAX ? -1 : ans;
}

int main()
{

}