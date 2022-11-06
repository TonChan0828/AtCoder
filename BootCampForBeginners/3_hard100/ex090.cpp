#include <bits/stdc++.h>
using namespace std;
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
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> ver(n + 1);

  rep(i, 0, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    ver[u].push_back({v, w});
    ver[v].push_back({u, w});
  }
  vector<int> ans(n, -1);
  ans[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    int p = ans[x];
    for (pair<int, int> tmp : ver[x]) {
      if (ans[tmp.first] != -1) continue;
      q.push(tmp.first);
      ans[tmp.first] = (p + tmp.second) % 2;
    }
  }

  rep(i, 0, n) { cout << ans[i] << endl; }
  return 0;
}
