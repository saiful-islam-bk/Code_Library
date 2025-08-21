#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
vector<int>spf(N);
void sieveSPF(){
  iota(spf.begin(), spf.end(), 0); // spf[i]=i initially
  for(int i=2; i*i<N; i++){
    if(spf[i]==i){
      for(int j=i*i; j<N; j+=i){
        if(spf[j]==j) spf[j]=i;
      }
    }
  }
}

vector<int>getPrimeFactors(int x){
  vector<int>factors;
  while(x>1){
    factors.push_back(spf[x]);
    x/=spf[x];
  }
  return factors;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N; cin>>N;
  sieveSPF();
  for(int i=1; i<=N; i++){
    cout<<i<<" : ";
    vector<int>factors=getPrimeFactors(i);
    for(int f:factors) cout<<f<<" ";
    cout<<"\n";
  }
}
