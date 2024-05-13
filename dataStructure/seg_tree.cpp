#define cl(x) (x<<1)
#define cr(x) (x<<1|1)
#define M ((l+r)>>1)
const int N = 5e5 + 5;
struct SegTree{
  int seg[N<<2], lz[N<<2];
  void push(int i, int l, int r){
    if(lz[i]){
        if(l != r){ lz[cl(i)] += lz[i]; lz[cr(i)] += lz[i]; }
        seg[i] += lz[i];
        lz[i] = 0;
    }
  }
  void pull(int i, int l, int r){
    if(l == r) return;
    push(cl(i), l, M);
    push(cr(i), M+1, r);
    seg[i] = seg[cl(i)] + seg[cr(i)];
  }
  void build(int i, int l, int r){
    if(l == r){ seg[i] = 0; return; }
    build(cl(i), l, M);
    build(cr(i), M+1, r);
    pull(i, l, r);
  }
  void upd(int i, int l, int r, int nl, int nr, int v){
    push(i, l, r);
    if(nl <= l && r <= nr){
        lz[i] += v;
        return;
    }

    if(nl <= M) upd(cl(i), l, M, nl, nr, v);
    if(M < nr) upd(cr(i), M+1, r, nl, nr, v);
    pull(i, l, r);
  }
  int qry(int i, int l, int r, int nl, int nr){
    push(i, l, r);
    if(nl <= l && r <= nr) return seg[i];

    int ret = 0;
    if(nl <= M) ret += qry(cl(i), l, M, nl, nr);
    if(M < nr) ret += qry(cr(i), M+1, r, nl, nr);
    return ret;
  }
}Seg;