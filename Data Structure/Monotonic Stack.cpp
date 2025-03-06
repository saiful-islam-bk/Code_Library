#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl "\n"
const int N=1e6+9;
const int mod1=1e9+7, mod2=1e9+9;
const int base1=137, base2=277;
const long long int inf=1e9;
const long double eps=1e-9;
#define saiful_islam_bk

vector<ll>leftt, rightt;
void ok(ll n){
  stack<ll>st;
  //prev smmalest value index
  for(int i=1; i<=n; i++){
    while(!st.empty() && a[st.top()]>=a[i]) st.pop();
    leftt[i]=(st.empty()?1:st.top());
    st.push(i);
  }
  while(!st.empty()) st.pop();
  //next smallest value index
  for(int i=n; i>0; i--){
    while(!st.empty() && a[st.top()]>=a[i]) st.pop();
    rightt[i]=(st.empty()?n:st.top());
    st.push(i);
  }
}
void solve(){
  ll n, m=0, k=0; cin>>n;
  leftt.resize(n+1); rightt.resize(n+1);
  for(ll i=1; i<=n; i++) cin>>a[i];
  ok(n);
  for(ll i=1; i<=n; i++) cout<<leftt[i]<<" "; cout<<nl;
  for(ll i=1; i<=n; i++) cout<<rightt[i]<<" "; cout<<nl; 
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
