//Extended Euclidian: O(log(min(a, b)))
pii extendedEuclid(int a, int b){
  if(b==0) return pii(1, 0);
  pii d=extendedEuclid(b, a%b);
  return pii(d.sc, d.F−d.sc∗(a/b));
}
