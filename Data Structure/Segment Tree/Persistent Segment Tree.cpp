#include<bits/stdc++.h>
using namespace std;
#define int long long int
typedef pair<int, int>pii;
#define nl "\n"
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N=2e5+5;
const int inf=1e9;
#define saiful_islam_bk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Node{
  int left=0, right=0, sum=0;
};
vector<Node>seg(1);
int a[N], root[N];
int t=0;
int build(int l, int r){
  int cur=++t;
  seg.pb(Node());
  if(l==r) return cur;
  int mid=(l+r)/2;
  seg[cur].left=build(l, mid);
  seg[cur].right=build(mid+1, r);
  return cur;
}
int upd(int prv, int l, int r, int pos){
  int cur=++t;
  seg.pb(Node());
  seg[cur]=seg[prv];
  if(l==r){
    seg[cur].sum++;
    return cur;
  }
  int mid=(l+r)/2;
  if(pos<=mid){
    seg[cur].left=upd(seg[prv].left, l, mid, pos);
  }else{
    seg[cur].right=upd(seg[prv].right, mid+1, r, pos);
  }
  seg[cur].sum=seg[seg[cur].left].sum+seg[seg[cur].right].sum;
  return cur;
}
int query(int cur, int l, int r, int ql, int qr){
  if(ql<=l && r<=qr) return seg[cur].sum;
  int mid=(l+r)/2;
  int ans=0;
  if(ql<=mid) ans+=query(seg[cur].left, l, mid, ql, qr);
  if(qr>mid) ans+=query(seg[cur].right, mid+1, r, ql, qr);
  return ans;
}
int kth(int qr, int ql, int l, int r, int k){
  if(l==r) return l;
  int cnt=seg[seg[qr].left].sum-seg[seg[ql].left].sum;
  int mid=(l+r)/2;
  if(k<=cnt){
    return kth(seg[qr].left, seg[ql].left, l, mid, k);
  }else{
    return kth(seg[qr].right, seg[ql].right, mid+1, r, k-cnt);
  }
}
int countLE(int qr, int ql, int l, int r, int x){ // count(value<=x in range l to r at version ql to qr)
  if(r<=x) return seg[qr].sum-seg[ql].sum;
  if(x<l) return 0;
  int mid=(l+r)/2, ans=0;
  ans+=countLE( seg[qr].left, seg[ql].left, l, mid, x);
  if(x>mid) ans+=countLE(seg[qr].right, seg[ql].right, mid+1, r, x);
  return ans;
}
// kth smallest value in range
void solve(){
  int n, q; cin>>n>>q; vector<int>v;
  seg.reserve(n*20);
  for(int i=1; i<=n; i++){
    cin>>a[i]; v.pb(a[i]);
  }
  sort(all(v));
  root[0]=build(1, n);
  for(int i=1; i<=n; i++){
    root[i]=upd(root[i-1], 1, n, lower_bound(all(v), a[i])-v.begin()+1);
  }
  while(q--){
    int l, r, k; cin>>l>>r>>k;
    cout<<v[kth(root[r], root[l-1], 1, n, k)-1]<<nl;
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
