#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
#define saiful_islam_bk

vector<vector<ll>> g(N);
bool vis[N];
void dfs(int v){
    vis[v]=true;
    for(int u:g[v]){
		if(!vis[u]) dfs1(u);
	}
}
void solve(){
    int n, m, u, v;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
		if(!vis[i]) dfs(i);
	}
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    saiful_islam_bk
    int test=1;
    //  cin>>test;
    for(int ii=1; ii<=test; ii++){
        //cout<<"Case "<<ii<<": ";
        solve();
    }
}
