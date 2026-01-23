//Divisor sieve:
vector<int>d[N];
void ok(){
  for(int i=1; i*i<N; i++){
    for(int j=i*i; j<N; j+=i){
      d[j].push_back(i);
      if(j/i!=i) d[j].push_back(j/i);
    }
  }
}
