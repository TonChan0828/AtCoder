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
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, 1, n) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }

  vector<int> xy(n, -1);
  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    --x, y;
    xy[x] = max(xy[x], y);
  }

  vector<int> com(n, -1);
  rep(i, 0, n) {
    if (xy[i] == -1) continue;
    if (com[i] >= xy[i]) continue;

    queue<pair<int, int>> q;
    q.push({i, xy[i]});
    com[i] = xy[i];
    while (!q.empty()) {
      auto [c, p] = q.front();
      q.pop();

      if (p == 0) {
        continue;
      }
      --p;
      for (int x : g[c]) {
        if (xy[x] >= p) continue;
        if (com[x] >= p) continue;
        com[x] = p;
        q.push({x, p});
      }
    }
  }

  int cnt = 0;
  rep(i, 0, n) {
    // cout << com[i] << endl;
    if (com[i] != -1) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
