#include <bits/stdc++.h>
using namespace std;
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

vector<vector<int>> G;
vector<int> vis;
int ans = 0;
bool ok = true;

void dfs(int t) {
  ++ans;
  vis[t] = true;
  if (ans >= 1000000) {
    ok = false;
  }
  if (!ok) {
    return;
  }
  for (int x : G[t]) {
    if (vis[x]) continue;
    dfs(x);
  }
  vis[t] = false;
}

int main() {
  int n, m;
  cin >> n >> m;
  G.resize(n);
  vis.resize(n, false);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0);
  // int cnt = 0;
  // for (auto x : mp) {
  //   cnt += x.second;
  // }
  // for (auto x : ans) {
  //   rep(i, 0, x.size()) { cout << x[i]; }
  //   cout << endl;
  // }
  cout << (ok ? ans : 1000000) << endl;
  return 0;
}
