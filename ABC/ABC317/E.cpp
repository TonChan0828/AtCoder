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
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];

  int sx, sy, gx, gy;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (a[i][j] == 'S') sy = i, sx = j;
      if (a[i][j] == 'G') gy = i, gx = j;
    }
  }
  string tar = "><v^";
  bool ng = false;
  auto f = [&](int i, int j, char c) -> void {
    if (a[i][j] == c) {
      ng = true;
      return;
    }
    if (a[i][j] == '.' || a[i][j] == 'S' || a[i][j] == 'G' || a[i][j] == '!') {
      if (ng) a[i][j] = '!';
    } else {
      ng = false;
    }
  };

  rep(i, 0, h) {
    ng = false;
    rep(j, 0, w) { f(i, j, tar[0]); }
    ng = false;
    rrep(j, w - 1, 0) { f(i, j, tar[1]); }
  }

  rep(j, 0, w) {
    ng = false;
    rep(i, 0, h) { f(i, j, tar[2]); }
    ng = false;
    rrep(i, h - 1, 0) { f(i, j, tar[3]); }
  }
  const int dx[] = {0, -1, 1, 0};
  const int dy[] = {-1, 0, 0, 1};
  vector vis(h, vector<int>(w, -1));
  vis[sy][sx] = 0;
  queue<pair<int, int>> q;

  q.push({sy, sx});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    rep(i, 0, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (a[ny][nx] == '#' || a[ny][nx] == '!') continue;
      if (tar.find(a[ny][nx]) != string::npos) continue;
      if (vis[ny][nx] != -1) continue;
      vis[ny][nx] = vis[y][x] + 1;
      q.push({ny, nx});
    }
  }

  // cout << "\n";
  // rep(i, 0, h) { cout << a[i] << endl; }
  // rep(i, 0, h) {
  //   rep(j, 0, w) { cout << vis[i][j] << " "; }
  //   cout << "\n";
  // }
  cout << vis[gy][gx] << endl;
  return 0;
}
