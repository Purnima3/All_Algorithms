#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr ,int l,int r,int mid)
{
    int l1=mid-l+1;
    int l2=r-mid;

   int a1[l1];
   int a2[l2];

   for(int i=0;i<l1;i++)
   {
       a1[i]=arr[l+i];
   }

   for(int i=0;i<l2;i++)
   {
       a2[i]=arr[mid+1+i];
   }

   int i=0;
   int j=0;
   int k=l;

   while(i<l1 && j<l2)
   {
    if(a1[i]<a2[j])
    {
        arr[k]=a1[i];
        k++;
        i++;
    }
    else{
        arr[k]=a2[j];
        k++;
        j++;
    }
   }

   while(i<l1)
   {
     arr[k]=a1[i];
        k++;
        i++;
   }
  
  while(j<l2)
  {
     arr[k]=a2[j];
        k++;
        j++;
  }
}
void mergeSort(vector<int> &arr ,int l,int r)
{
   if(l<r)
   {
    int mid = (l+r)/2;

    mergeSort(arr ,l,mid);
    mergeSort(arr ,mid+1,r);


    merge(arr,l,r,mid);

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
  
  mergeSort(arr,0,n-1);
 
  cout<<"sorted array is"<<endl;

  for(auto x:arr)
  {
    cout<<x<<" ";
  }

}