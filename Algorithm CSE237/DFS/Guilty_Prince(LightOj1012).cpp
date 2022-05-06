#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
char a[22][22];
int vis[22][22];
int n, m ,c;

void dfs(int p, int q)
{
    vis[p][q] = 1;
    c++;
    if(p+1 < n && a[p+1][q] != '#' && !vis[p+1][q])
        dfs(p+1,q);
    if(p-1 >= 0 && a[p-1][q] != '#' && !vis[p-1][q])
        dfs(p-1,q);
    if(q+1 < m && a[p][q+1] != '#' && !vis[p][q+1])
        dfs(p,q+1);
    if(q-1 >= 0 && a[p][q-1] != '#' && !vis[p][q-1])
        dfs(p,q-1);
}


int main()
{
    int  x, y, k = 1;
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>m>>n;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                cin>>a[i][j];
                if(a[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        c = 0;
        dfs(x,y);
        cout<<"Case "<<k++<<": "<<c<<endl;

    }
    return 0;
}