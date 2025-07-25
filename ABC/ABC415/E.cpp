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
  int h, w;
  cin >> h >> w;
  vector a(h, vector<ll>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  vector<ll> p(h + w - 1);
  rep(i, 0, h + w - 1) cin >> p[i];

  const ll INF = 1e18;
  vector dp(h, vector<ll>(w, INF));
  dp[h - 1][w - 1] = 0;
  rrep(i, h - 1, 0) {
    rrep(j, w - 1, 0) {
      dp[i][j] += p[i + j] - a[i][j];
      chmax(dp[i][j], 0LL);

      if (i) chmin(dp[i - 1][j], dp[i][j]);
      if (j) chmin(dp[i][j - 1], dp[i][j]);
    }
  }

  cout << dp[0][0] << endl;
  return 0;
}
