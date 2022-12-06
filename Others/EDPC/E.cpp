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
  int N, W;
  cin >> N >> W;
  vector<int> w(N + 1), v(N + 1);
  rep(i, 0, N) cin >> w[i] >> v[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(201010, W + 1));
  dp[0][0] = 0;
  rep(i, 0, N) {
    rep(j, 0, N * 1010 + 1) {
      chmin(dp[i + 1][j], dp[i][j]);
      chmin(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
    }
  }
  int ans = 0;
  rep(i, 0, N * 1010 + 1) {
    if (dp[N][i] <= W) chmax(ans, i);
  }
  cout << ans << endl;
  return 0;
}
