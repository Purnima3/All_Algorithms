#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    int fac=1;
    for(int i=1;i<=n;i++)
    {
        fac=fac*i;
    }
    return fac;
}

int fibonacci(int n)
{
    int f1=0;
    int f2=1;
  for(int i=2;i<n;i++)
    {
        int c=f1+f2;
    f1=f2;
    f2=c;
    }

    return f2;
}

int main()
{
    int n1,n2;
    cout<<"enter the number you want factorial of:";
    cin>>n1;
    int ans1=fact(n1);
    cout <<"enter the number you want fibonacci no of:";
    cin>>n2;
    int ans2=fibonacci(n2);

    cout<<"the factorial of "<<n1<<" is:"<<ans1<<endl;
    cout<<"the fibonacci of "<<n2<<" is:"<<ans2;

}
