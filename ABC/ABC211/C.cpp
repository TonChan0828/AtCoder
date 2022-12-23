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
  string s;
  cin >> s;
  ll r = pow(10, 9) + 7;
  string a = "chokudai";
  vector<vector<ll>> dp(s.size() + 1, vector<ll>(9, 0));
  dp[0][0] = 1;
  rep(i, 1, s.size() + 1) {
    dp[i][0] = 1;
    rep(j, 1, 9) {
      if (s[i - 1] == a[j - 1]) {
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % r;
      } else {
        dp[i][j] = dp[i - 1][j] % r;
      }
    }
  }
  cout << dp[s.size()][8] << endl;
  return 0;
}
