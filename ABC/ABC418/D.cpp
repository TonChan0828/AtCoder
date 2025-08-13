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
  string t;
  cin >> n >> t;
  vector dp(n + 1, vector<int>(2));

  rep(i, 1, n + 1) {
    if (t[i - 1] == '0') {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] + 1;
    } else {
      dp[i][0] = dp[i - 1][0] + 1;
      dp[i][1] = dp[i - 1][1];
    }
  }
  ll ans = 0;
  rep(i, 1, n + 1) ans += dp[i][0];
  cout << ans << endl;
  return 0;
}
