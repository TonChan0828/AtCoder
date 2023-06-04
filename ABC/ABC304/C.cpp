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
  int n, d;
  cin >> n >> d;
  d *= d;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];

  queue<int> q;
  vector<int> vis(n, false);
  q.push(0);
  while (!q.empty()) {
    int tar = q.front();
    q.pop();
    vis[tar] = true;
    // cout << tar << endl;
    rep(i, 0, n) {
      if (vis[i]) continue;
      int dx = abs(x[tar] - x[i]);
      dx *= dx;
      int dy = abs(y[tar] - y[i]);
      dy *= dy;
      int dist = dx + dy;
      if (dist <= d) {
        vis[i] = true;
        q.push(i);
      }
    }
  }
  rep(i, 0, n) {
    if (vis[i]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
