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
  int n, x;
  cin >> n >> x;
  vector<int> t(n);
  rep(i, 0, n) cin >> t[i];

  vector<mint> dp(x + 1);
  dp[0] = 1;
  mint p = mint(1) / n;
  rep(i, 0, x + 1) {
    rep(j, 0, n) {
      int ni = i + t[j];
      if (ni <= x) dp[ni] += dp[i] * p;
    }
  }

  mint ans;
  rep(i, 0, x + 1) {
    if (i + t[0] > x) {
      ans += dp[i] * p;
    }
  }
  cout << ans.val() << endl;
  return 0;
}
