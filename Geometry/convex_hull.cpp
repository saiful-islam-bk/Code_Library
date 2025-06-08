#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl "\n"
const long double eps=1e-9;
#define saiful_islam_bk
struct point{
    ll x, y;
    // Operator to compare p lexicographically
    bool operator<(const point& p) const{
        return x<p.x || (x==p.x && y<p.y);
    }
    bool operator==(const point& p) const{
        return x==p.x && y==p.y;
    }
};

ll ori(point a, point b, point c){
    ll val=(c.x-b.x)*(b.y-a.y)-(b.x-a.x)*(c.y-b.y);
    return val?val/abs(val):0;
}
vector<point> convex_hull(vector<point>p){
  ll m, k=1, n=p.size(), id=0; if(n<=1) return p;
  sort(p.begin(), p.end()); vector<point>hull; k=hull.size();
  for(ll i=0; i<n; i++){
    m=hull.size();
    while(m>=k+2 && ori(hull[m-2], hull[m-1], p[i])>=0){
      hull.pop_back();
      m=hull.size();
    }
    hull.push_back(p[i]);
  }
  hull.pop_back(); k=hull.size();
  for(ll i=n-1; i>=0; i--){
    m=hull.size();
    while(m>=k+2 && ori(hull[m-2], hull[m-1], p[i])>=0){
      hull.pop_back();
      m=hull.size();
    }
    hull.push_back(p[i]);
  }
  hull.pop_back();
  return hull;
}
void solve(){
    ll n; cin>>n; vector<point>p(n);
    for(ll i=0; i<n; i++){
        cin>>p[i].x>>p[i].y;
    }
    auto convex=convex_hull(p);
    cout<<convex.size()<<nl;
    for(auto i:convex) cout<<i.x<<" "<<i.y<<nl;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 saiful_islam_bk
 ll test=1;
//   cin>>test;
 for(ll ii=1; ii<=test; ii++){
     //cout<<"Case "<<ii<<": ";
     solve();
 }
}
