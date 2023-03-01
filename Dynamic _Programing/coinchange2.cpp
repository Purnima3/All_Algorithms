#include<bits/stdc++.h>
using namespace std;


//here if we will use the basic apprach ad the coin chanf=ge 1 then we will encounter some problem .

//as there will be many duplicates.
//so if we will move like basic recursion substracting 1 ans then again checking one by one until it becomes 0 then we will get wrong ans;
int func2(int ind,int amount,vector<int>&coins)
{
   if(amount == 0)return 0;
    if(ind < 0 )return 0;
 
   
     
 
}

int coinChange(vector<int>&coins,int amount)
{
  int ans = func(amount,coins);
  return ans == INT_MAX ? -1 : ans;
}

int main()
{

}