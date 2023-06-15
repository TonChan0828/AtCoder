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
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<mint>> dp(k + 1, vector<mint>(n + 1, 0));
  dp[0][0] = 1;
  rep(i, 0, k) {
    rep(j, 0, n) {
      rep(t, 1, m + 1) {
        if (j + t > n) {
          dp[i + 1][n - (j + t - n)] += dp[i][j];
        } else {
          dp[i + 1][j + t] += dp[i][j];
        }
      }
    }
  }
  // rep(i, 0, k + 1) {
  //   rep(j, 0, n + 1) { cout << dp[i][j].val() << " "; }
  //   cout << endl;
  // }

  mint ans = 0;
  mint cnt = 1;
  rep(i, 1, k + 1) {
    cnt *= m;
    ans += dp[i][n] / cnt;
  }
  cout << ans.val() << endl;
  return 0;
}
