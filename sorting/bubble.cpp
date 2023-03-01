#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &arr ,int n)
{
     int count=1;
     while(count < n){
     for(int i=0;i<n-count;i++)
     {
        if(arr[i] > arr[i+1])
        {
            int temp=arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
     }
     count++;
     }
}

int main()
{
    int n;
    cout<<"enter the number of elements in array"<<endl;
    cin>>n;
    vector<int> arr;
   cout<<"enter the elements:"<<endl;
    for(int i=0;i<n;i++)
    { 
        int x;
        cin>>x;
        arr.push_back(x);
    }
  
  bubblesort(arr,n);
 
  cout<<"sorted array is"<<endl;

  for(auto x:arr)
  {
    cout<<x<<" ";
  }

}