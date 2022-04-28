//DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> node[100003];
int vis[100003];
int dis[100003];
int discoveryTime[100003];
int finishingTime[100003];
int Time = 1;
void dfs(int x)
{
    discoveryTime[x] = Time;
    Time++;
    vis[x]=1;
    for(int i=0;i<node[x].size();i++)
    {
        int tmp=node[x][i];
        if(!vis[tmp])
        {
            dfs(tmp);
        }
    }
    finishingTime[x] = Time;
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
    node[x].push_back(y);
    //node[y].push_back(x);
}

dfs(1);
int c=0;
for(int i=1;i<=n;i++)
{
    //dfs(i);
     cout << "Node " << i << " Discovery Time "
             << discoveryTime[i] << " Finishing number "
             << finishingTime[i] << endl;
}
//cout<<c<<endl;
}
/*
6 5
1 2 
1 3
3 4
3 5
2 6

*/
