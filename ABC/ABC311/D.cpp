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
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vector<int> dx{0, -1, 0, 1}, dy{-1, 0, 1, 0};

  queue<pair<int, int>> q;
  q.push({1, 1});
  vis[1][1] = true;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    rep(i, 0, 4) {
      int tx = x, ty = y;
      while (s[ty + dy[i]][tx + dx[i]] != '#') {
        vis[ty][tx] = true;
        // printf("%d %d\n", ty, tx);
        ty += dy[i], tx += dx[i];
      }
      if (vis[ty][tx]) continue;
      vis[ty][tx] = true;
      q.push({ty, tx});
    }
  }
  int cnt = 0;
  rep(i, 0, n) {
    rep(j, 0, m) {
      if (vis[i][j]) ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}
