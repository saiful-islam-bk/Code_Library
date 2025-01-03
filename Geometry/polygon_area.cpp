#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl "\n"
const double eps=1e-9;
#define saiful_islam_bk

struct point{
    ll x, y;
    point() { x=y=0.0; }
    point(ll _x, ll _y) : x(_x), y(_y) {}
    bool operator<(point other) const{
        if(fabs(x-other.x)>eps) return x<other.x;
        return y<other.y;
    }
    bool operator==(point other){
        return x==other.x && y==other.y;
    }
};
void solve(){
    ll n, ans=0; cin>>n; vector<point>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].x>>v[i].y;
    }
    for(int i=0; i<n; i++){
        if(v[i]==v[(i+1)%n]) continue;
        ans+=v[i].x*v[(i+1)%n].y-v[i].y*v[(i+1)%n].x;
    }
    cout<<abs(ans)<<nl;
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
