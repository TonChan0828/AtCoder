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
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector<ll> x(n), y(n), z(n);
  rep(i, 0, n) cin >> x[i] >> y[i] >> z[i];
  ll sum = 0;
  rep(i, 0, n) sum += z[i];
  const ll INF = __LONG_LONG_MAX__;
  vector<vector<ll>> dp(sum + 1, vector<ll>(n + 1, INF));
  dp[0][0] = 0;
  rep(i, 0, sum + 1) {
    rep(j, 0, n) {
      dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
      if (dp[i][j] != INF) {
        ll xy = x[j] + y[j];
        dp[i + z[j]][j + 1] =
            min(dp[i + z[j]][j + 1], dp[i][j] + max(0LL, y[j] - xy / 2));
      }
    }
  }

  ll ans = INF;
  rep(i, sum / 2 + 1, sum + 1) {
    if (dp[i][n] != INF) ans = min(ans, dp[i][n]);
  }
  cout << ans << endl;

  return 0;
}
