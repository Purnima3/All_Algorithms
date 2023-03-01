/*
Given array arr of N integers. Given Q queries and in each query given L and R print sum of array elements from index L to R


Constraints :

1<= N <= 10^5;
1<=arr[i]<=10^9; // long long
1<=Q<=10^5;
1<=L,R<=N;
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int arr[N];
int prf[N]={0};
//everytime you have been given the 1 based index while using the prefix sum questions because it will make everything easy for you;
int main()
{
     int n;
     cin>>n;
    
    
     for(int i=1;i<=n;i++)
     {
        cin>>arr[i];
     }
     prf[0]=arr[0];
     for(int i=2;i<=n;i++)
     {
        prf[i] = prf[i-1]+arr[i];
     }

     int q;
     cin>>q;
     while(q--)
     {
        int l,r;
        cin>>l>>r;

        long long sum = prf[r] - prf[l-1];
        
       
        cout<<sum<<endl;
     }
    // O(N)+O(N*Q)->10^10 
    //toooooooooooooooooooooooo!!
    //O(N)*O(Q)
}