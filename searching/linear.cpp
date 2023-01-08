#include<iostream>
using namespace std;
int linearSearch (int*, int,int);
int main()
{
    int n=0;
    cout<<"enter the size of your array"<<endl;
    cin >> n;
    int arr[n];
   cout<<"enter the elements";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
     int k=0;
     cout<<"enter the element you want to find"<<endl;
     cin>>k;
    int ans=linearSearch(arr,n,k);
    if(ans!=-1){
    cout<<"the element is fount in the index:"<<ans;}
    else{
        cout<<"element is not found";
    }
}

int linearSearch (int arr[], int n,int k){

   for(int i=0;i<n;i++)
   {
      if(arr[i] == k)return i;
   }

   return -1;
}