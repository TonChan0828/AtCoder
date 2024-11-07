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
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  int ans = 0;
  vector vis(h, vector<int>(w, -1));

  auto dfs = [&](auto dfs, int y, int x) {
    if (vis[y][x] == k) {
      ++ans;
      return;
    }

    rep(d, 0, 4) {
      int ny = y + dy[d], nx = x + dx[d];
      if (ny < 0 || ny > h - 1 || nx < 0 || nx > w - 1) continue;
      if (s[ny][nx] == '#') continue;
      if (vis[ny][nx] != -1) continue;
      vis[ny][nx] = vis[y][x] + 1;
      dfs(dfs, ny, nx);
      vis[ny][nx] = -1;
    }
  };

  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == '#') continue;
      vis[i][j] = 0;
      dfs(dfs, i, j);
      vis[i][j] = -1;
      // cout << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
