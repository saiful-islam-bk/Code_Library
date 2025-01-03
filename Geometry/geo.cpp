#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
const long double eps=1e-9;
#define saiful_islam_bk

// point
struct point{
    double x, y;
    point(){x=y=0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator<(point p) const{
        if(fabs(x-p.x)>eps) return x<p.x;
        return y<p.y;
    }
    bool operator==(point p) const{
        return fabs(x-p.x)<eps && fabs(y-p.y)<eps;
        // return x==p.x && y==p.y;   //for int
    }
    bool operator!=(point p) const{
        return x!=p.x || y!=p.y;
    }
};
double hypot(double dx, double dy){
    return sqrt(dx*dx+dy*dy);
}
double distance(point p, point q){
    return hypot(p.x-q.x, p.y-q.y);
}

// Line
struct line{
    double a, b, c;
    bool operator=||(line l){   // =|| means areParallel
        return fabs(a-l1.a)<eps && fabs(b-l1.b)<eps;
    }
    bool operator==(line l) const{
        return fabs(a-l1.a)<eps && fabs(b-l1.b)<eps && fabs(c-l1.c)<eps;
    }
};
line pointsToLine(point p, point q){
    line l;
    if(fabs(p.x-q.x)<eps){
        l.a=1.0; l.b= 0.0; l.c=-p.x;
    }else{
        l.a=-(double)(p.y-q.y)/(p.x-q.x);
        l.b=1.0;
        l.c=-(double)(l.a*p.x)-p.y;
    }
    return l;
}
bool areParallel(line l1, line l2){
    return fabs(l1.a-l2.a)<eps && fabs(l1.b-l2.b)<eps;
}
bool same(line l1, line l2){
    return fabs(l1.a-l2.a)<eps && fabs(l1.b-l2.b)<eps && fabs(l1.c-l2.c)<eps;
}

void solve(){
    
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
