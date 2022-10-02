#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

struct UnionFind {
  vector<int> par;

  UnionFind() {}
  UnionFind(int n) : par(n, -1) {}
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);  // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) { return -par[root(x)]; }
};

int main() {
  // 入力
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i];
    --A[i], --B[i];
  }

  // 各辺を除外して Union-Find で判定
  int res = 0;
  for (int e = 0; e < M; ++e) {
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
      // 辺 e を除外
      if (i == e) continue;

      uf.merge(A[i], B[i]);
    }

    // 連結成分の個数を求める
    int num = 0;
    for (int v = 0; v < N; ++v) {
      if (uf.root(v) == v) ++num;
    }

    // 連結成分数が 1 より大きいと非連結
    if (num > 1) ++res;
  }
  cout << res << endl;

  return 0;
}
