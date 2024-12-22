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
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  --x, --y;
  vector<string> s(h);
  string t;
  rep(i, 0, h) cin >> s[i];
  cin >> t;

  vector vis(h, vector<bool>(w, false));

  for (char c : t) {
    if (c == 'U') {
      if (x - 1 >= 0 && s[x - 1][y] != '#') --x;
    } else if (c == 'D') {
      if (x + 1 < h && s[x + 1][y] != '#') ++x;
    } else if (c == 'L') {
      if (y - 1 >= 0 && s[x][y - 1] != '#') --y;
    } else {
      if (y + 1 < w && s[x][y + 1] != '#') ++y;
    }

    if (s[x][y] == '@') vis[x][y] = true;
    // cout << x << " " << y << endl;
  }

  int ans = 0;
  rep(i, 0, h) rep(j, 0, w) if (vis[i][j])++ ans;

  printf("%d %d %d\n", x + 1, y + 1, ans);
  return 0;
}
