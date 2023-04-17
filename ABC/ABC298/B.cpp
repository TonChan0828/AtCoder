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
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));

  rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
  rep(i, 0, n) rep(j, 0, n) cin >> b[i][j];

  vector<vector<int>> ans(n, vector<int>(n, 0));

  bool ok = false;
  rep(t, 0, 4) {
    bool res = true;
    rep(i, 0, n) {
      rep(j, 0, n) {
        if (a[i][j] == 1 && b[i][j] == 0) res = false;
      }
    }
    ok |= res;
    auto tmp = a;
    rep(i, 0, n) {
      rep(j, 0, n) { a[i][j] = tmp[n - j - 1][i]; }
    }
  }

  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}
