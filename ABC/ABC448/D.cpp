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

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<vector<int>> g(n);
  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  multiset<int> se;
  vector<bool> ans(n), vis(n);
  auto dfs = [&](auto dfs, multiset<int>& s, int now, bool same) -> void {
    if (same) {
      ans[now] = true;
    } else if (s.find(a[now]) != s.end()) {
      ans[now] = true;
      same = true;
    }
    s.insert(a[now]);
    vis[now] = true;
    for (int nx : g[now]) {
      if (vis[nx]) continue;
      dfs(dfs, s, nx, same);
    }
    auto it = s.find(a[now]);
    s.erase(it);
  };

  dfs(dfs, se, 0, false);

  rep(i, 0, n) {
    if (ans[i]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
