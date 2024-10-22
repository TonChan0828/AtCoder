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
  vector<vector<int>> g(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }

  const int INF = 1001001001;
  vector<int> vis(n, INF);
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int cost = p.first, now = p.second;
    for (int x : g[now]) {
      if (vis[x] <= cost + 1) continue;
      vis[x] = cost + 1;
      pq.push({cost + 1, x});
    }
  }

  int ans = vis[0];
  if (vis[0] == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
