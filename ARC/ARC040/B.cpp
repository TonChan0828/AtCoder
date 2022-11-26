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
  int n, r;
  string s;
  cin >> n >> r >> s;

  int ans = 0, j;
  rrep(i, n - 1, 0) {
    if (s[i] == '.') {
      j = max(0, i - r + 1);
      ans = j + 1;
      break;
    }
  }
  rep(i, 0, j) {
    if (s[i] == '.') {
      ++ans;
      i += r - 1;
    }
  }
  cout << ans << endl;

  // const int inf = 100010;
  // vector<vector<int>> dp(n, vector<int>(n, inf));
  // if (s[0] == '.') {
  //   dp[0][0] = 1;
  // } else {
  //   dp[0][0] = 0;
  // }
  // rep(i, 1, r) {
  //   if (s[i] == 'o') {
  //     dp[0][i] = dp[0][i - 1];
  //   } else {
  //     dp[0][i] = 1;
  //   }
  // }
  // rep(i, 1, n) {
  //   rep(j, 0, n) {
  //     if (dp[i - 1][j] != inf) {
  //       dp[i][j] = dp[i - 1][j];
  //     } else {
  //       if (s[j] == 'o') {
  //         dp[i][j] = dp[i][j - 1];
  //       } else {
  //         if (j >= i + r) break;
  //         dp[i][j] = dp[i][j - r] + 1;
  //       }
  //     }
  //   }
  // }
  // rep(i, 0, n) {
  //   rep(j, 0, n) {
  //     if (j != 0) cout << " ";
  //     cout << dp[i][j];
  //   }
  //   cout << endl;
  // }
  // int ans = INT_MAX;
  // rep(i, 0, n) { ans = min(ans, dp[i][n - 1] + i); }
  // cout << ans << endl;
  return 0;
}
