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

const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  rep(i, 1, n + 1) cin >> a[i];
  vector<ll> dp(n + 3), cnt(n + 3);
  dp[1] = a[1];
  cnt[0] = cnt[1] = 1;
  rep(i, 2, n + 1) {
    cnt[i] = cnt[i - 1] + cnt[i - 2];
    if (cnt[i] >= mod) cnt[i] -= mod;
    dp[i] = dp[i - 1] + a[i] * cnt[i - 1];
    dp[i] += dp[i - 2] + (a[i - 1] - a[i]) * cnt[i - 2];
    dp[i] %= mod;
    if (dp[i] < 0) dp[i] += mod;
  }
  cout << dp[n] << endl;
  return 0;
}
