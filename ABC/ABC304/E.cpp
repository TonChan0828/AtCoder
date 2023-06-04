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

int main() {
  int n, m;
  cin >> n >> m;

  dsu uf(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    uf.merge(u, v);
  }
  int k;
  cin >> k;
  set<pair<int, int>> set;
  rep(i, 0, k) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    set.insert({uf.leader(x), uf.leader(y)});
    set.insert({uf.leader(y), uf.leader(x)});
  }

  int Q;
  cin >> Q;
  rep(i, 0, Q) {
    int p, q;
    cin >> p >> q;
    --p, --q;
    if (set.find({uf.leader(p), uf.leader(q)}) != set.end()) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }

  return 0;
}
