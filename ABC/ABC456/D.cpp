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

const ll mod = 998244353;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  vector dp(n + 1, vector<ll>(3));
  rep(i, 0, n) {
    rep(j, 0, 3) dp[i + 1][j] += dp[i][j];
    int j = s[i] - 'a';
    dp[i + 1][j]++;
    dp[i + 1][j] += dp[i][(j + 1) % 3];
    dp[i + 1][j] += dp[i][(j + 2) % 3];
    dp[i + 1][j] %= mod;
  }

  // rep(j, 0, 3) {
  //   rep(i, 0, n + 1) cout << dp[i][j] << " ";
  //   cout << endl;
  // }

  ll ans = 0;
  rep(j, 0, 3) {
    ans += dp[n][j];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
