#include <bits/stdc++.h>
using namespace std;
const int N=1e5+9;
#define saiful_islam_bk

vector<int>primefactor[N];
void primeFactors(){
    int n;
    for(int i=2; i<=N; i++){
        n=i;
	    while(n%2==0){
            primefactor[i].push_back(2);
		    n=n/2;
	    }
	    for(int j=3; j*j<=n; j+=2){
	    	while(n%j==0){
                primefactor[i].push_back(j);
	    		n=n/j;
	    	}
	    }
	    if(n>2) primefactor[i].push_back(n);
    }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    saiful_islam_bk
	int n; cin>>n;
	primeFactors();
    for(auto i: primefactor[n]) cout<<i<<" ";
	return 0;
}
