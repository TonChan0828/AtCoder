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
  string s, t;
  cin >> s >> t;
  int sz = s.size(), tz = t.size();
  vector<vector<int>> dp(sz + 1, vector<int>(tz + 1, 0));

  rep(i, 1, sz + 1) {
    rep(j, 1, tz + 1) {
      if (s[i - 1] == t[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  int len = dp[sz][tz];
  int i = sz - 1, j = tz - 1;
  vector<char> ans(len);
  while (len > 0) {
    if (s[i] == t[j]) {
      ans[len - 1] = s[i];
      --i, --j, --len;
    } else if (dp[i + 1][j + 1] == dp[i][j + 1]) {
      --i;
    } else {
      --j;
    }
  }
  rep(i, 0, dp[sz][tz]) cout << ans[i];
  cout << endl;
  return 0;
}
