#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define saiful_islam_bk
const int N=3e5+9;

int a[N];
#define lc (n << 1)
#define rc ((n << 1) | 1)
int t[4*N];
static const int inf = 1e9;
long long combine(long long a,long long b){
    return a+b;
}
void pull(int n){
    t[n]=t[lc]+t[rc];
}
void build(int n, int b, int e) {
    if (b == e){
      t[n] = a[b];
      return;
    }
    int mid=(b+e)>>1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
}
void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x;
      return;
    }
    int mid=(b+e)>>1;
    upd(lc, b, mid, i, x);
    upd(rc, mid + 1, e, i, x);
    pull(n);
}
int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return combine(L, R);
}
void solve(int ii){
	int n, m; cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	build(1, 0, n-1);
	while(m--){
	    int p, q; cin>>p>>q;
	    cout<<query(1, 0, n-1, p, q)<<nl;
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
		solve(ii);
	}
}
