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
  ll x, y, z;
  string s;
  cin >> x >> y >> z >> s;
  int n = s.size();

  vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));

  dp[1][0] = z;
  rep(i, 1, n + 1) {
    if (s[i - 1] == 'a') {
      dp[0][i] = min(dp[0][i - 1] + x, dp[1][i - 1] + z + x);
      dp[1][i] = min(dp[0][i - 1] + z + y, dp[1][i - 1] + y);
    } else {
      dp[0][i] = min(dp[0][i - 1] + y, dp[1][i - 1] + z + y);
      dp[1][i] = min(dp[0][i - 1] + z + x, dp[1][i - 1] + x);
    }
  }
  cout << min(dp[0][n], dp[1][n]) << endl;
  return 0;
}
