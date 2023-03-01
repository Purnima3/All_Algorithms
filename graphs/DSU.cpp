#include<bits/stdc++.h>
using namespace std;


  vector<int>rankk;
  vector<int>parent;
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
 
int find(int i)
{
    if(i == parent[i])return i;

    else return parent[i]=find(parent[i]);//this is the process of compression
}

void uni(int x,int y)
{
      int x_parent = find(x);
      int y_parent = find(y);
      
      if(x_parent == y_parent)return;

      if(rankk[x_parent] > rankk[y_parent])
      {
        parent[y_parent]=x_parent;
      }

      else if(rankk[x_parent] < rankk[y_parent])
      {
        parent[x_parent]=y_parent;
      }

      else{
        parent[x_parent]=y_parent;
        rankk[y_parent]+=1;
      }
}

void DFS(  unordered_map<int,vector<int>>&adj, int u , vector<bool>& is_active)
     {
         for( auto &v:adj[u])
         {
           if(is_active[v])
          {
            uni(u,v);
          }
         }
         is_active[u] = true;
     }
  
int main()
{
   unordered_map<int,vector<int>> adj;
     vector<vector<int>> edges;
    
    int n;
 
      cout<<"enter the number of edges in an array"<<endl;
   int e;
   cin>>e;
   n=e+1;
    parent.resize(n);
     rankk.resize(n,1);
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

      for(int i=0;i<n;i++)
      {
        parent[i] = i;
      }

       for(int i=0;i<n;i++)
    {
      cout<<parent[i]<<" ";
    }
    cout<<endl;
     
    adj_from_edges_array(adj,edges);

    vector<bool> is_active(n,false);
     
    DFS(adj,0,is_active);

    for(int i=0;i<n;i++)
    {
      cout<<parent[i]<<" ";
    }
   
}
