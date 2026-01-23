//Prime Factor-1:
vector<int>factor[N];
void primeFactors(){
  for(int i=2; i<=N; i++){
    int n=i;
    while(n%2==0){ factor[i].pb(2); n=n/2; }
    for(int j=3; j*j<=n; j+=2){
      while(n%j==0){ factor[i].pb(j); n=n/j; }
    }
    if(n>2) factor[i].pb(n);
  }
}

//Prime Factorization-2:
vector<pair<int, int>>f;
void prime_factorization(ll num){
  for (ll i=2; i * i <= num; i++){
    if (num%i==0){
      ll ctr=0;
      while(num%i==0){ ctr++; num/=i; }
      f.push_back({i, ctr});
    }
  }
  if(num!=1) f.push_back({num, 1});
}
