#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define saiful_islam_bk
const int N=1e5+9;

int a[N], tree[4*N];
void build(int node, int st, int en){
	if(st==en){
		tree[node]=a[st];
		return;
	}
	int mid=(st+en)/2;
	build(2*node, st, mid);
	build(2*node+1, mid+1, en);
	//tree[node]=tree[2*node]+tree[2*node+1];
	tree[node]=max(tree[2*node], tree[2*node+1]);
}

int query(int node, int st, int en, int l, int r){
    if(st>r || en<l) return 0;
    if(st>=l && en<=r) return tree[node];
    
    int mid=(st+en)/2;
    int q1=query(2*node, st, mid, l, r);
    int q2=query(2*node+1, mid+1, en, l, r);
    //return q1+q2;
    return max(q1,q2);
}

void update(int node, int st, int en, int idx, int val){
    if(st==en){
        a[st]=val;
        tree[node]=val;
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node, st, mid, idx, val);
    }else{
        update(2*node+1, mid+1, en, idx, val);
    }
    //tree[node]=tree[2*node]+tree[2*node+1];
    tree[node]=max(tree[2*node], tree[2*node+1]);
}

void solve(){
	int n; cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	build(1, 0, n-1);
	while(1){
	    int p, q; cin>>p>>q;
	    if(p==-1) return;
	    cout<<query(1, 0, n-1, p, q)<<nl;
	}
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	saiful_islam_bk
	ll test=1;
	 cin>>test;
	for(ll ii=1; ii<=test; ii++){
    solve();
	//cout<<"Case "<<ii<<": ";
  }
}
