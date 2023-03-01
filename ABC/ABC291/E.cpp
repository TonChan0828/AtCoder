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

// int main() {
//   int n, m;
//   cin >> n >> m;
//   vector<int> deg(n);
//   vector<vector<int>> to(n);
//   rep(i, 0, m) {
//     int x, y;
//     cin >> x >> y;
//     --x, --y;
//     to[y].push_back(x);
//     ++deg[x];
//   }

//   queue<int> q;
//   rep(i, 0, n) {
//     if (deg[i] == 0) q.push(i);
//   }

//   vector<int> a(n);
//   int na = n;
//   while (!q.empty()) {
//     if (q.size() > 1) {
//       cout << "No" << endl;
//       return 0;
//     }
//     int v = q.front();
//     q.pop();
//     a[v] = na, --na;
//     for (int u : to[v]) {
//       --deg[u];
//       if (!deg[u]) q.push(u);
//     }
//   }

//   cout << "Yes" << endl;
//   rep(i, 0, n) { cout << a[i] << " "; }
//   cout << endl;

//   return 0;
// }

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n);
  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    to[y].push_back(x);
  }

  vector<int> vs;
  vector<bool> visited(n);

  auto dfs = [&](auto dfs, int v) -> void {
    if (visited[v]) return;
    visited[v] = true;
    for (int u : to[v]) {
      dfs(dfs, u);
    }
    vs.push_back(v);
  };

  rep(i, 0, n) dfs(dfs, i);

  rep(i, 0, n - 1) {
    int a = vs[i], b = vs[i + 1];
    bool ok = false;
    for (int v : to[b]) {
      if (v == a) ok = true;
    }
    if (!ok) {
      cout << "No" << endl;
      return 0;
    }
  }
  vector<int> a(n);
  rep(i, 0, n) { a[vs[i]] = i + 1; }
  cout << "Yes" << endl;
  rep(i, 0, n) { cout << a[i] << " "; }
  cout << endl;
  return 0;
}