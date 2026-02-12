
struct state{
  int len, link, oc;
  map<char, int>next;
};
int last=0, sz=0, cur=0;
vector<state>node;
struct automata{
  automata(vector<int>s){
    node[0].len=0;
    node[0].link=-1;
    sz=1;
    last=0;
    for(int i=0; i<s.size(); i++){
      cur=sz++; node.pb(state());
      node[cur].len=node[last].len+1;
      node[cur].next.clear();
      node[cur].oc=1;
      while(last!=-1 && !node[last].next.count(s[i])){
        node[last].next[s[i]]=cur;
        last=node[last].link;
      }
      if(last==-1){
        node[cur].link=0;
      }else{
        int q=node[last].next[s[i]];
        if(node[last].len+1==node[q].len){
          node[cur].link=q;
        }else{
          int clone=sz++; node.pb(state());
          node[clone]=node[q];
          node[clone].len=node[last].len+1;
          node[clone].oc=0;
          while(last!=-1 && node[last].next[s[i]]==q){
            node[last].next[s[i]]=clone;
            last=node[last].link;
          }
          node[q].link=clone;
          node[cur].link=clone;
        }
      }
    last=cur;
    }
  }
  vector<int>ok(vector<int>s){  //for problem 'E' in contest https://toph.co/c/inter-university-buet-cse-fest-2026
    vector<int>ans;
    int cur=0;
    for(int i=0; i<s.size(); i++){
      if(s[i]==0){
        if(node[cur].next.count(1)){
          ans.pb(1);
          cur=node[cur].next[1];
        }else{
          ans.pb(0);
          cur=node[cur].next[0];
        }
      }else{
        if(node[cur].next.count(0)){
          ans.pb(0);
          cur=node[cur].next[0];
        }else{
          ans.pb(1);
          cur=node[cur].next[1];
        }

      }
    }
    return ans;
  }
};
