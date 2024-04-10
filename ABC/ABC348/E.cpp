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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector g(n, vector<int>());
  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<ll> c(n);
  rep(i, 0, n) cin >> c[i];

  ll tot = 0;
  rep(i, 0, n) tot += c[i];

  int x = -1;
  {
    auto dfs = [&](auto dfs, int v, int p = -1) -> ll {
      ll res = c[v];
      ll mx = 0;
      for (int u : g[v]) {
        if (u != p) {
          ll now = dfs(dfs, u, v);
          mx = max(mx, now);
          res += now;
        }
      }
      mx = max(mx, tot - res);
      if (mx * 2 <= tot) x = v;
      return res;
    };
    dfs(dfs, 0);
  }

  ll ans = 0;
  auto dfs = [&](auto dfs, int v, int dist = 0, int p = -1) -> void {
    ans += (ll)dist * c[v];
    for (int u : g[v]) {
      if (u != p) dfs(dfs, u, dist + 1, v);
    }
  };
  dfs(dfs, x);
  cout << ans << endl;
  return 0;
}
