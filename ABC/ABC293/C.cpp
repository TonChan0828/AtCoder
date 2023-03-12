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
  vector<vector<int>> t(h, vector<int>(w, 0));
  rep(i, 0, h) { rep(j, 0, w) cin >> t[i][j]; }

  auto f = [&](auto f, int y, int x, set<int> s) -> ll {
    s.insert(t[y][x]);
    if (y == h - 1 && x == w - 1) {
      if (s.size() == h + w - 1) {
        return 1;
      } else {
        return 0;
      }
    }
    ll cnt = 0;
    if (y < h - 1) {
      cnt += f(f, y + 1, x, s);
    }
    if (x < w - 1) {
      cnt += f(f, y, x + 1, s);
    }
    return cnt;
  };
  set<int> st;
  cout << f(f, 0, 0, st) << endl;

  return 0;
}
