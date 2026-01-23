//String Division: (string/integer)

string longDivision(string s, int n){
  string ans; int id=0, m=s[id]-'0';
  while(id<(s.size()-1) && m<n)
    m=m*10+(s[++id]-'0');
  while((s.size()-1)>id){
    ans+=(m/n)+'0';
    m=(m%n)*10+s[++id]-'0';
  }
  ans+=(m/n)+'0';
  if(ans.length()==0) return "0";
  return ans;
}
