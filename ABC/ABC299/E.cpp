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

const int inf = 1e9;

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

  int k;
  cin >> k;
  vector<int> a(n, -1);
  rep(i, 0, k) {
    int p, d;
    cin >> p >> d;
    --p;
    a[p] = d;
  }

  vector<int> ans(n, 1);
  vector<vector<int>> dist(n, vector<int>(n, inf));
  rep(i, 0, n) {
    if (a[i] == -1) continue;

    queue<int> q;
    q.push(i);
    dist[i][i] = 0;
    vector<bool> vis(n, false);
    vis[i] = true;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : g[x]) {
        if (vis[y]) continue;
        q.push(y);
        vis[y] = true;
        dist[i][y] = dist[i][x] + 1;
      }
    }

    rep(j, 0, n) {
      if (dist[i][j] < a[i]) ans[j] = 0;
    }
  }

  rep(i, 0, n) {
    if (a[i] == -1) continue;
    int mn = inf;
    rep(j, 0, n) {
      if (ans[j]) chmin(mn, dist[i][j]);
    }
    if (a[i] != mn) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  rep(i, 0, n) cout << ans[i];
  cout << endl;

  return 0;
}