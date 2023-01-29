#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> vis(n, false);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    vis[x] = true;
    for (int t : g[x]) {
      if (vis[t]) continue;
      q.push(t);
    }
  }
  rep(i, 0, n) {
    if (!vis[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (n - 1 != m) {
    cout << "No" << endl;
    return 0;
  }

  rep(i, 0, n) {
    if (g[i].size() > 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
