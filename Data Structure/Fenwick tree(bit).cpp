#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl "\n"
#define saiful_islam_bk

template <class T>
struct bit{
  ll n; vector<ll>t;
  bit(){}
  bit(ll _n){
    n=_n; t.assign(n+1, 0);
  }
  void upd(T i, T k){
    if(i<=0) return;
    while(n>=i){
      t[i]+=k;
      i+=(i & -i);
    }
  }
  void upd(T l, T r, T p){
    upd(l, p); upd(r+1, -p);
  }
  T query(T i){
    T ans=0;
    while(i>0){
      ans+=t[i];
      i-=(i & -i);
    }
    return ans;
  }
  T query(T l, T r){
    return query(r)-query(l-1);
  }
};

void solve(){
  
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 saiful_islam_bk
 ll test=1;
  // cin>>test;
 for(ll ii=1; ii<=test; ii++){
    //cout<<"Case "<<ii<<": ";
    solve();
 }
}
