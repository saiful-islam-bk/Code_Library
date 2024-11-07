#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define saiful_islam_bk
const int N=1e6+9;

vector<int>d[N];
void ok(){
  for(int i=1; i*i<N; i++) {
      for(int j=i*i; j<N; j+=i) {
        d[j].push_back(i);
        if(j/i!=i) d[j].push_back(j/i);
      }
  }
}
void solve(int ii){
	int n, m; cin>>n;
  //print all divisors of n
    for(auto k:d[n]){
      cout<<k<<" ";
    }
    cout<<nl;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	saiful_islam_bk
	int test=1;
  ok();
	  cin>>test;
	for(int ii=1; ii<=test; ii++){
		//cout<<"Case "<<ii<<": ";
		solve(ii);
	}
}
