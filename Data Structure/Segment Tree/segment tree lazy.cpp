#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define saiful_islam_bk
const int N=3e5+9;

int a[N];
#define lc (n << 1)
#define rc ((n << 1) | 1)
long long t[4 * N], lazy[4 * N];
inline void push(int n, int b, int e){
    if (lazy[n] == 0) return;
    t[n] = t[n] + lazy[n] * (e - b + 1);
    if (b != e){
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
}
inline long long combine(long long a,long long b){
    return a + b;
}
inline void pull(int n) {
    t[n] = t[lc] + t[rc];
}
//build
void build(int n, int b, int e){
    lazy[n] = 0;
    if (b == e){
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
}
//update
void upd(int n, int b, int e, int i, int j, long long v){
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
}
//query
long long query(int n, int b, int e, int i, int j){
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
}
void solve(int ii){
  ll n, m=0, k=0, ans=0; cin>>n>>m;
  for(int i=0; i<n; i++){
      cin>>a[i];
  }
  build(1, 0, n-1);
  for(int i=0; i<m; i++){
      //for query
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	saiful_islam_bk
	int test=1;
  sieve();
	  //cin>>test;
	for(int ii=1; ii<=test; ii++){
		//cout<<"Case "<<ii<<": ";
		solve(ii);
	}
}
