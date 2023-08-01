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

using mint = modint998244353;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector dp(n + 1, vector<mint>(n + 1));
  dp[0][0] = 1;
  rep(i, 0, n) {
    rep(j, 0, n) {
      if (s[i] != ')') dp[i + 1][j + 1] += dp[i][j];
      if (j != 0 && s[i] != '(') dp[i + 1][j - 1] += dp[i][j];
      // printf("%d ", dp[i][j]);
    }
    // cout << endl;
  }
  cout << dp[n][0].val() << endl;
  return 0;
}
