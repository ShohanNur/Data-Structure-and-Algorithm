// If we start traversing from one node in a directed tree,
// how many nodes can we traverse from each traversal? 

#include<bits/stdc++.h>
using namespace std;
#define sz       200000
#define ll       long long
#define pb       push_back
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define mod      1000000007
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)


vector<int> node[100003];
int vis[100003];
int dis[100003];
ll cnt,ans;

void dfs(int x)
{
    cnt++;
    vis[x]=1;
    for(int i=0;i<node[x].size();i++)
    {
        int tmp=node[x][i];
        cout<<tmp<<" "<<x<<endl;
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
    node[x].push_back(y);
   // node[y].push_back(x);
}
    //dfs(1);

for(int i=1;i<=n;i++)
{
     memset(vis,0,sizeof(vis));
        cnt=0;

        dfs(i);
        cout<<i<<" no road visits "<<cnt<<" nodes"<<endl;
        ans+=cnt;

}
cout<<"All possible visited nodes from all nodes "<<ans<<endl;
}
/*
6 5
1 2 
1 3
3 4
3 5
2 6

*/