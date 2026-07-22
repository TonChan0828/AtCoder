#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(n - 1);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n - 1) cin >> b[i];

  vector dp(n, vector<int>(2, 0));
  if (a[0] == 0) {
    dp[0][0] = 0, dp[0][1] = 1;
  } else {
    dp[0][0] = 1, dp[0][1] = 0;
  }

  rep(i, 1, n) {
    if (b[i - 1] == 0) {
      if (a[i] == 0) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1] + 1;
      } else {
        dp[i][0] = dp[i - 1][0] + 1;
        dp[i][1] = dp[i - 1][1];
      }
    } else {
      if (a[i] == 0) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + 1;
      } else {
        dp[i][0] = dp[i - 1][1] + 1;
        dp[i][1] = dp[i - 1][0];
      }
    }
  }

  cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
  return 0;
}
