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
  int r, c;
  cin >> r >> c;
  vector<vector<char>> b(r, vector<char>(c)), ans(r, vector<char>(c));

  rep(i, 0, r) {
    rep(j, 0, c) { cin >> b[i][j]; }
  }
  ans = b;

  rep(i, 0, r) {
    rep(j, 0, c) {
      if (b[i][j] == '.' || b[i][j] == '#') continue;
      // cout << i << " " << j << endl;
      int t = b[i][j] - '0';
      rep(k, i - t, i + t + 1) {
        if (k < 0 || k >= r) continue;
        rep(l, j - t, j + t + 1) {
          if (l < 0 || l >= c) continue;
          // cout << k << " " << l << endl;
          if (abs(i - k) + abs(j - l) <= t) ans[k][l] = '.';
        }
      }
      // rep(i, 0, r) {
      //   rep(j, 0, c) cout << ans[i][j];
      //   cout << endl;
      // }
      // cout << endl;
    }
  }

  rep(i, 0, r) {
    rep(j, 0, c) cout << ans[i][j];
    cout << endl;
  }
  return 0;
}
