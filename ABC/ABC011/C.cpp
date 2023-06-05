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
  vector<int> ng(3);
  cin >> n;
  rep(i, 0, 3) cin >> ng[i];

  vector<int> dp(301, 0);
  dp[1] = dp[2] = dp[3] = 1;
  rep(i, 0, 3) dp[ng[i]] = 101010;
  rep(i, 4, n + 1) {
    if (i == ng[0] || i == ng[1] || i == ng[2]) continue;
    dp[i] = min(dp[i - 1], dp[i - 2]);
    dp[i] = min(dp[i], dp[i - 3]) + 1;
  }
  // rep(i, 0, n + 1) cout << dp[i] << endl;
  if (dp[n] <= 100) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
