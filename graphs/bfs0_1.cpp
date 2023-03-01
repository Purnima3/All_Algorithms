#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>>g[N];//representation of weighted. graph 

vector<int> lev(N,INF);//fill all the levels as infinity because we will have to play with these levels.

int n,m;//n vertices,m vertices.

//here dequeue will be used why? because we have to insert at the front as well as back of the queue.

// 0 -> insert at the front
// 1 -> inser at the back 

int bfs()
{
  deque<int>q;
  q.push_back(1);
  lev[1]=0;

  while(!q.empty())
  {
    int curr_node = q.front();
    q.pop_front();

    for(auto child:g[curr_node])
    {
        int child_v = child.first;
        int wt = child.second;

         //initially the weight of the child node will be infinity 
         //if(wt+lev[curr_node]<infinity) then we are adding 1 to the level of current node;

         if(lev[curr_node] + wt < lev[child_v])
         {
            lev[child_v] = lev[curr_node]+wt;

            if(wt == 1)//1 h to queu k back mn daal dia 
            {
                q.push_back(child_v);
            }
            else{
                q.push_front(child_v);
            }
         }
    }
  }
  return lev[n] == INF ? -1 : lev[n];//the last will have  the shortest path in the last level. 
}


int main()
{
  //in 0/1 bfs there is no need for  visited array
   cin>>n>>m;

   for(int i=0;i<m;i++)
   {
    int x,y;
    cin>>x>>y;
    if(x == y)continue;//no eges will be added in case of loops.
    g[x].push_back({y,0});//this is the given edges we will put their weight as 0
    g[y].push_back({x,1});//thisis the revese edge which we have ourselves made and given it the weight of 1
   }
   
   cout<<bfs()<<endl;
}
