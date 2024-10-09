struct ST{
  int n, st[N][20];
  ST(int _n){ n = _n; memset(st, 0, sizeof(st));}
  void build(int a[]){
    for(int i=1; i<=n; i++)
      st[i][0] = a[i];
    for(int j=1; j<20; j++)
      for(int i=1; i+(1<<j)-1<=n; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
  }
  int query(int l, int r){
    int q = log2(r-l+1);
    return min(st[l][q], st[r - (1<<q) + 1][q]);
  }
}st;