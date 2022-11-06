#include <bits/stdc++.h>
using namespace std;
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
  vector<vector<char>> c(h, vector<char>(w));
  pair<int, int> p;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  rep(i, 0, h) {
    rep(j, 0, w) {
      cin >> c[i][j];
      if (c[i][j] == 'S') p = make_pair(i, j);
    }
  }
  vector<vector<int>> t(h, vector<int>(w, -1));
  vector<vector<int>> pa(h, vector<int>(w, -1));
  queue<vector<int>> q;
  t[p.first][p.second] = 0;
  pa[p.first][p.second] = 4;
  rep(i, 0, 4) {
    int nx = p.second + dx[i];
    int ny = p.first + dy[i];
    if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
    if (c[ny][nx] == '#') continue;
    t[ny][nx] = 1;
    pa[ny][nx] = i;
    q.push({nx, ny});
  }
  q.push({p.second, p.first});
  while (!q.empty()) {
    int x = q.front()[0];
    int y = q.front()[1];
    q.pop();
    rep(i, 0, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if (c[ny][nx] == '#') continue;
      if (t[ny][nx] != -1) {
        if (t[ny][nx] + t[y][x] + 1 >= 4 && pa[ny][nx] != pa[y][x]) {
          cout << "Yes" << endl;
          return 0;
        }
      } else {
        t[ny][nx] = t[y][x] + 1;
        pa[ny][nx] = pa[y][x];
        q.push({nx, ny});
      }
    }
  }

  // rep(i, 0, h) {
  //   rep(j, 0, w) { cout << pa[i][j]; }
  //   cout << endl;
  // }
  // cout << endl;
  // rep(i, 0, h) {
  //   rep(j, 0, w) { cout << t[i][j]; }
  //   cout << endl;
  // }

  cout << "No" << endl;
  return 0;
}
