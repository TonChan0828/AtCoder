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
  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<char>> ans(h, vector<char>(w));
  rep(i, 0, h) {
    rep(j, 0, w) { cin >> a[i][j]; }
  }
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (a[i][j] == 0) {
        ans[i][j] = '.';
      } else {
        ans[i][j] = (char)('A' + (a[i][j] - 1));
        // cout << (char)('A' + (a[i][j] - 1)) << endl;
      }
    }
  }

  rep(i, 0, h) {
    rep(j, 0, w) { cout << ans[i][j]; }
    cout << endl;
  }
  return 0;
}
