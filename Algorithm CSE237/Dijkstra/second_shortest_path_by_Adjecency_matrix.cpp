#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sz 102
#define inf (1<<20)

vector<int> adj[sz],weight[sz],s;
int dis[sz],par[sz],node;
int graph[sz][sz];
bool vis[sz];
int ans=inf;

void dijkstra(int src,int val)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    pq.push({0,src});
    dis[src]=0;

    while(!pq.empty())
    {
        int c=pq.top().first;// cost of parent
        int u=pq.top().second;//parent node
        pq.pop();

        for(int i=0;i<node;i++) //iterate over all nodes in matrix
        {
            if(graph[u][i]){
                if(i==node-1)
                {
                    if(c+graph[u][i]<dis[i] && c+graph[u][i]>val)
                    {
                        dis[i]=c+graph[u][i];
                        par[i]=u;
                        pq.push({dis[i],i});
                    }
                }
                else if(c+graph[u][i]<dis[i])
                {
                    dis[i]=c+graph[u][i];
                    par[i]=u;
                    pq.push({dis[i],i});
                }
            }
        }
    }

    if(ans>dis[node-1])
    {
        ans=dis[node-1];
        while(s.size()!=0) s.pop_back();
        int x=node-1;
        while(x!=-1){
            s.push_back(x);
            x=par[x];
        }
        reverse(s.begin(),s.end());
    }

}


void init(int n)
{
    for(int i=0;i<n;i++){
        dis[i] = inf;
        par[i] = -1;
        vis[i] = false;
    }
}

void printgraph()
{
    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
            cout << graph[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    int edges,src;
    cin >> node >> edges >> src;


    for(int i=0;i<edges;i++)
    {
        int u,v,x;
        cin >> u >> v >> x;
        graph[u][v]=x;
        graph[v][u]=x;
    }

    init(node);

    
    dijkstra(0,0);

    int distance = dis[node-1];

    // cout << ans[0] << ' ' << distance << endl;

    cout << "1st Shortest Path distance: ";
    cout << distance << endl << "Path : ";
    
    ans=inf;
    

    vector<int> path;
    int x=node-1;
    while(x!=-1){
        path.push_back(x);
        x=par[x];
    }
    reverse(path.begin(),path.end());

    for(int i:path) cout << i << " ";cout << endl;

    
    for(int p=1;p<path.size();p++)
    {
        int i=path[p-1],j=path[p];
        if(graph[i][j])
        {
            // cout << "Path " << i << " " << j << endl;
            int x=graph[i][j];
            graph[i][j]=graph[j][i]=0;
            // printgraph();
            init(node);
            //cout<<distance<<endl;
            dijkstra(0,distance);
            // cout << endl;
            graph[i][j]=graph[j][i]=x;
        }
    }

    cout << "2nd Shortest Path distance: ";
    cout << ans << endl << "Path : ";

    // for(int i:s[node-1]) cout << i << ' ' ;cout << endl;
    for(int i:s) cout << i << " ";cout << endl;

    return 0;
}

/**

4 4 0
0 1 24
0 3 20
2 0 3
3 2 12

5 7 2
0 1 3
0 2 1
1 2 7
1 3 5
1 4 1
2 3 2
3 4 7

5 7 0
0 1 10
0 2 1
1 2 7
1 3 5
1 4 1
2 3 2
3 4 7

7 10 0
0 2 1
0 3 6
1 5 1
3 1 2
1 6 5
2 5 8
2 3 2
4 3 9
4 5 2
6 4 1
*/