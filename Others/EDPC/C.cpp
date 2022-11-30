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
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, 0, n) {
    cin >> a[i];
    cin >> b[i];
    cin >> c[i];
  }
  vector<vector<int>> dp(3, vector<int>(n, 0));
  dp[0][0] = a[0];
  dp[1][0] = b[0];
  dp[2][0] = c[0];
  rep(i, 1, n) {
    dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[i];
    dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + b[i];
    dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
  }
  int ans = max(dp[0][n - 1], dp[1][n - 1]);
  ans = max(ans, dp[2][n - 1]);
  cout << ans << endl;

  return 0;
}
