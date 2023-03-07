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
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  const ll mod = 998244353;

  vector<vector<ll>> dp(n + 1, vector<ll>(3001, 0));

  dp[0][0] = 1;
  rep(i, 0, n + 1) {
    rep(j, 0, 3000) {
      dp[i][j + 1] += dp[i][j];
      dp[i][j + 1] %= mod;
    }
    if (i != n) {
      rep(j, a[i], b[i] + 1) {
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= mod;
      }
    }
  }

  cout << dp[n][3000] << endl;
  return 0;
}
