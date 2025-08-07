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
  vector<int> p(n), a(n), b(n);
  rep(i, 0, n) cin >> p[i] >> a[i] >> b[i];
  const int M = 1001;
  vector dp(n + 1, vector<int>(M));
  rep(i, 0, M) dp[n][i] = i;
  rrep(i, n - 1, 0) {
    rep(j, 0, M) {
      int nj;
      if (j <= p[i]) {
        nj = j + a[i];
      } else {
        nj = max(0, j - b[i]);
      }
      dp[i][j] = dp[i + 1][nj];
    }
  }
  vector<int> bs(n + 1);
  rep(i, 0, n) bs[i + 1] = bs[i] + b[i];

  int Q;
  cin >> Q;
  while (Q--) {
    int x;
    cin >> x;
    int ans = 0;
    if (x >= M) {
      int i = upper_bound(begin(bs), begin(bs) + n, x - M) - begin(bs);
      x -= bs[i];
      if (i < n) {
        ans = dp[i][x];
      } else {
        ans = x;
      }
    } else {
      ans = dp[0][x];
    }
    cout << ans << "\n";
  }
  return 0;
}
