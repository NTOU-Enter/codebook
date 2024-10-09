struct mat{
  int a[500][500], r, c;
  mat(int _r, int _c){r=_r, c=_c; memset(a, 0, sizeof(a));}
  void build(){ for(int i=0; i<r; i++) a[i][i] = 1; }
};
mat operator *(mat x, mat y){
  mat z = mat(x.r, y.c);
  for(int i=0; i<x.r; i++)
    for(int j=0; j<x.c; j++)
      for(int k=0; k<y.c; k++)
        z.a[i][j] += x.a[i][k]*y.a[k][j]%MOD %= MOD;
  return z;
}
mat matpow(mat x, int y){
  mat ret = mat(x.r, x.c);
  ret.build();
  while(y){
    if(y & 1) ret = ret * x;
    x = x * x;
    y >>= 1;
  }
  return ret;
}