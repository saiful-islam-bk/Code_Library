#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl "\n"
#define saiful_islam_bk

vector<int>zalgo(string s){
  int n=s.size(), l=0, r=0;
  vector<int>z(n, 0);
  for(int i=1; i<n; ++i){
    if(i<=r) z[i]=min(r-i+1, z[i-l]);
    while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
    if(i+z[i]-1>r) l=i, r=i+z[i]-1;
  }
  return z;
}
//Longest prefix-suffix:
int findLongestPrefixSuffix(string s){
  vector<int>z=zalgo(s); int n=s.size(), ans=0;
  for(int i=1; i<n; i++){ if(z[i]==n-i) ans=z[i]; }
  return ans;
}

void solve(){
  string s; cin>>s; auto z=zalgo(s); cout<<findLongestPrefixSuffix(s)<<nl;
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
