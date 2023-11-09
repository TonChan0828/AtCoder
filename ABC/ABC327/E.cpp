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
  cin >> n;
  vector<double> p(n);
  rep(i, 0, n) cin >> p[i];

  vector dp(n, vector<double>(n, 0));
  rrep(i, n - 1, 0) {
    if (i == n - 1) {
      dp[0][i] = p[i];
    } else {
      dp[0][i] = dp[0][i + 1];
      chmax(dp[0][i], p[i]);
    }
  }
  double q = 0.9;
  rep(i, 1, n) {
    dp[i][n - 1 - i] = dp[i - 1][n - i] + p[n - 1 - i] * q;
    rrep(j, n - 2 - i, 0) {
      dp[i][j] = dp[i][j + 1];
      chmax(dp[i][j], dp[i - 1][j + 1] + p[j] * q);
    }
    q *= 0.9;
  }
  // rep(i, 0, n) {
  //   rep(j, 0, n) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }

  double ans = 0 - __DBL_MAX__;
  q = 1;
  double sumq = q;
  rep(i, 0, n) {
    chmax(ans, dp[i][0] / sumq - (double)1200 / sqrt(i + 1));
    q *= 0.9;
    sumq += q;
  }
  printf("%.10lf\n", ans);
  return 0;
}
