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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];

  vector dp(n + 1, vector<ll>(2, 0));
  dp[0][0] = dp[0][1] = 1;
  rep(i, 0, n) {
    rep(j, 0, 2) {
      rep(k, 0, 2) {
        if (s[i] == "AND") {
          dp[i + 1][j & k] += dp[i][j];
        } else {
          dp[i + 1][j | k] += dp[i][j];
        }
      }
    }
  }

  // rep(i, 0, n + 1) {
  //   rep(j, 0, 2) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }

  cout << dp[n][1] << endl;
  return 0;
}
