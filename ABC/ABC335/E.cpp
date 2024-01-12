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
  vector<ll> a(n);
  rep(i, 0, n) { cin >> a[i]; }
  vector<pair<int, int>> ed;
  dsu uf(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (a[u] == a[v]) uf.merge(u, v);
    ed.emplace_back(u, v);
  }

  vector<vector<int>> to(n);
  for (auto [u, v] : ed) {
    u = uf.leader(u);
    v = uf.leader(v);
    if (u == v) continue;
    if (a[u] > a[v]) swap(u, v);
    to[u].push_back(v);
  }

  vector<int> vs;
  rep(i, 0, n) {
    if (uf.leader(i) == i) vs.push_back(i);
  }
  sort(begin(vs), end(vs), [&](int u, int v) { return a[u] < a[v]; });

  vector<int> dp(n, 0);
  dp[uf.leader(0)] = 1;
  for (int v : vs) {
    for (int u : to[v]) {
      dp[u] = max(dp[u], dp[v] + 1);
    }
  }
  int ans = dp[uf.leader(n - 1)];
  cout << (ans < 0 ? 0 : ans) << endl;

  return 0;
}
