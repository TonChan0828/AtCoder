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
using mint = modint998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  vector<vector<mint>> dp(n, vector<mint>(2, 0));
  dp[0][0] = dp[0][1] = 1;
  rep(i, 1, n) {
    if (a[i] != a[i - 1]) dp[i][0] += dp[i - 1][0];
    if (a[i] != b[i - 1]) dp[i][0] += dp[i - 1][1];
    if (b[i] != a[i - 1]) dp[i][1] += dp[i - 1][0];
    if (b[i] != b[i - 1]) dp[i][1] += dp[i - 1][1];
  }
  mint ans = dp[n - 1][0] + dp[n - 1][1];
  cout << ans.val() << endl;
  return 0;
}
