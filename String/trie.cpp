#include<bits/stdc++.h>;
using namespace std;
typedef long long int ll;
#define nl "\n"
#define pb push_back
#define saiful_islam_bk

class vertex {
public:
char alphabet;
    vector<vertex*>child;
    bool exist;
    int cnt;
    vertex(char a):alphabet(a), exist(false){child.assign(26, NULL), cnt = 0;}
};
class Trie{
private:
    vertex* root;
public:
    Trie(){ root=new vertex('!');}
    void insert(string word){
        vertex* cur=root;
        for(int i=0; i<word.size(); i++){
            int id=word[i]-'a';
            if(cur->child[id]==NULL) cur->child[id]=new vertex(word[i]);
            cur=cur->child[id];
            cur->cnt++;
        }
        cur->exist=true;
    }
    bool search(string word){
        vertex* cur = root;
        for (int i=0; i<word.size(); i++){
            int id=word[i]-'a';
            if(cur->child[id]==NULL) return false;
            cur=cur->child[id];
        }
        return cur->exist;
    }
    bool startsWith(string prefix){
        vertex* cur = root;
        for(int i=0; i<prefix.size(); i++){
            int id=prefix[i]-'a';
            if(cur->child[id]==NULL) return false;
            cur=cur->child[id];
        }
        return true;
    }
    int countPrefix(string prefix){
        vertex* cur=root;
        for (int i=0; i<prefix.size(); i++){
            int id=prefix[i]-'a';
            if(cur->child[id]==NULL) return 0;
            cur=cur->child[id];
        }
        return cur->cnt;
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
    for(int i=0; i<m; i++){
        cin>>s;
        cout<<trie.countPrefix(s)<<"\n";
    }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	saiful_islam_bk
	ll test=1;
	//  cin>>test;
	for(ll ii=1; ii<=test; ii++){
	    // cout<<"Case "<<ii<<": ";
	    solve();
	}
}
