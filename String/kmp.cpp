#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
#define nl "\n"
#define pb push_back
#define saiful_islam_bk

ll ans=0;
void kmp(string s, string t){
    vector<int>lps(t.size(), 0);
    for(int i=1, len=0; i<t.size();){
        if(t[i]==t[len]) lps[i++]=++len;
        else if(len) len=lps[len-1];
        else lps[i++]=0;
    }
    for(int i=0, j=0; i<s.size();){
        if(s[i]==t[j]) i++, j++; 
        if(j==t.size()) ans++, j=lps[j-1];
        else if(i<s.size() && s[i]!=t[j]) j?j=lps[j-1]:i++; 
    }
}
void solve(){
    string s, t; cin>>s>>t;
    kmp(s, t); cout<<ans<<nl; //kotobar match korche ta print korbe
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
