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
  string snuke = "snuke";
  int dx[] = {0, -1, 1, 0};
  int dy[] = {-1, 0, 0, 1};
  bool ok = false;
  vector<vector<bool>> vis(h, vector<bool>(w, false));
  auto f = [&](auto f, int y, int x, int cnt) -> void {
    if (ok) return;
    if (snuke[cnt % 5] != s[y][x]) return;
    vis[y][x] = true;
    // cout << s[y][x];
    if (y == h - 1 && x == w - 1) {
      ok = true;
      return;
    }
    rep(i, 0, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if (vis[ny][nx]) continue;
      f(f, ny, nx, cnt + 1);
    }
    return;
  };
  f(f, 0, 0, 0);
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
