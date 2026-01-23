//Factorial:

int fa[N], invfa[N];
int inv(long long a, long long b=M){
  return 1<a?b-inv(b%a,a)*b/a:1;
}
void factorial(){
  fa[0]=1;
  for(int i=1; i<N; i++) fa[i]=(fa[i-1]*i)%M;
  //invfa[N-1]=power(fa[N-1], M-2, M);
  Invfa[N-1]=inv(fa[N-1]);
  for(int i=N-2; i>=0; i--)
    invfa[i]=(invfa[i+1]*(i+1))%M;
}

//nCr:
int ncr(int n, int r){
  if(n<r) return 0;
  return (fa[n]*invfa[r]%M)*invfa[n-r]%M;
}

//nPr:
int npr(int n, int r){
  if(n<r) return 0;
  return (fa[n]*invfa[n-r])%M;
}

//nCr without mod(small r)
int nCr(int n, int r) {
  if(r>n-r) r=n-r;
  int res=1;
  for (int i=1; i<=r; i++){
    int num=n-i+1, cur=i, g=gcd(num, cur);
    num/=g; cur/=g; res=(res/cur)*num;
  }
  return res;
}
