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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  const int dx[] = {0, -1, 1, 0};
  const int dy[] = {-1, 0, 0, 1};
  vector<vector<bool>> vis(h, vector<bool>(w, false));
  ll ans = 0;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (vis[i][j]) continue;
      if (s[i][j] == '.') continue;

      ll bl = 0, wh = 0;
      queue<pair<int, int>> q;
      vis[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (s[y][x] == '#') {
          ++bl;
        } else {
          ++wh;
        }
        rep(k, 0, 4) {
          int nx = x + dx[k], ny = y + dy[k];
          if (ny < 0 || ny > h - 1 || nx < 0 || nx > w - 1) continue;
          if (vis[ny][nx]) continue;
          if (s[y][x] == '.' && s[ny][nx] == '#') {
            vis[ny][nx] = true;
            q.push({ny, nx});
          }
          if (s[y][x] == '#' && s[ny][nx] == '.') {
            vis[ny][nx] = true;
            q.push({ny, nx});
          }
        }
      }
      ans += bl * wh;
    }
  }

  cout << ans << endl;
  return 0;
}
