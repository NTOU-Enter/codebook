// 比較兩棵樹的hash值，判斷是否為同構(Isomorphism)
#define ull unsigned long long
const ull mask = std::mt19937_64(time(nullptr))();
ull hash[N];
vector<ull> trees;
ull shift(ull x) {
  x ^= mask;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  x ^= mask;
  return x;
}
// rooted tree
// 對於根節點做DFS，找到整棵樹的hash值
void getHash(int x, int fa){
  hash[x] = 1;
  for(auto i : edge[x]){
    if(i == fa) continue;
    getHash(i, x);
    hash[x] += shift(hash[i]);
  }
  trees.insert(hash[x]);
}
// unrooted tree
// 找到樹的重心(最多兩個)，分別對重心做DFS，找到整棵樹的hash值(pair)
int sz[N], w[N];
vector<int> centroid;
void getCentroid(int x, int fa){
  sz[x] = 1;
  w[x] = 0;
  for(auto i : edge[x]){
    if(i == fa) continue;
    getCentroid(i, x);
    sz[x] += sz[i];
    w[x] = max(w[x], sz[i]);
  }
  w[x] = max(w[x], n-sz[x]);
  if(w[x] <= n/2)
    centroid.PB(x);
}
ull getHash(int x, int fa){
  ull hash = 1;
  for(auto i : edge[x]){
    if(i == fa) continue;
    hash += shift(getHash(i, x));
  }
  return hash;
}