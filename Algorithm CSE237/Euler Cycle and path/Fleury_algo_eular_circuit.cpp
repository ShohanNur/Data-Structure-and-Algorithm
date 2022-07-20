#include<bits/stdc++.h>

#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1e18
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;

int graph[101][101];
int vis[200];
int n,m;
vector<pair<int,int>>ans;

int dfs(int x){
    vis[x]=1;
    int cnt=1;

    for(int i=1;i<=n;i++){
        
        if(!vis[i] && graph[x][i]){
            cnt+=dfs(i);
        }
    }
    return cnt;

}


bool isValid(int par, int child){
      memset(vis,0,sizeof vis);

      int cnt1 = dfs(par);
  
      graph[par][child]=0;
      graph[child][par]=0;
      memset(vis,0,sizeof vis);
      
      int cnt2 = dfs(par);
      
      graph[par][child]=1;
      graph[child][par]=1;
     // cout<<cnt1<<"xxx"<<cnt2<<endl;
      if(cnt1!=cnt2){
        return 0;
      } 
      else{
        return 1;
      }

}
void eularTraverse(int x){
   
   for(int i=1;i<=n;i++){
       if(graph[x][i] && isValid(x,i)){
          graph[x][i] = 0;
          graph[i][x] = 0;
          ans.pb({x,i});
          //cout<<x<<" "<<i<<endl;
          eularTraverse(i);
       }
   }

   for(int i=1;i<=n;i++){
      if(graph[x][i]){
          graph[x][i] = 0;
          graph[i][x] = 0;
          //cout<<x<<" "<<i<<endl;
          ans.pb({x,i});
          eularTraverse(i);
      }
   }


}

int main(){
    cin>>n>>m;

    for(int i=1;i<=m;i++){
       int x,y;
       cin>>x>>y;
       graph[x][y]=1;
       graph[y][x]=1;
    }

    int x=1;
    int odd=0;
    for(int i=1;i<=n;i++){
      int deg=0;
      for(int j=1;j<=n;j++){

          if(graph[i][j]){
              deg++;
          } 
      }
      if(deg%2){
         odd++; 
         x = i;
      }
    }
    if(odd==1 || odd>2){
      cout<<"No Euler circuit exist!\n";
    }
    else{
    eularTraverse(x);
      for(auto i:ans){
        cout<<i.f<<" "<<i.s<<endl;
      }
   }

}