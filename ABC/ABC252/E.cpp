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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

struct Road {
  int v;
  int road;
  ll cost;
};
struct Point {
  int road;
  ll cost;
};

const ll INF = __LONG_LONG_MAX__;
using P = pair<ll, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Road>> g(n);
  rep(i, 1, m + 1) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].push_back({b, i, c});
    g[b].push_back({a, i, c});
  }

  vector<Point> vis(n, {-1, INF});
  vis[0] = {-1, 0};

  priority_queue<P, vector<P>, greater<P>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto [cost, now] = q.top();
    q.pop();
    if (vis[now].cost != cost) continue;
    for (Road nxt : g[now]) {
      if (nxt.road == vis[nxt.v].road) continue;
      ll costN = cost + nxt.cost;
      if (vis[nxt.v].cost <= costN) continue;
      vis[nxt.v] = {nxt.road, costN};
      q.push({costN, nxt.v});
    }
  }

  rep(i, 1, n) { cout << vis[i].road << " "; }
  cout << endl;
  return 0;
}
