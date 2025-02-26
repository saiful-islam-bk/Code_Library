#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define saiful_islam_bk

string string_addd(string s, string t){
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    while(s.size()<t.size()) s+='0';
    while(t.size()<s.size()) t+='0';
    string ans=""; int carry=0;
    for(int i=0; i<s.size(); i++){
        int sum=(s[i]-'0')+(t[i]-'0')+carry;
        ans+=(sum%10)+'0';
        carry=sum/10;
    }
    if(carry>0) ans+=carry+'0';
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(){
  string a, b; cin>>a>>b; cout<<string_addd(a, b)<<nl;
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
