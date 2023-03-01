#include<bits/stdc++.h>
using namespace std;


void adj_from_parent_array(unordered_map<int,vector<int>>&adj , vector<int>& parent)
{
   int n = parent.size();

   for(int i=0;i<n;i++)
   {
    int u = i;
    int v = parent[i];

    adj[u].push_back(v);
    adj[v].push_back(u);
   }

}

void adj_from_edges_array(unordered_map<int,vector<int>>&adj , vector<vector<int>>& edges)
{
   for(auto &vec:edges)
   {
     int u = vec[0];
     int v = vec[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
   }
}

int main()
{
   vector<int>parent;
   unordered_map<int,vector<int>> adj1;
   unordered_map<int,vector<int>> adj2;
    vector<vector<int>> edges;
    cout<<"enter the size of parent array"<<endl;
    int n;
    cin>>n;
    cout<<"enter the elements in the parent array"<<endl;
   for(int i=0;i<n;i++)
   {
    int x;
    cin>>x;
    parent.push_back(x);
   }

 cout<<"enter the number of edges in an array"<<endl;
   int e;
   cin>>e;

  cout<<"enter the edges"<<endl;
  for(int i=0;i<e;i++)
  {
    vector<int>temp;
    int a;
    int b;
    cin>>a;
    cin>>b;
   temp.push_back(a);
   temp.push_back(b);

   edges.push_back(temp);
  }

  adj_from_parent_array(adj1,parent);
  adj_from_edges_array(adj2,edges);

 cout<<"the adjacency list by parent array:"<<endl;
  for(auto it = adj1.cbegin(); it != adj1.cend(); ++it)
{
    cout << it->first << " "<<"->";
    for(int i=0;i < it->second.size();i++)
    {
        cout<<it->second[i]<<" ";
    }
    cout<<endl;

}
cout<<endl;


cout<<"the adjacency list by edges array:"<<endl;
 for(auto it = adj2.cbegin(); it != adj2.cend(); ++it)
{
    cout << it->first << " "<<"->";
    for(int i=0;i < it->second.size();i++)
    {
        cout<<it->second[i]<<" ";
    }
    cout<<endl;
}
  return 0;
}