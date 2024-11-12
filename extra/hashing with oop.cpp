#include<bits/stdc++.h>
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

const int N=8e4+6810;
const int mod1=1e9+7, mod2=1e9+9;
const int base1=137, base2=277;
const long long int inf=1e18;
#define saiful_islam_bk

class Hashing{
private:
    int ip1, ip2;
    pii pw[N], ipw[N], pref[N];
    int power(int n, int k, int mod){
        int ans=1%mod; n%=mod; if(n<0) n+=mod;
        while(k>0){
            if(k & 1) ans=1LL*ans*n%mod;
            n=1LL*n*n%mod;
            k>>=1;
        }
        return ans;
    }
    void prac(){
        pw[0]={1, 1}; ipw[0]={1, 1};
        for(int i=1; i<N; i++){
            pw[i].F=1LL*pw[i-1].F*base1%mod1;
            pw[i].sc=1LL*pw[i-1].sc*base2%mod2;
       }
        ip1=power(base1, mod1-2, mod1);
        ip2=power(base2, mod2-2, mod2);
        for(int i=1; i<N; i++){
            ipw[i].F=1LL*ipw[i-1].F*ip1%mod1;
            ipw[i].sc=1LL*ipw[i-1].sc*ip2%mod2;
        }
    }
public:
    Hashing(){
        prac();
    }
    pii str_hash(string s){
        int n=s.size();
        pii hs({0, 0});
        for(int i=0; i<n; i++){
            hs.F+=1LL*s[i]*pw[i].F%mod1;
            hs.sc+=1LL*s[i]*pw[i].sc%mod2;
            hs.F%=mod1; hs.sc%=mod2;
        }
        return hs;
    }
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
        pii hs={pref[j].F, pref[j].sc};
        if(i){
            hs.F=(hs.F-pref[i-1].F+mod1)%mod1;
            hs.sc=(hs.sc-pref[i-1].sc+mod2)%mod2;
        }
        hs.F=1LL*hs.F*ipw[i].F%mod1;
        hs.sc=1LL*hs.sc*ipw[i].sc%mod2;
        return hs;
    }
};

void solve(){
    string s, t; cin>>s>>t; int n=s.size(), m=t.size();
    Hashing hs1; int ans=0;
    hs1.build(s);
    auto p=hs1.str_hash(t); //cout<<p.F<<" "<<p.sc<<nl;
    for(int i=0; i<=n-m; i++){
        if(hs1.get_hash(i, i+m-1)==p) ans++;
    }
    cout<<ans<<nl;
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
