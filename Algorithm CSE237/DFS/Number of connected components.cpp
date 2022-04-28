#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[100003];
int vis[100003];
int dis[100003];
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<graph[x].size();i++)
    {
        int tmp=graph[x][i];
        if(!vis[tmp])
        {
            dfs(tmp);
        }
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
    graph[x].push_back(y);
    graph[y].push_back(x);
}
    //dfs(1);
int c=0;
vector<int>vec;
for(int i=1;i<=n;i++)
{
    if(!vis[i])
    {
        vec.push_back(i);
        c++;
        dfs(i);
    }
}
cout<<c<<endl;

}
/*
6 5
1 2 
1 3
3 4
3 5
2 6
*/