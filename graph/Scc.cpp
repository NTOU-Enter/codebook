// u or v: addEdge(u, ~v); addEdge(v, ~u);
// u => v: addEdge(~u, ~v); addEdge(v, u);
// bln[i] == bln[n+i] => no solution
struct Scc{// 0-based
  int n, nScc, vst[MXN], bln[MXN];
  vector<int> E[MXN], rE[MXN], vec;
  void init(int _n){
    n = _n;
    for (int i=0; i<MXN; i++)
      E[i].clear(), rE[i].clear();
  } 
  void addEdge(int u, int v){
    E[u].PB(v); rE[v].PB(u);
  }
  void DFS(int u){
    vst[u]=1;
    for(auto v : E[u]) if(!vst[v]) DFS(v);
    vec.PB(u);
  }
  void rDFS(int u){
    vst[u] = 1; bln[u] = nScc;
    for(auto v : rE[u]) if(!vst[v]) rDFS(v);
  }
  void solve(){
    nScc = 0;
    vec.clear();
    fill(vst, vst+n+1, 0);
    for(int i=0; i<n; i++)
      if(!vst[i]) DFS(i);
    reverse(vec.begin(),vec.end());
    fill(vst, vst+n+1, 0);
    for(auto v : vec) 
      if(!vst[v]){
          rDFS(v); nScc++;
      }
  }
}scc;