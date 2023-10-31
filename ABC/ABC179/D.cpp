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
  int n, k;
  cin >> n >> k;
  vector<int> l(k), r(k);
  rep(i, 0, k) cin >> l[i] >> r[i];
  vector<mint> dp(n + 1, 0), sum(n + 1, 0);
  dp[1] = 1;
  rep(i, 1, n + 1) {
    rep(j, 0, k) {
      if (i <= l[j]) continue;
      dp[i] += sum[i - l[j]] - sum[max(i - (r[j] + 1), 0)];
    }
    sum[i] = sum[i - 1] + dp[i];
  }
  cout << dp[n].val() << endl;
  return 0;
}
