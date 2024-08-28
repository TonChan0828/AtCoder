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
  int n, k;
  cin >> n >> k;

  vector g(n, vector<int>());
  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<bool> v(n, false);
  rep(i, 0, k) {
    int vv;
    cin >> vv, --vv;
    v[vv] = true;
  }

  vector<bool> vis(n, false);
  int ans = n;
  auto dfs = [&](auto dfs, int now) -> bool {
    // cout << now << endl;
    bool target = v[now];
    vis[now] = true;
    for (int nxt : g[now]) {
      if (vis[nxt]) continue;
      target |= dfs(dfs, nxt);
    }
    if (!target) --ans;
    return target;
  };

  rep(i, 0, n) {
    if (v[i] && !vis[i]) dfs(dfs, i);
  }

  cout << ans << endl;
  return 0;
}
