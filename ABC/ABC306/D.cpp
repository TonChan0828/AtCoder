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
  vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));

  rep(i, 0, n) {
    int x, y;
    cin >> x >> y;

    dp[0][i + 1] = dp[0][i];
    dp[1][i + 1] = dp[1][i];

    if (x == 0) {
      dp[0][i + 1] = max(dp[0][i + 1], dp[0][i] + y);
      dp[0][i + 1] = max(dp[0][i + 1], dp[1][i] + y);
    } else {
      dp[1][i + 1] = max(dp[1][i + 1], dp[0][i] + y);
    }
  }
  cout << max(dp[0][n], dp[1][n]) << endl;
  return 0;
}
