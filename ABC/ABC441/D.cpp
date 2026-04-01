#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

using P = pair<int, ll>;

int main() {
  int n, m, l, s, t;
  cin >> n >> m >> l >> s >> t;
  vector g(n, vector<P>());
  rep(i, 0, m) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    --u, --v;
    g[u].push_back({v, c});
  }
  set<int> ans;
  auto dfs = [&](auto dfs, int u, int count, ll cost) -> void {
    if (count == l) {
      if (s <= cost && cost <= t) ans.insert(u);
      return;
    }

    for (auto [v, c] : g[u]) {
      dfs(dfs, v, count + 1, cost + c);
    }
    return;
  };

  dfs(dfs, 0, 0, 0);

  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << endl;
  return 0;
}
