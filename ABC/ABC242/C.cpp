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
  ll r = 998244353;

  vector<vector<ll>> dp(n, vector<ll>(9, 0));
  rep(i, 0, 9) dp[0][i] = 1;
  rep(i, 1, n) {
    rep(j, 0, 9) {
      rep(k, j - 1, j + 2) {
        if (k >= 0 && k < 9) {
          dp[i][j] = (dp[i][j] + dp[i - 1][k]) % r;
        }
      }
    }
  }
  ll ans = 0;
  rep(i, 0, 9) { ans = (ans + dp[n - 1][i]) % r; }
  cout << ans << endl;

  return 0;
}
