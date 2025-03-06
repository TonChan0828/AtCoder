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

using V = vector<ll>;
const ll INF = 1001001001001001;

int main() {
  int n, m;
  ll x;
  cin >> n >> m >> x;
  vector g(2, vector(n, vector<int>()));
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[0][u].push_back(v);
    g[1][v].push_back(u);
  }

  vector cost(2, vector<ll>(n, INF));
  priority_queue<V, vector<V>, greater<V>> q;
  q.push({0, 0, 0});
  q.push({x, 0, 1});

  while (!q.empty()) {
    auto v = q.top();
    q.pop();
    ll c = v[0];
    int u = v[1];
    int r = v[2];
    if (c >= cost[r][u]) continue;
    cost[r][u] = c;
    // printf("c:%lld, u:%d, r:%d\n", c, u, r);

    ll tmp = c + 1;
    for (int y : g[r][u]) {
      if (cost[r][y] <= tmp) continue;
      // printf("tmp:%lld, u:%d, r:%d, y:%d\n", tmp, u, r, y);
      q.push({tmp, y, r});
    }
    tmp += x;
    r = (r + 1) % 2;
    for (int y : g[r][u]) {
      if (cost[r][y] <= tmp) continue;
      // printf("tmp:%lld, u:%d, r:%d, y:%d\n", tmp, u, r, y);

      q.push({tmp, y, r});
    }
  }

  cout << min(cost[0][n - 1], cost[1][n - 1]) << endl;
  return 0;
}
