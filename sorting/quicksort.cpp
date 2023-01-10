#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr ,int l,int r)
{
    int pivot=arr[r];
    int i=l-1;
    for(int j=l; j < r ; j++)
    {
        if(arr[j]<pivot)
        {
        i++;
        swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(vector<int> &arr ,int l,int r)
{
   if(l<r)
   {
    int pi=partition(arr,l,r);

    quickSort(arr,l,pi-1);
    quickSort(arr ,pi+1,r);
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
  
  quickSort(arr,0,n-1);
 
  cout<<"sorted array is"<<endl;

  for(auto x:arr)
  {
    cout<<x<<" ";
  }

}