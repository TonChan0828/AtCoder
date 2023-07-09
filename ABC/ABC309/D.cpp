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
  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  vector<vector<int>> g(n1 + n2);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<bool> vis(n1 + n2, false);
  vector<int> d(n1 + n2, 0);
  int ans = 0;

  rep(i, 0, n1 + n2) {
    if (vis[i]) continue;
    if (!(i == 0 || i == n1 + n2 - 1)) continue;
    queue<pair<int, int>> q;
    int ma = 0;
    q.push({i, 0});
    vis[i] = true;
    while (!q.empty()) {
      auto [p, cnt] = q.front();
      q.pop();
      ma = max(ma, cnt);
      // vis[p] = true;
      for (int x : g[p]) {
        if (vis[x]) continue;
        vis[x] = true;
        q.push({x, cnt + 1});
      }
    }
    // cout << i << ma << endl;
    ans += ma + 1;
  }
  cout << ans - 1 << endl;
  return 0;
}
