#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
const int N=5e5+9;
#define saiful_islam_bk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int LOG=20;
int timer=0;
vector<vector<int>>g(N, vector<int>());
vector<int>tin(N, 0), tout(N, 0), dis(N, 0);
vector<vector<int>>up(N, vector<int>(LOG, -1));
void dfs(int u, int p=-1){
  tin[u]=++timer;
  if(p!=-1) dis[u]=dis[p]+1;
  up[u][0]=p;
  for(int i=1; i<LOG; i++) if(up[u][i-1]!=-1) up[u][i]=up[up[u][i-1]][i-1];
  for(auto c:g[u]){
    if(c!=p) dfs(c, u);
  }
  tout[u]=++timer;
}
bool is_ancestor(int u, int v){
  return tin[u]<=tin[v] && tout[u]>=tout[v];
}
int lca(int u, int v){
  if(is_ancestor(u, v)) return u;
  if(is_ancestor(v, u)) return v;
  for(int i=LOG-1; i>=0; i--){
    if(up[u][i]!=-1 && !is_ancestor(up[u][i], v)) u=up[u][i];
  }
  return up[u][0];
}
int distance(int u, int v){
  int L=lca(u, v);
  return dis[u]+dis[v]-2*dis[L];
  // return (tin[u]-tin[L])/2+(tin[v]-tin[L])/2;
}
int kth_ancestor(int u, int k){
  for(int i=LOG-1; i>=0; i--){
    if(k>=(1<<i)){
      u=up[u][i];
      k-=(1<<i);
    }
  }
  return u;
  // for(int i=0; i<LOG && u!=-1; i++){
  //   if(k&(1<<i)) u=up[u][i];
  // }
  // return u;
}
void solve(){
  int n, m; int u, v, w; cin>>n>>m;
  for(int i=1; i<n; i++){
    cin>>u>>v;
    g[u].push_back(v);
  }
  dfs(1);
  while(m--){
    cin>>u>>v;
    cout<<lca(u, v)<<nl;
  }
}
int32_t main(){
 saiful_islam_bk
 int test=1;
  // cin>>test;
 for(int ii=1; ii<=test; ii++){
    //cout<<"Case "<<ii<<": ";
    solve();
 }
}
