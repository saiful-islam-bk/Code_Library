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

bool isSmaller(string s, string t){
  if(s.size()<t.size()) return true;
  if(s.size()>t.size()) return false;
  for(int i=0; i<s.size(); i++){
    if(s[i]<t[i]) return true;
    if(s[i]>t[i]) return false;
  }
  return false;
}
string subtract(string s, string t){
  bool isNeg=false; string ans="";
  if(isSmaller(s, t)){
    swap(s, t); isNeg=true;
  }
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  int carry=0;
  for(int i=0; i<s.size(); i++){
    int digit=(i<t.size())?t[i]-'0':0;
    int sub=(s[i]-'0')-digit-carry;
    if(sub<0) sub+=10, carry=1;
    else carry=0;
    ans+=(sub+'0');
  }
  while(ans.size()>1 && ans.back()=='0') ans.pop_back();
  reverse(ans.begin(), ans.end());
  if(isNeg) ans="-"+ans;
  return ans;
}

void solve(){
  string a, b; cin>>a>>b; cout<<substract(a, b)<<nl;
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
