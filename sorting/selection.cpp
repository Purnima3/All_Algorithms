#include<bits/stdc++.h>
using namespace std;

void selectionsort(vector<int> &arr ,int n)
{
    
     for(int i=0;i<n-1;i++)
     {
        for(int j=i+1;j<n;j++)
       { 
        if(arr[j] < arr[i])
        {
            int temp=arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        }
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
  
  selectionsort(arr,n);
 
  cout<<"sorted array is"<<endl;

  for(auto x:arr)
  {
    cout<<x<<" ";
  }

}