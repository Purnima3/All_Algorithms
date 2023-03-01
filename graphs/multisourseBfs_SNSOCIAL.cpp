#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int INF = 1e9+10;

int val[N][N];
int vis[N][N];
int lev[N][N];

int n,m;

vector<pair<int,int>>movement ={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

bool isValid(int i,int j)
{
   return i>=0 && j>=0 && i<n && j<m;
}


int bfs()
{
    int max_val=0;
    for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            max_val = max(max_val,val[i][j]);
        }
     }

     queue<pair<int,int>>q;

     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
           if(max_val == val[i][j])
           {
            q.push({i,j});
            lev[i][j]=0;//for all the sources the level will be zero;
            vis[i][j]=1;
           }
        }
     }
    
    int ans = 0;
     while(!q.empty())
     {
        auto u = q.front();
        int x = u.first;
        int y = u.second;
        q.pop();

        for(auto &mov:movement)
        {
           int child_x = mov.first + x;
           int child_y = mov.second + y;
           if(!isValid(child_x,child_y))continue;
           if(vis[child_x][child_y])continue;

           q.push({child_x,child_y});
           lev[child_x][child_y] = lev[x][y] + 1;
           vis[child_x][child_y] = 1;

           //while updating the level;
           ans = max(ans , lev[child_x][child_y]);
        }
     }
     return ans;
}
//this fuction will reset the level array and the visited array for every source bfs;
void  reset(){
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=0;
            lev[i][j]=INF;
        }
     }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        reset();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    cin>>val[i][j];
            }
        }
        cout<<bfs()<<endl;
    }

} 