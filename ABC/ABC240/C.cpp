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
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  vector<vector<int>> dp(n + 1, vector<int>(10101, -1));
  dp[0][0] = 0;
  rep(i, 0, n) {
    rep(j, 0, x + 1) {
      if (dp[i][j] == i) {
        dp[i + 1][j + a[i]] = dp[i][j] + 1;
        dp[i + 1][j + b[i]] = dp[i][j] + 1;
      }
    }
    // rep(j, 0, x + 1) { cout << dp[j] << " "; }
    // cout << endl;
  }

  if (dp[n][x] == n) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
