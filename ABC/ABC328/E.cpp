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
  ll k;
  cin >> n >> m >> k;
  ll ans = 0;
  vector<tuple<int, int, ll>> g(m);
  rep(i, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u, --v;
    g[i] = {u, v, w};
    ans += w;
    ans %= k;
  }
  vector<vector<int>> pattern;

  auto dfs = [&](auto dfs, vector<int> v, int cnt) {
    if (cnt == n - 1) {
      pattern.push_back(v);
      return;
    }
    rep(i, v.back() + 1, m) {
      v.push_back(i);
      dfs(dfs, v, cnt + 1);
      v.pop_back();
    }
    return;
  };
  rep(i, 0, m - n + 2) {
    vector<int> t;
    t.push_back(i);
    dfs(dfs, t, 1);
  }
  // for (auto tmp : pattern) {
  //   rep(i, 0, n - 1) { cout << tmp[i] << " "; }
  //   cout << endl;
  // }
  // cout << pattern.size() << endl;
  if (pattern.empty()) {
    cout << k << endl;
    return 0;
  }
  ans = k;
  for (auto p : pattern) {
    dsu uf(n);
    ll res = 0;
    for (auto x : p) {
      auto [u, v, w] = g[x];
      uf.merge(u, v);
      res = (res + w) % k;
    }

    if (uf.size(0) != n) continue;
    chmin(ans, res);
  }
  cout << ans << endl;
  return 0;
}
