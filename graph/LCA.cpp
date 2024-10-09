const int MXN = 2e5 + 5;
const int lgN = __lg(MXN);
int tin[MXN], tout[MXN], anc[MXN][lgN+5], ti = 0;
vector<int> E[MXN];
void dfs(int x, int f){
  anc[x][0] = f;
  tin[x] = ti++;
  for(auto i : E[x]){
    if(i == f) continue;
    dfs(i, x);
  }
  tout[x] = ti++;
}
void init(int n){
  for(int i=1; i<=lgN; i++)
    for(int u=0; u<n; u++)
      anc[u][i] = anc[anc[u][i-1]][i-1];
}
bool inanc(int x, int y){ 
  return tin[x]<=tin[y]&&tout[x]>=tout[y];
}
int lca(int x, int y){
  if(isanc(x, y)) return x;
  if(isanc(y, x)) return y;
  for(int i=lgN; i>=0; i--)
    if(!isanc(anc[x][i], y))
      x = anc[x][i];
  return anc[x][0];
}