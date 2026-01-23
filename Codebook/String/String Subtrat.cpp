//String Subtract/Minus: 

bool isSmaller(string s, string t){
  if(s.size()<t.size()) return true;
  if(s.size()>t.size()) return false;
  for(int i=0; i<s.size(); i++){
    if(s[i]<t[i]) return true;
    if(s[i]>t[i]) return false;
  }
  return false;
}
string subtract(string s, string t){
  bool isNeg=false; string ans="";
  if(isSmaller(s, t)){
    swap(s, t); isNeg=true;
  }
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  int carry=0;
  for(int i=0; i<s.size(); i++){
    int digit=(i<t.size())?t[i]-'0':0;
    int sub=(s[i]-'0')-digit-carry;
    if(sub<0) sub+=10, carry=1;
    else carry=0;
    ans+=(sub+'0');
  }
  while(ans.size()>1 && ans.back()=='0') ans.pop_back();
  reverse(ans.begin(), ans.end());
  if(isNeg) ans="-"+ans;
  return ans;
}
