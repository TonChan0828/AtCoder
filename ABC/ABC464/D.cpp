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
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<ll> x(n), y(n - 1);
    rep(i, 0, n) cin >> x[i];
    rep(i, 0, n - 1) cin >> y[i];

    vector dp(n, vector<ll>(2, 0));

    rep(i, 0, n) {
      if (s[i] == 'R') {
        dp[i][0] = 0;
        dp[i][1] = -x[i];
      } else {
        dp[i][0] = -x[i];
        dp[i][1] = 0;
      }
      if (i) {
        dp[i][0] += max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] += max(dp[i - 1][0] + y[i - 1], dp[i - 1][1]);
      }
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
  }

  return 0;
}
