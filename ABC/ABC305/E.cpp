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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n);

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<pair<int, int>> health;
  rep(i, 0, k) {
    int p, h;
    cin >> p >> h;
    --p;
    health.push_back({h, p});
  }
  sort(health.begin(), health.end(), greater());

  vector<int> vis(n, -1);

  for (auto [h, p] : health) {
    if (h <= vis[p]) continue;
    vis[p] = h;
    queue<pair<int, int>> q;
    q.push({p, p});
    while (!q.empty()) {
      auto [x, p] = q.front();
      q.pop();
      if (x != p) {
        if (vis[x] >= vis[p] - 1) continue;
        vis[x] = vis[p] - 1;
        if (vis[x] <= 0) continue;
      }
      // printf("%d %d\n", x, vis[x]);
      for (int y : g[x]) {
        if (y == p) continue;
        q.push({y, x});
      }
    }
  }

  int ans = 0;
  rep(i, 0, n) {
    if (vis[i] > -1) ++ans;
  }
  cout << ans << endl;
  rep(i, 0, n) {
    if (vis[i] > -1) printf("%d ", i + 1);
  }
  cout << "\n";
  return 0;
}
