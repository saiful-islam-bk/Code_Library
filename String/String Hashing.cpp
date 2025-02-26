#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
#define nl "\n"
#define pb push_back
#define F first
#define sc second
const int N=1e5+9;
const int mod1=1e9+7, mod2=1e9+9;
const int base1=137, base2=277;

int power(int n, int k, int mod){
    int ans=1%mod; n%=mod; if(n<0) n+=mod;
    while(k>0){
        if(k & 1) ans=(long long)ans*n%mod;
        n=(long long)n*n%mod;
        k>>=1;
    }
    return ans;
}
int ip1, ip2;
pii pw[N], ipw[N];
void prac(){
    pw[0]={1, 1};
    for(int i=1; i<N; i++){
        pw[i].F=1LL*pw[i-1].F*base1%mod1;
        pw[i].sc=1LL*pw[i-1].sc*base2%mod2;
    }
    ip1=power(base1, mod1-2, mod1);
    ip2=power(base2, mod2-2, mod2);
    ipw[0]={1, 1};
    for(int i=1; i<N; i++){
        ipw[i].F=1LL*ipw[i-1].F*ip1%mod1;
        ipw[i].sc=1LL*ipw[i-1].sc*ip2%mod2;
    }
}
pii str_hash(string s){
    int n=s.size();
    pii hs({0, 0});
    for(int i=0; i<n; i++){
        hs.F+=1LL*s[i]*pw[i].F%mod1;
        hs.F%=mod1;
        hs.sc+=1LL*s[i]*pw[i].sc%mod2;
        hs.sc%=mod2;
    }
    return hs;
}
pii pref[N];
void build(string s){
    int n=s.size();
    for(int i=0; i<n; i++){
        pref[i].F=1LL*s[i]*pw[i].F%mod1;
        if(i) pref[i].F=(pref[i].F+pref[i-1].F)%mod1;
        pref[i].sc=1LL*s[i]*pw[i].sc%mod2;
        if(i) pref[i].sc=(pref[i].sc+pref[i-1].sc)%mod2;
    }
}
pii get_hash(int i, int j){
    pii hs({0, 0});
    hs.F=pref[j].F;
    if(i) hs.F=(hs.F-pref[i-1].F+mod1)%mod1;
    hs.F=1LL*hs.F*ipw[i].F%mod1;
    hs.sc=pref[j].sc;
    if(i) hs.sc=(hs.sc-pref[i-1].sc+mod2)%mod2;
    hs.sc=1LL*hs.sc*ipw[i].sc%mod2;
    return hs;
}

void solve(){
  prac();
  string s, t; cin>>s, t;
  build(s);
  pll hs=str_hash(t);
  for(int i=0; i<s.size()-t.size()+1; i++){
    if(hs.F==get_hash(i, i+t.size()-1).F && hs.sc==get_hash(i, i+t.size()-1).sc) cout<<"Found"<<nl;
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 saiful_islam_bk
 int test=1;
  // cin>>test;
 for(int ii=1; ii<=test; ii++){
     //cout<<"Case "<<ii<<": ";
     solve();
 }
}
