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

const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> c(n), a(n);
  rep(i, 1, n) cin >> c[i];
  rep(i, 1, n) cin >> a[i];

  vector<int> dp(n, INF);
  dp[0] = 0;
  rep(i, 1, n) {
    rep(j, 1, c[i] + 1) {
      if (a[i - j]) {
        dp[i] = min(dp[i], dp[i - j] + 1);
        break;
      }

      dp[i] = min(dp[i], dp[i - j] + 1);
    }
  }

  int ans = INF;
  rep(i, 1, n) {
    if (a[i]) ans = dp[i];
    // cout << dp[i] << " ";
  }
  cout << ans << endl;
  return 0;
}
