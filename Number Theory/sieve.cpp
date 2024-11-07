#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define saiful_islam_bk
const int N=1e6+9;

vector<int> primes;
bool is_prime[N]; 
// use bitset<N> is_prime; to have O(N/64) memory complexity
// using bitset you can solve upto around N = 10^8 in 1s
void sieve(){
  for(int i=2; i<N; i++){
    is_prime[i]=true;
  }
  for(int i=2; i*i<N; i++){
    if(is_prime[i]){
      for(int j=i*i; j<N; j+=i){
        is_prime[j]=false;
      }
    }
  }
  //store all prime in primes vector upto N
  for(int i=2; i<N; i++){
    if(is_prime[i]){
      primes.push_back(i);
    }
  }
}

void solve(int ii){
	int n, m; cin>>n;
  if(is_prime[n]) cout<<"Prime"<<nl;
  else cout<<"Not Prime"<<nl;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	saiful_islam_bk
	int test=1;
  sieve();
	  cin>>test;
	for(int ii=1; ii<=test; ii++){
		//cout<<"Case "<<ii<<": ";
		solve(ii);
	}
}
