//Kmp:
void kmp(string s, string t){
  vector<int>lps(t.size(), 0);
  for(int i=1, len=0; i<t.size();){
    if(t[i]==t[len]) lps[i++]=++len;
    else if(len) len=lps[len-1];
    else lps[i++]=0;
  }
  for(int i=0, j=0; i<s.size();){
    if(s[i]==t[j]) i++, j++;
    if(j==t.size()) cout<<"Found "<<i-j<<"\n", j=lps[j-1];
    else if(i<s.size() && s[i]!=t[j]) j?j=lps[j-1]:i++;
  }
}
