#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> vis(n, false);

  int ans = 0;
  auto f = [&](auto f, int x, int p) -> void {
    for (int t : g[x]) {
      if (t == p) continue;
      if (vis[t]) {
        ++ans;
        continue;
      }
      vis[t] = true;
      f(f, t, x);
    }
  };
  rep(i, 0, n) {
    if (vis[i]) continue;
    vis[i] = true;
    f(f, i, -1);
  }
  cout << ans / 2 << endl;
  return 0;
}
