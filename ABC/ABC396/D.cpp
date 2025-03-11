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

using P = pair<int, ll>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<P>> g(n);
  rep(i, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  ll ans = LLONG_MAX;
  vector<bool> vis(n, false);
  auto dfs = [&](auto dfs, int u, ll res) -> void {
    if (u == n - 1) {
      ans = min(ans, res);
      return;
    }

    for (auto [v, w] : g[u]) {
      if (vis[v]) continue;
      vis[v] = true;
      dfs(dfs, v, res ^ w);
      vis[v] = false;
    }
  };
  vis[0] = true;
  dfs(dfs, 0, 0);
  cout << ans << endl;
  return 0;
}
