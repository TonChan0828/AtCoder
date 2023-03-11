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
  int a, n;
  cin >> a >> n;

  const int MX = 1000000;
  const int INF = 1001001001;
  vector<int> dist(MX, INF);
  queue<int> q;

  auto push = [&](int v, int d) {
    if (dist[v] != INF) return;
    dist[v] = d;
    q.push(v);
  };

  push(1, 0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    int d = dist[v];
    if (ll(v) * a < MX) push(v * a, d + 1);
    if (v >= 10 && v % 10 != 0) {
      string s = to_string(v);
      int len = s.size();
      rotate(s.begin(), s.begin() + (len - 1), s.end());
      int u = stoi(s);
      push(u, d + 1);
    }
  }

  if (dist[n] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[n] << endl;
  }
  return 0;
}
