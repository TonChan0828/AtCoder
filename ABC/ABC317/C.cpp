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

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), v(n, vector<int>(n, 0));

  rep(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
    v[a][b] = c;
    v[b][a] = c;
  }

  int ans = 0;

  auto dfs = [&](auto dfs, int now, int sum, vector<bool> vis) -> void {
    ans = max(ans, sum);
    for (int y : g[now]) {
      if (vis[y]) continue;
      vis[y] = true;
      dfs(dfs, y, sum + v[now][y], vis);
      vis[y] = false;
    }
  };
  rep(i, 0, n) {
    vector<bool> visAll(n, false);
    visAll[i] = true;
    dfs(dfs, i, 0, visAll);
  }
  cout << ans << endl;
  return 0;
}
