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
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<vector<int>> dp(3030, vector<int>(3030));
  double ma = 0;
  int ans1 = 100 * a, ans2 = 0;
  dp[0][0] = 1;
  rep(i, 1, f + 1) {
    rep(j, 0, i + 1) {
      int water = i - j;
      int sugar = j;

      if (100 * a <= i)
        if (dp[i - 100 * a][j]) dp[i][j] = 1;
      if (100 * b <= i)
        if (dp[i - 100 * b][j]) dp[i][j] = 1;
      if (c <= i && c <= j)
        if (dp[i - c][j - c]) dp[i][j] = 1;
      if (d <= i && d <= j)
        if (dp[i - d][j - d]) dp[i][j] = 1;

      if (sugar * 100 <= water * e && dp[i][j] && 0 < j) {
        double e = 1.0 * 100 * j / i;
        if (ma < e) {
          ma = e;
          ans1 = i;
          ans2 = j;
        }
      }
    }
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}
