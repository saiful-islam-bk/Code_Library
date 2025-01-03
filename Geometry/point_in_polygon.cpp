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
        if(x<=other.x) return x<other.x;
        return y<other.y;
    }
    bool operator<=(point other) const{
        if(x<=other.x) return x<=other.x;
        return y<=other.y;
    }
    bool operator==(point other){
        return fabs(other.x-x)<eps && fabs(other.y-y)<eps;
    }
};
ll ori(point a, point b, point c){
    ll val=(c.x-b.x)*(b.y-a.y)-(b.x-a.x)*(c.y-b.y);
    if(val==0) return 0;
    return val/abs(val);
}
bool onseg(point a, point b, point c){
    return c.x<=max(a.x, b.x) && c.x>=min(a.x, b.x) && c.y<=max(a.y, b.y) && c.y>=min(a.y, b.y);
}
bool ok(point a, point b, point c, point d){
    return ori(a, b, c)!=ori(a, b, d) && ori(c, d, a)!=ori(c, d, b);
    return ori(a, b, c)==0 && onseg(a, b, c);
    return ori(a, b, d)==0 && onseg(a, b, d);
    return ori(c, d, a)==0 && onseg(c, d, a);
    return ori(c, d, b)==0 && onseg(c, d, b);
    return 0;
}

void solve(){
    ll n, m; cin>>n>>m; vector<point>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].x>>v[i].y;
    }
    for(int i=0; i<m; i++){
        point c, p; cin>>c.x>>c.y; bool f=false;
        p.x=1e9+7, p.y=c.y+1; ll k=0;
        for(int j=0; j<n; j++){
            if(ori(v[j], v[(j+1)%n], c)==0 && onseg(v[j], v[(j+1)%n], c)){
                f=true;
                break;
            }else if(ok(v[j], v[(j+1)%n], c, p)) k++;
        }
        if(f){
            cout<<"BOUNDARY"<<nl;
        }else if(k&1){
            cout<<"INSIDE"<<nl;
        }else{
            cout<<"OUTSIDE"<<nl;
        }
    }
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
