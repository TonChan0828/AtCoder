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

using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, 0, n) cin >> x[i];

  vector<vector<P>> g(n);
  rep(i, 0, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  auto dfs = [&](auto dfs, int u, int p = -1) -> ll {
    // cout << u << " " << p << endl;
    if (g[u].size() == 1 && g[u][0].second == p) {
      x[p] += x[u];
      return abs(x[u]) * g[u][0].second;
    }
    ll res = 0;
    ll c = 0;
    for (auto [v, w] : g[u]) {
      if (v == p) {
        c = w;
        continue;
      }
      res += dfs(dfs, v, u);
    }
    x[p] += x[u];
    res += abs(x[u]) * c;
    return res;
  };

  cout << dfs(dfs, 0) << endl;
  return 0;
}
