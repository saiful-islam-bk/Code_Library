//String Addition:

string string_addd(string s, string t){
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  while(s.size()<t.size()) s+='0';
  while(t.size()<s.size()) t+='0';
  string ans=""; int carry=0;
  for(int i=0; i<s.size(); i++){
    int sum=(s[i]-'0')+(t[i]-'0')+carry;
    ans+=(sum%10)+'0';
    carry=sum/10;
  }
  if(carry>0) ans+=carry+'0';
  reverse(ans.begin(), ans.end());
  return ans;
}
