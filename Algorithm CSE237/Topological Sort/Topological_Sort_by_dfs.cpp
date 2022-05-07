//Topological Sort by DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> node[100003];
vector<int> result;
int vis[100003];
int dis[100003];
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<node[x].size();i++)
    {
        int tmp=node[x][i];
        if(!vis[tmp])
        {
            dfs(tmp);
        }
    }
    result.push_back(x);
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
  
}
for(int i=1;i<=n;i++)
{
    if(!vis[i])
    {
        dfs(i);
    }
}
reverse(result.begin(),result.end());


for(int i=0;i<result.size();i++)
{
    cout<< result[i]<<" ";
}
cout<<endl;
}

/*
7 6
1 2
2 3
2 4
1 5
5 6
5 7
*/