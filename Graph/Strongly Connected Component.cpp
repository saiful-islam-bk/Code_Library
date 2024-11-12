#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
#define saiful_islam_bk

vector<vector<ll>> g(N), gt(N), scc;
bool vis[N];
stack<int> st;
vector<ll> component;
void dfs1(int v){
    vis[v]=true;
    for(int u:g[v]) if(!vis[u]) dfs1(u);
    st.push(v);
}
void dfs2(int v){
    vis[v]=true;
    component.push_back(v);
    for(int u:gt[v]) if(!vis[u]) dfs2(u);
}
void solve(){
    int n, m, u, v;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    for(int i=1; i<=n; i++) if(!vis[i]) dfs1(i);
    fill(vis, vis+N, false);
    while(!st.empty()){
        int v=st.top(); st.pop(); component.clear();
        if(!vis[v]){
            dfs2(v);
            scc.push_back(component);
        }
    }
    for(auto i:scc){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
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
