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
    g[u].push_back({v, w});
    g[v].push_back({u, 0 - w});
  }
  vector<ll> ans(n, 0);
  vector<bool> vis(n, false);
  int cnt = 0;
  auto dfs = [&](auto dfs, int now) -> void {
    for (auto [nxt, cost] : g[now]) {
      if (vis[nxt]) continue;
      vis[nxt] = true;
      ++cnt;
      ans[nxt] = ans[now] + cost;
      dfs(dfs, nxt);
    }
  };

  rep(i, 0, n) {
    if (vis[i]) continue;
    vis[i] = true;
    ++cnt;
    dfs(dfs, i);
  }

  for (ll x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
