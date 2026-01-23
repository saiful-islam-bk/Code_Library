//String Multiply:

string multiply(string a, string b){
  if(a=="0" or b=="0") return "0";
  int n=a.size(), m=b.size();
  vector<int>nm(n+m,0);
  for(int i=n-1; i>=0; i--){
    for(int j=m-1; j>=0; j--){
      nm[i+j+1]+=(a[i]-'0')*(b[j]-'0');
      nm[i+j]+=nm[i+j+1]/10;
      nm[i+j+1]=nm[i+j+1]%10;
    }
  }
  int i=0; string s="";
  while(i<nm.size() and nm[i]==0) i++;
  while(i<nm.size()){
    s.push_back(nm[i]+'0'); i++;
  }
  return s;
}
