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

const ll INF = 1010101010101010;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  --x, --y;
  vector g(n, vector<tuple<int, ll, ll>>());
  rep(i, 0, m) {
    ll a, b, t, k;
    cin >> a >> b >> t >> k;
    --a, --b;
    g[a].push_back({b, t, k});
    g[b].push_back({a, t, k});
  }

  vector<ll> vis(n, INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  pq.push({0, x});
  while (!pq.empty()) {
    auto [time, t] = pq.top();
    pq.pop();
    if (vis[t] <= time) continue;
    vis[t] = time;
    for (auto [bb, tt, kk] : g[t]) {
      ll t2 = ((time + kk - 1) / kk) * kk;
      pq.push({t2 + tt, bb});
    }
  }

  cout << (vis[y] == INF ? -1 : vis[y]) << endl;
  return 0;
}
