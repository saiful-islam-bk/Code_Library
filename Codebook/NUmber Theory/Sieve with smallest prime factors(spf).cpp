// sieve with smallest prime factors (spf): 
vector<int> primes;
int spf[N];
void sieve(){
  for(int i=2; i<N; i++) spf[i]=i;
  for(int i=2; i*i<N; i++){
    if(spf[i]==i){
      for(int j=i*i; j<N; j+=i){
        spf[j]=min(spf[j], i);
      }
    }
  }
  for(int i=2; i<N; i++){
    if(spf[i]==i){
      primes.push_back(i);
    }
  }
}
