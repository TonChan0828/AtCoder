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
  int ans = 1;
  vector<int> vis(n1 + n2, -1);
  rep(i, 0, n1 + n2) {
    if (!(i == 0 || i == n1 + n2 - 1)) continue;
    queue<int> q;
    q.push(i);
    vis[i] = 0;
    int ma = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      ma = max(ma, vis[x]);
      for (int y : g[x]) {
        if (vis[y] > -1) continue;
        vis[y] = vis[x] + 1;
        q.push(y);
      }
    }
    // cout << ma << endl;
    ans += ma;
  }
  cout << ans << endl;
  return 0;
}
