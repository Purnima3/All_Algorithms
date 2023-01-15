#include<bits/stdc++.h>
using namespace std;


 void bfs(int u,vector<int>&ans,vector<bool>&vis, unordered_map<int,vector<int>>&adj)
    {
        
        queue<int>q;
        
        q.push(u);
        vis[u]=true;
        
        while(!q.empty())
        {
           int u=q.front();
           q.pop();
           ans.push_back(u);
           
           for(auto &v:adj[u])
           {
               if(vis[v] == false)
               {
                   vis[v]=true;
                   q.push(v);
               }
           }
        }
        
    }

 void DFS(  unordered_map<int,vector<int>>&adj, int u  ,  vector<bool>&vis , vector<int>&result)
     {
         if(vis[u] == true)return;
         
         vis[u] = true;
         result.push_back(u);
         for( auto &v: adj[u])
         {
             if(!vis[v])
             {
                 DFS(adj , v ,vis , result);
             }
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
   unordered_map<int,vector<int>> adj;
    vector<vector<int>> edges;
   

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

  
  adj_from_edges_array(adj,edges);

    vector<int>result;
     vector<bool>vis(e+1, false);
        
        DFS(adj, 0 , vis , result);
      
      for(int i=0;i<result.size();i++)
      {
        cout<<result[i]<<" ";
      }
  
      cout<<endl;
        vector<int>ans;

        vector<bool>visi(e+1,false);

        bfs(0,ans,visi,adj);


        for(int i=0;i<ans.size();i++)
      {
        cout<<ans[i]<<" ";
      }
  return 0;
}