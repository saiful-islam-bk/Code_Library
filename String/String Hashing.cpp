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
static unsigned int power(unsigned int a, unsigned int b, unsigned int mod){
  unsigned int ans=1%mod; a%=mod; if(a<0) a+=mod;
  while(b>0){
    if(b & 1) ans=1LL*ans*a%mod;
    a=1LL*a*a%mod; b>>=1;
  }
  return ans;
}
static unsigned int ip1, ip2;
static int pw1[N], pw2[N], ipw1[N], ipw2[N];
void prac(){
  pw1[0]=1; pw2[0]=1;
  for(int i=1; i<N; i++){
    pw1[i]=1LL*pw1[i-1]*base1%mod1;
    pw2[i]=1LL*pw2[i-1]*base2%mod2;
  }
  ip1=power(base1, mod1-2, mod1);
  ip2=power(base2, mod2-2, mod2);
  ipw1[0]=1; ipw2[0]=1;
  for(unsigned int i=1; i<N; i++){
    ipw1[i]=1LL*ipw1[i-1]*ip1%mod1;
    ipw2[i]=1LL*ipw2[i-1]*ip2%mod2;
  }
}
static pii hs={0, 0};
struct Hashing{
  unsigned int n; string s; // 0-indexed
  vector<pii>pref; // 1-indexed
  Hashing() {}
  Hashing(string _s){
    n=_s.size(); s=_s; pref.assign(n+1, {0, 0});
    hs={0, 0};
    for(unsigned int i=0; i<n; i++){
      hs.F+=1LL*s[i]*pw1[i]%mod1;
      hs.sc+=1LL*s[i]*pw2[i]%mod2;
      hs.F%=mod1;
      hs.sc%=mod2;
      pref[i+1]=hs;
    }
  }
  pii get_hash(unsigned int i, unsigned int j){ // 1-index
    i++; j++; // 0 - index
    hs.F=0;
    if(i>j) return hs;
    hs.F=((int)pref[j].F-pref[i-1].F+mod1)*1LL*ipw1[i-1]%mod1;
    hs.sc=((int)pref[j].sc-pref[i-1].sc+mod2)*1LL*ipw2[i-1]%mod2;
    return hs;
  }
  pii get_hash(){ return get_hash(1, n); }
};
 
bool is_palindrome(unsigned int l, unsigned int r, unsigned int n, Hashing &hs1, Hashing &hs2){
  return hs1.get_hash(l, r) == hs2.get_hash(n-r-1, n-l-1);
}
