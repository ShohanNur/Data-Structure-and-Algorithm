//cycle detection by DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[100003];
int vis[100003];
int pathvis[100003];
int dis[100003];
vector<pair<int, int>>backEdge;
bool dfs(int node)
{
    vis[node] = 1;
    pathvis[node] = 1;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        if (!vis[child] == 0)
        {
            if (dfs(child) == true) {
                return true;
            }
        } 
        // if the node had been visited previously visited 
        //but it has to be visited on the same path
        else if (pathvis[child]) {
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        //graph[y].push_back(x);
    }
    int sr;
    cin >> sr;
    if (dfs(sr)) {

        cout << "Cycle Detected!" << endl;
    }
    else {
        cout << "No cycle!" << endl;
    }

}
/*
4 4
1 2
2 3
3 4
4 1
1
*/
