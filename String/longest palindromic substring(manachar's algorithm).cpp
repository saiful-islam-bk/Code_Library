#include <bits/stdc++.h>
using namespace std;
#define saiful_islam_bk

string longestPalindrome(string s){
    string t="@#";
    for(char c : s) t += c, t += '#'; t += '$';
    int n=t.size(), id=0, j=0, maxLen=0, maxid=0;
    vector<int> p(n, 0);
    for(int i=1; i<n-1; i++){
        if(i<j) p[i]=min(j-i, p[2*id-i]);
        while(t[i+p[i]+1]==t[i-p[i]-1]) p[i]++;
        if(i+p[i]>j){
            id=i;
            j=i+p[i];
        }
        if(p[i]>maxLen){
            maxLen=p[i];
            maxid=i;
        }
    }
    int start=(maxid-maxLen)/2;
    return s.substr(start, maxLen);
}
void solve(){
    string s; cin>>s;
    cout<<longestPalindrome(s)<<endl;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    saiful_islam_bk
    int test=1;
    //  cin>>test;
    for(int ii=1; ii<=test; ii++){
        //cout<<"Case "<<ii<<": ";
        solve();
    }
}
