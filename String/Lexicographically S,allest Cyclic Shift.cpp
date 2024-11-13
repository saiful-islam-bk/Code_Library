#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll>vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef list<int> li;
typedef set<int> sti;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef unordered_set<ll> us;
typedef priority_queue<ll> pq;
typedef deque<ll> dq;
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define Yes cout<<"YES\n";
#define No cout<<"NO\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define F first
#define sc second
#define all(v) v.begin(), v.end()
#define sortv(v) sort(v.begin(), v.end());
#define rsort(v) sort(v.rbegin(), v.rend());
#define revv(v) reverse(v.begin(), v.end());

const int N=1e6+9;
const int mod1=1e9+7, mod2=1e9+9;
const int base1=29, base2=67;
const long long int inf=1e18;
#define saiful_islam_bk
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
int lcp(int i, int j, int x, int y){
    int l=1, r=min(j-i+1, y-x+1), ans=0;
    while(l<=r){
        int mid=l+r>>1;
        if(get_hash(i, i+mid-1)==get_hash(x, x+mid-1)){
            ans=mid,
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
string s;
int cmp(int i, int j, int x, int y){
    int lc=lcp(i, j, x, y);
    int len1=j-i+1, len2=y-x+1;
    if(len1==len2 && lc==len1) return 0;
    else if(lc==len1) return -1;
    else if(lc==len2) return 1;
    else return (s[i+lc]<s[x+lc]?-1:1);
}
string lsc(){
    s+=s; build(s);
    int n=s.size()/2, mni=0, mnj=n-1;
    for(int i=1; i<n; i++){
        int x=cmp(mni, mnj, i, i+n-1);
        if(x==1) mni=i, mnj=i+n-1;
    }
    return s.substr(mni, n);
}
void solve(){
    cin>>s; int n=s.size();
    prac();
    cout<<lsc()<<nl;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    saiful_islam_bk
    ll test=1;
    //  cin>>test;
    for(ll ii=1; ii<=test; ii++){
        //cout<<"Case "<<ii<<": ";
        solve();
    }
}
