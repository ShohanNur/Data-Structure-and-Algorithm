/*
2 nodes are given a and b. Find out, if one node b lies under a subtree of node a [a = root , b = children]

*/
//cycle detection by DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[100003];
int vis[100003];
int dis[100003];
int Intime[100003];
int Outtine[100003];
int Time=1;
void dfs(int node)
{
    vis[node]=1;
    Intime[node]=Time;
    Time++;
    for(int i=0;i<graph[node].size();i++)
    {
        int child=graph[node][i];
        if(!vis[child]){
            dfs(child);
        }
    }

    Outtine[node]=Time;
    Time++;
}
int main()
{
int n,e;
cin>>n>>e;
while(e--)
{
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    //graph[y].push_back(x);
}
int a,b;
cin>>a>>b;
dfs(1);
if(Intime[a]<Intime[b] && Outtine[a]>Outtine[b]){
    cout<<"YES b lies under a subtree of a"<<endl;
}
else{
      cout<<"NO b does not under a subtree of a"<<endl;
}

}
/*
6 5
1 3
3 4
3 5
1 2
2 6
3 4
*/
