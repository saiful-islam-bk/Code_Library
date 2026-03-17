pii t[N][22]; int a[N];
void build(int n){
  for(int i=1; i<=n; i++) t[i][0]={a[i], i};
  for(int k=1; k<22; k++){
    for(int i=1; i+(1<<k)-1<=n; i++){
      auto l=t[i][k-1], r=t[i+(1<<(k-1))][k-1];
      if(l.F>r.F) t[i][k]=l;
      else if(r.F>l.F) t[i][k]=r;
      else t[i][k]=(l.sc<r.sc?l:r);
    }
  }
}
pii query(int l, int r){
  int k=31-__builtin_clz(r-l+1);
  auto L=t[l][k];
  auto R=t[r-(1<<k)+1][k];
  if(L.first>R.first) return L;
  if(R.first>L.first) return R;
  return (L.second<R.second?L:R);
}
