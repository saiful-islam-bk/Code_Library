#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define Yes cout<<"YES\n"
#define No cout<<"NO\n"
#define nl "\n"
const double eps=1e-9;
#define saiful_islam_bk
 
struct point{
    ll x, y;
    point(){x=y=0.0;}
    point(ll _x, ll _y) : x(_x), y(_y) {}
    bool operator<(point p) const{
        if(fabs(x-p.x)>eps) return x<p.x;
        return y<p.y;
    }
    bool operator==(point p) const{
        return x==p.x && y==p.y;
    }
    bool operator!=(point p) const{
        return x!=p.x || y!=p.y;
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
 
void solve(){
    point a, b, c, d; cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    if(a==c || a==d || b==c || b==d) return void(Yes);
    if(ori(a, b, c)!=ori(a, b, d) && ori(c, d, a)!=ori(c, d, b)) Yes;
    else if(ori(a, b, c)==0 && onseg(a, b, c)) Yes;
    else if(ori(a, b, d)==0 && onseg(a, b, d)) Yes;
    else if(ori(c, d, a)==0 && onseg(c, d, a)) Yes;
    else if(ori(c, d, b)==0 && onseg(c, d, b)) Yes;
    else No;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 saiful_islam_bk
 ll test=1;
  cin>>test;
 for(ll ii=1; ii<=test; ii++){
     //cout<<"Case "<<ii<<": ";
     solve();
 }
}
