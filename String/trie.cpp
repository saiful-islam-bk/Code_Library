//insert, delete, search, count prefix, longest common prefix
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
#define saiful_islam_bk
class vertex{
public:
char alphabet;
	vector<vertex*>child;
	bool exist;
	int cnt;
	vertex(char a):alphabet(a), exist(false){child.assign(26, NULL), cnt=0;}
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
	void deleteString(vertex* cur, const string& word, int depth=0){
    	if(depth==word.size()){
        	if(cur->exist){
        	    cur->exist=false;
        	    cur->cnt--;
        	}
        	return;
    	}
    	int id=word[depth]-'a';
    	if(cur->child[id]!=NULL){
    	    deleteString(cur->child[id], word, depth + 1);
    	    cur->cnt--;
    	    if(cur->child[id]->cnt==0){
    	        delete cur->child[id];
    	        cur->child[id]=NULL;
    	    }
    	}
	}
	void del(string word){
    	deleteString(root, word);
	}
	bool search(string word){
		vertex* cur=root;
		for(int i=0; i<word.size(); i++){
			int id=word[i]-'a';
			if(cur->child[id]==NULL) return false;
			cur=cur->child[id];
		}
		return cur->exist;
	}
	int countPrefix(string prefix){
		vertex* cur=root;
		for(int i=0; i<prefix.size(); i++){
			int id=prefix[i]-'a';
			if(cur->child[id]==NULL) return 0;
			cur=cur->child[id];
		}
		return cur->cnt;
	}
	string lcp(){ // longest common prefix
    	string prefix="";
    	vertex* cur=root;
    	while(true){
    	    int numChildren=0, id=-1;
    	    for(int i=0; i<26; ++i){
    	        if(cur->child[i]!=NULL){
    	            numChildren++;
    	            id=i;
    	        }
    	    }
    	    if(numChildren!=1 || cur->exist) break;
        	cur=cur->child[id];
        	prefix+=cur->alphabet;
    	}
    	return prefix;
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
