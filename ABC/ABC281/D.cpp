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
  int n, k, d;
  cin >> n >> k >> d;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector dp(n + 1, vector(k + 1, vector<ll>(d, -1)));
  dp[0][0][0] = 0;

  rep(i, 0, n) {
    rep(j, 0, k + 1) {
      rep(l, 0, d) {
        if (dp[i][j][l] == -1) continue;

        dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
        if (j != k) {
          dp[i + 1][j + 1][(l + a[i]) % d] =
              max(dp[i + 1][j + 1][(l + a[i]) % d], dp[i][j][l] + a[i]);
        }
      }
    }
  }

  cout << dp[n][k][0] << endl;
  return 0;
}
