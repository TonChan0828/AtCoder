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

  vector<bool> vis(n, false);
  vector<int> res;
  auto f = [&](auto f, int x) -> int {
    // cout << x << endl;
    if (g[x].size() == 1) return 1;
    vis[x] = true;
    int cnt = 0;
    if (x == 0) {
      for (int y : g[x]) {
        res.push_back(f(f, y));
      }
      return 0;
    } else {
      for (int y : g[x]) {
        if (vis[y]) continue;
        cnt += f(f, y);
        vis[y] = true;
      }
    }
    ++cnt;
    // cout << x << " " << cnt << endl;
    return cnt;
  };
  f(f, 0);
  sort(begin(res), end(res));
  int ans = 1;
  rep(i, 0, (int)res.size() - 1) ans += res[i];
  cout << ans << endl;
  return 0;
}
