#include<bits/stdc++.h>
using namespace std;

const int N= 1e5+10;
bool vis[N];

vector<int>g[N];

bool dfs(int vertex,int par)
{
   vis[vertex] = true;
  bool isLoop = false;
   for(auto child:g[vertex])
   {
     if(child == par)continue;
     if(vis[child])return true;

     isLoop |= dfs(child,vertex);
   }

   return isLoop;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2; 
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }

bool isLoopExist = false;
     for(int i=1;i<n;i++)
     {
        if(vis[i])continue;
        if(dfs(i,0))
       { 
        isLoopExist = true; 
            break;
        }
      
     }

     cout<<isLoopExist<<endl;


}