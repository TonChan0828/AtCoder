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

void solve(void) {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  --x, --y;
  vector<vector<int>> g(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  rep(i, 0, n) sort(begin(g[i]), end(g[i]));
  vector<int> vis(n, false);
  vector<int> ans;
  bool complete = false;
  auto dfs = [&](auto dfs, int now, vector<int> v) {
    v.push_back(now);
    if (now == y) {
      for (int tmp : v) cout << tmp + 1 << " ";
      cout << endl;
      complete = true;
      return;
    }
    if (complete) return;

    for (int nxt : g[now]) {
      if (vis[nxt]) continue;
      vis[nxt] = true;
      dfs(dfs, nxt, v);

      if (complete) return;
    }
  };

  vis[x] = true;
  dfs(dfs, x, ans);

  return;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    solve();
  }
  return 0;
}
