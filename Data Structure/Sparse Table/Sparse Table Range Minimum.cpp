
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl "\n"
#define pb push_back
const int N=2e5+9;
#define saiful_islam_bk

int t[N][18], a[N];
void build(int n){
  for(int i=1; i<=n; i++) t[i][0]=a[i];
  for(int k=1; k<18; k++) {
    for(int i=1; i+(1<<k)-1<=n; i++) {
      t[i][k]=min(t[i][k-1], t[i+(1<<(k-1))][k-1]);
    }
  }
}

int query(int l, int r){
  int k=31-__builtin_clz(r-l+1);
  return min(t[l][k], t[r-(1<<k)+1][k]);
}

void solve(){
	ll n, m=0, k=0; cin>>n>>k;
	for(ll i=1; i<=n; i++){
		cin>>a[i];
	}
	build(n);
	while(k--){
	    ll l, r; cin>>l>>r;
	    cout<<query(l, r)<<nl;
	}
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	saiful_islam_bk
	ll test=1;
	// cin>>test;
	for(ll ii=1; ii<=test; ii++){
	    //cout<<"Case "<<ii<<": ";
	    solve();
	}
}
