// cnt[i] 有多少字串以此節點結尾(字串出現次數)
// sz[i] 有多少字串前綴包括此節點
struct trie{
  trie *nxt[26];
  int cnt, sz;
  trie(){cnt=0; sz=0; memset(nxt, 0, sizeof(nxt));}
};

trie root = new trie();
void insert(string s){
  trie *now = root;
  for(auto c : s){
    now->sz++;
    if(now->nxt[c-'a'] == nullptr)
      now->nxt[c-'a'] = new trie();
    now = now->nxt[c-'a'];
  }
  now->cnt++; now->sz++;
}
int query(string s){
  trie *now = root;
  for(auto c : s){
    if(now->nxt[c-'a'] == nullptr)
      return 0;
    now = now->nxt[c-'a'];
  }
  return now->cnt;
}