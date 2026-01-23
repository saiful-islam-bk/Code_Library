//a^b%p:

int power(int a, int b, int p){
  int ans=1%p; a%=p; if(a<0) a+=p;
  while(b>0){
    if(b & 1) ans=1LL*ans*a%p;
    a=1LL*a*a%p; b>>=1;
  }
  return ans;
}
