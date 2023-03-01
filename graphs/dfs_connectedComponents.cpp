#include<bits/stdc++.h>
using namespace std;

const int N= 1e5+10;
bool vis[N];

vector<vector<int>>connected_components;
vector<int>current_cc;

void dfs(int vertex)
{
    //take action on vertex after entering into the vertix
    vis[vertex]= true;
    current_cc.push_back(vertex);
  for(int child:g[vertex])
  {
    if(vis[child] == true)continue;
    //take action on child before entering the child node

    dfs(child);
  //take action on child after exiting the child node
  }
  //take action on vertex before exiting the vertex
}
//thime complexity :    o(V+E)

vector<int>g[N];
int main()
{
  int n,m;
  //n->no of vetices and m->number of edges.
  cin>>n>>m;



  for(int i=0;i<m;i++)
  {
    int v1,v2;
    cin>>v1>>v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  int count = 0;
  for(int i = 1;i<n;i++)
  {
    if(vis[i] == true)continue;
    current_cc.clear();
    dfs(i);
   connected_components.push_back(current_cc);
    count++;
  }
  cout<<connected_components.size()<<endl;
  for(auto curr:connected_components)
  {
    for(int vertex:curr)
    {
        cout<<vertex<<" ";
    }
    cout<<endl;
  }
}