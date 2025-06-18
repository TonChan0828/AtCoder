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
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector g(n, vector<P>());
  rep(i, 0, m) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    g[a].emplace_back(b, w);
  }
  vector<bool> visited(n * 1024);
  queue<int> q;
  auto push = [&](int v, int x) {
    int vid = v * 1024 + x;
    if (visited[vid]) return;
    visited[vid] = true;
    q.push(vid);
  };
  push(0, 0);

  while (q.size()) {
    int vid = q.front();
    q.pop();
    int v = vid / 1024, x = vid % 1024;
    for (auto [n, w] : g[v]) push(n, x ^ w);
  }

  rep(i, 0, 1024) {
    if (visited[(n - 1) * 1024 + i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
