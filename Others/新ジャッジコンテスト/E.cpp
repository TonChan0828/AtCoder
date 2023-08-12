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

  set<pair<int, int>> set;
  int k;
  cin >> k;
  rep(i, 0, k) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    set.insert({uf.leader(x), uf.leader(y)});
    set.insert({uf.leader(y), uf.leader(x)});
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int p, q;
    cin >> p >> q;
    --p, --q;
    if (set.find({uf.leader(p), uf.leader(q)}) != set.end()) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}
