//DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> node[100003];
int vis[100003];
int dis[100003];

int dfs(int x)
{
    
    vis[x]=1;
    int currentSize = 1;
    dis[x] = 1;
    for(int i=0;i<node[x].size();i++)
    {
        int tmp=node[x][i];
        if(!vis[tmp])
        {
            currentSize^=dfs(tmp);
        }
    }
    dis[x] = currentSize;
    return currentSize;

}
int main()
{
int n,e;

cin>>n;
e = n-1;
while(e--)
{
    int x,y;
    cin>>x>>y;
    node[x].push_back(y);
    node[y].push_back(x);
}

dfs(1);

for(int i=1;i<=n;i++)
{
    cout<<dis[i]<<" ";
}
}
/*
6 5
1 2 
1 3
3 4
3 5
2 6

*/
