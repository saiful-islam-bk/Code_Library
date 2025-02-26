#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define F first
#define sc second
#define saiful_islam_bk

string multiply(string a, string b){
  if(a=="0" or b=="0") return "0";
    int n=a.size(), m=b.size();
    vector<int>nm(n+m,0);
    for(int i=n-1; i>=0; i--){
      for(int j=m-1; j>=0; j--){
        nm[i+j+1]+=(a[i]-'0')*(b[j]-'0');
        nm[i+j]+=nm[i+j+1]/10;
        nm[i+j+1]=nm[i+j+1]%10;
      }
    }
    int i=0; string s="";
    while(i<nm.size() and nm[i]==0) i++;
    while(i<nm.size()){
      s.push_back(nm[i]+'0'); i++;
    }
    return s;
}
void solve(){
  string a, b; cin>>a>>b; cout<<multiply(a, b)<<nl;
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
