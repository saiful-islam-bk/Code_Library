//insert, delete, search, count prefix, longest common prefix
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
#define saiful_islam_bk
class vertex{
  public:
  bool exist; int cnt;
  vector<vertex*>next;
  vertex(){
    exist=false;
    next.assign(26, NULL);  // change there if string is number
    cnt=0;
  }
};
class Trie{
  private:
    vertex* root;
    char c='a';
    int sz=26;  // change there if string is number
    void del(vertex* cur, string s, int id=0){  // delete string from trie
      if(s.size()==id){
        cur->exist=false;
        cur->cnt--;
        return;
      }
      if(cur->next[s[id]-c]!=NULL){
        del(cur->next[s[id]-c], s, id+1);
        cur->cnt--;
        if(cur->next[s[id]-c]->cnt==0){
          delete(cur);
          cur->next[s[id]-c]=NULL;
        }
      }
    }
    void del(vertex* cur){  // delete cur vertex
      for(int i=0; i<sz; i++){
        if(cur->next[i]!=NULL) del(cur->next[i]);
      }
      delete(cur);
    }
  public:
    Trie(){root=new vertex();}
    void insert(string s){  // insert a string on trie
      vertex* cur=root;
      for(int i=0; i<s.size(); i++){
        if(cur->next[s[i]-c]==NULL)
          cur->next[s[i]-c]=new vertex();
        cur=cur->next[s[i]-c];
        cur->cnt++;
      }
      cur->exist=true;
    }
    bool search(string s){  // search a string on trie
      vertex* cur=root;
      for(int i=0; i<s.size(); i++){
        if(cur->next[s[i]-c]==NULL) return false;
        cur=cur->next[s[i]-c];
      }
      return cur->exist;
    }
    int count_prefix(string s){ // count prefix of string s
      vertex* cur=root;
      for(int i=0; i<s.size(); i++){
        if(cur->next[s[i]-c]==NULL) return 0;
        cur=cur->next[s[i]-c];
      }
      return cur->cnt;
    }
    string lcp(){   // return longest common prefix of trie
      vertex* cur=root;
      string pre="";
      while(1){
        int n=0, id=0;
        for(int i=0; i<sz; i++){
          if(cur->next[i]!=NULL){
            n++;
            id=i;
          }
        }
        if(n==1) pre+=(id+c);
        if(n>1 || cur->exist) break;
        cur=cur->next[id];
      }
      return pre;
    }
    void erase(string s){ // delete a string on trie;
      vertex* cur=root;
      if(search(s)) del(cur, s);
    }
    void clear(){ // erase full trie;
      vertex* cur=root;
      del(cur);
    }
};
void solve(){
    Trie trie;
    int n, m; cin>>n>>m;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        trie.insert(s);
    }
	cout<<trie.lcp()<<"\n";
    for(int i=0; i<m; i++){
        cin>>s;
        cout<<trie.countPrefix(s)<<"\n";
    }
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
