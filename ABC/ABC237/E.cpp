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

using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  vector<vector<int>> to(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    to[u].push_back(v);
    to[v].push_back(u);
  }

  priority_queue<P, vector<P>, greater<P>> q;
  const int INF = 1001001001;
  vector<int> dist(n, INF);
  dist[0] = 0;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [d, v] = q.top();
    q.pop();
    if (dist[v] != d) continue;
    for (int u : to[v]) {
      int cost = max(0, h[u] - h[v]);
      int nd = d + cost;
      if (nd >= dist[u]) continue;
      dist[u] = nd;
      q.emplace(nd, u);
    }
  }

  int ans = 0;
  rep(i, 0, n) {
    int now = h[0] - h[i] - dist[i];
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
