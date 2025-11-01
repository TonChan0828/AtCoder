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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  string s;
  cin >> s;

  const int INF = 1001001001;
  using P = pair<int, int>;
  vector<vector<P>> dist(n);
  queue<tuple<int, int, int>> q;

  auto push = [&](int v, int sv, int d) {
    if (dist[v].size() >= 2) return;
    for (auto p : dist[v]) {
      if (p.second == sv) return;
    }
    dist[v].emplace_back(d, sv);
    q.emplace(v, sv, d);
  };
  rep(v, 0, n) if (s[v] == 'S') push(v, v, 0);

  while (q.size()) {
    auto [v, sv, d] = q.front();
    q.pop();
    for (int u : g[v]) push(u, sv, d + 1);
  }

  rep(v, 0, n) {
    if (s[v] == 'D') {
      int ans = dist[v][0].first + dist[v][1].first;
      cout << ans << "\n";
    }
  }
  return 0;
}
