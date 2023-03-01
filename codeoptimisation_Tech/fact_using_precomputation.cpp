/* givrn t test cases and in each test cases a number n.print its factorial where m=10^9+7

constraints -
1 <= T<=10^5
1 <= N<=10^5
*/
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
const int N = 1e5+7;

long long fact[N];

int main()
{  //this is called precomputation     techniques.
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout << fact[n] <<endl;
    }
    //  O(T*N)  O(10*10);
    //O(T)
}
