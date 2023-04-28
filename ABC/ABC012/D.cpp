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
  vector<vector<int>> r(n, vector<int>(n));

  rep(i, 0, m) {
    int a, b, t;
    cin >> a >> b >> t;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
    r[a][b] = t;
    r[b][a] = t;
  }

  int ans = INT_MAX;

  rep(i, 0, n) {
    vector<int> res(n, INT_MAX);
    queue<int> q;
    q.push(i);
    res[i] = 0;

    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : g[x]) {
        if (res[x] + r[x][y] >= res[y]) continue;
        res[y] = res[x] + r[x][y];
        q.push(y);
      }
    }
    int ma = 0;
    rep(i, 0, n) ma = max(ma, res[i]);
    ans = min(ans, ma);
  }

  cout << ans << endl;
  return 0;
}
