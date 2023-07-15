#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n, -1) {}
  int find(int x) {
    if (par[x] < 0) return x;
    return par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (par[x] > par[y]) {
      par[y] += par[x];
      par[x] = y;
    } else {
      par[x] += par[y];
      par[y] = x;
    }
    return true;
  }

  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -par[find(x)]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> es(m);
  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    es[i] = {x, y};
  }
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];

  UnionFind uf(n);
  for (auto [x, y] : es) {
    if (c[x] != c[y]) {
      uf.unite(x, y);
    }
  }
  for (auto [x, y] : es) {
    if (c[x] == c[y] && uf.same(x, y)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
