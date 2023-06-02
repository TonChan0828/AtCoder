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
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int leaf = -1;
  rep(i, 0, n) {
    if (g[i].size() == 1) leaf = i;
  }

  vector<int> ans;

  auto dfs = [&](auto dfs, int v, int p = -1, int d = 0) -> void {
    if (d % 3 == 1) ans.push_back(g[v].size());
    for (int u : g[v]) {
      if (u != p) {
        dfs(dfs, u, v, d + 1);
      }
    }
  };

  dfs(dfs, leaf);

  sort(ans.begin(), ans.end());
  for (int res : ans) {
    printf("%d ", res);
  }
  cout << endl;
  return 0;
}
