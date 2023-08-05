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
  const int INF = 1010101;
  vector<int> vis(n, INF), sign(n);
  vis[0] = sign[0] = 0;
  queue<pair<int, int>> q;
  q.push({0, -1});

  while (!q.empty()) {
    auto [x, p] = q.front();
    // cout << x << endl;
    q.pop();

    for (int y : g[x]) {
      if (vis[y] != INF) continue;
      vis[y] = vis[x] + 1;
      sign[y] = x;
      q.push({y, x});
    }
  }

  rep(i, 0, n) {
    if (vis[i] == INF) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes\n";
  rep(i, 1, n) cout << sign[i] + 1 << "\n";

  return 0;
}
