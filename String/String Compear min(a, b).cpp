#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define F first
#define sc second
#define saiful_islam_bk

bool cmp(string a, string b){
  if(a.size()<b.size()) return 1;
  if(a.size()>b.size()) return 0;
  if(a<=b) return 1;
  return 0;
}
void solve(){
  string a, b; cin>>a>>b;
  if(cmp(a, b) cout<<"a is smaller then b"<<nl;
  else cout<<"b is smaller then a"<<nl;
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
