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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  rep(i, 0, m) {
    int a, c;
    char b, d;
    cin >> a >> b >> c >> d;
    --a, --c;
    g[a].push_back(c);
    g[c].push_back(a);
    ++deg[a];
    ++deg[c];
  }
  vector<bool> vis(n, false);
  int x = 0, y = 0;

  rep(i, 0, n) {
    if (vis[i]) continue;

    queue<int> q;
    vis[i] = true;
    q.push(i);
    bool l = true;
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      if (deg[t] != 2) l = false;
      for (int v : g[t]) {
        if (vis[v]) continue;
        q.push(v);
        vis[v] = true;
      }
    }

    if (l)
      ++x;
    else
      ++y;
  }

  cout << x << " " << y << endl;
  return 0;
}
