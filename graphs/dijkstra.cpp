#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

//for weighted graph we store pair<int,int>
vector<pair<int,int>>g[N];

void dijkstra(int source)
{
   vector<int> vis(N,0);
   vector<int> dist(N,INF);
   //ek list of elements h jismen se humen minimum chahiye.

   set<pair<int,int>>st;//<weight,node> wieght k hisab se sorted chahiye set.

   st.insert({0,source});
   dist[source] = 0;

   while(st.size() > 0)
   {
       auto node = *st.begin(); //to find out the minimum element from the set.
       int v = node.second;
       int distance = node.first;
       st.erase(st.begin());
       if(vis[v])continue;
         vis[v]=1;
       for(auto &child:g[v])
       {
          int child_v = child.first;
          int wt = child.second;
          if(dist[v] + wt < dist[child_v])
          {
            dist[child_v] = dist[v] + wt;
            st.insert({dist[child_v], child_v});
          }
       }

   }


}

int main()
{
   int n,m;//n vertices and m edges;

   for(int i=0;i<m;i++)
   {
    int x,y,wt;
    cin>>x>>y>>wt;
    g[x].push_back({y,wt});

   }

}