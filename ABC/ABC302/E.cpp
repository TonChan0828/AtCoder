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
  int n, Q;
  cin >> n >> Q;

  vector<set<int>> g(n);
  int cnt = n;
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      if (g[u].empty()) --cnt;
      if (g[v].empty()) --cnt;
      g[u].insert(v);
      g[v].insert(u);
      cout << cnt << endl;
    } else {
      int v;
      cin >> v;
      --v;
      for (int x : g[v]) {
        g[x].erase(v);
        if (g[x].empty()) ++cnt;
      }
      if (!g[v].empty()) {
        g[v].clear();
        ++cnt;
      }
      cout << cnt << endl;
    }
  }
  return 0;
}
