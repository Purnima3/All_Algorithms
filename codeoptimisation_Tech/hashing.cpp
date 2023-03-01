/*
Given array a of n integers.Given Qwueries and in each query given a number X,print count of that number in an array;

constraints:
1<=N<=10^5
1<=a[i]<=10^7
1<=Q<=10^5
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   int Q[n];
   
    int queries;
    cin>>queries;
    //this is hasharray
  int count[N];//koi bhi global array kabi bi 0 initialized hota h
  int ct =0;
  for(int i=0;i<N;i++)
        count[arr[i]]++;
    
    while(queries--)
    {
        int x;
        cin>>x;
        cout<<count[x]<<endl;
    }

    //O(N)+O(Q*N);  O(n2)
   // toooooooooooo!!!!!!!!!!!
    //O(N);
}