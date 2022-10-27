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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int h, w;
vector<string> a;
vector<vector<bool>> b(1000, vector<bool>(1000, false));

int f(set<pair<int, int>> s) {
  int cnt = 0;
  set<pair<int, int>> x;
  for (pair<int, int> p : s) {
    rep(i, 0, 4) {
      int nx = p.second + dx[i];
      int ny = p.first + dy[i];
      if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if (b[ny][nx]) continue;
      x.insert({ny, nx});
      b[ny][nx] = true;
    }
  }
  if (x.size()) {
    return 1 + f(x);
  } else {
    return 0;
  }
}

int main() {
  cin >> h >> w;
  a.resize(h);
  rep(i, 0, h) cin >> a[i];
  set<pair<int, int>> s;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (a[i][j] == '#') {
        s.insert({i, j});
        b[i][j] = true;
      }
    }
  }
  cout << f(s) << endl;
  return 0;
}
