#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s, --t;
  vector<vector<int>> g(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }
  rep(i, 0, n) sort(g[i].begin(), g[i].end());

  const int INF = 1001001001;
  using P = pair<int, int>;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push({0, s});
  vector<int> cost(n, INF);
  while (!q.empty()) {
    auto [c, i] = q.top();
    q.pop();
    if (c >= cost[i]) continue;
    cost[i] = c;
    rep(j, 0, g[i].size()) {
      int nc = c;
      if (j) nc++;
      if (cost[g[i][j]] > nc) {
        q.push({nc, g[i][j]});
        // cost[g[i][j]] = nc;
        // cout << i << " " << g[i][j] << " " << nc << endl;
      }
    }
  }
  if (cost[t] == INF) {
    cout << -1 << endl;
  } else {
    cout << cost[t] << endl;
  }
  return 0;
}
