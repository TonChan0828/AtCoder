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
  vector<vector<tuple<int, int, int>>> g(n);
  rep(i, 0, m) {
    int a, b;
    ll x, y;
    cin >> a >> b >> x >> y;
    --a, --b;
    g[a].push_back({b, y, x});
    g[b].push_back({a, 0 - y, 0 - x});
  }

  vector<bool> vis(n);
  vector<ll> ansX(n, 0), ansY(n, 0);
  queue<int> q;
  q.push(0);
  vis[0] = true;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    ll x = ansX[t], y = ansY[t];
    for (auto [p, ny, nx] : g[t]) {
      if (vis[p]) continue;
      vis[p] = true;
      ansX[p] = x + nx;
      ansY[p] = y + ny;
      q.push(p);
    }
  }

  rep(i, 0, n) {
    if (!vis[i])
      printf("undecidable\n");
    else
      printf("%lld %lld\n", ansX[i], ansY[i]);
  }
  return 0;
}
