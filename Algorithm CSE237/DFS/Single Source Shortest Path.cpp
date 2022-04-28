//sssp by DFS (only for tree) N:B = (will not give exact result if tree has a cycle)
//how much cost needed to visit each nodes from a single node?
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> node[100003];
int vis[100003];
int dis[100003];
int path[100003];
void dfs(int x , int cost)
{
    vis[x]=1;
    dis[x]=cost;
    //int costu= cost;
    for(int i=0;i<node[x].size();i++)
    {
        int tmp=node[x][i];
       // cout<<tmp<<" \n"[i==node[x].size()-1];
        if(!vis[tmp])
        {
             //dis[tmp] = cost+1;
             //cost++;
             dfs(tmp,cost+1);

        }
        //cost = costu;
    }
}
int main()
{
int n,e;
cin>>n>>e;
while(e--)
{
    int x,y;
    cin>>x>>y;
    node[x].push_back(y);
    node[y].push_back(x);
}
    dfs(2,0);
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" \n"[i==n];
    }

}
/*
6 5
1 2
2 3
2 4
4 5
4 6
*/
