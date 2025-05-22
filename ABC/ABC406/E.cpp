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

void solve() {
  ll n, k;
  cin >> n >> k;
  n++;

  const int M = 60;
  mint dp[M + 1][2][2][M + 1];
  rep(i, 0, M + 1) rep(j, 0, 2) rep(s, 0, 2) rep(p, 0, k + 1) dp[i][j][s][p] =
      0;
  dp[M][0][0][0] = 1;
  rrep(i, M - 1, 0) {
    rep(j, 0, 2) rep(s, 0, 2) rep(p, 0, k + 1) {
      mint now = dp[i + 1][j][s][p];
      if (now == 0) continue;

      rep(a, 0, 2) {
        int ns = s, np = p + a;
        if (s == 0) {
          if (a < (n >> i & 1)) ns = 1;
          if (a > (n >> i & 1)) continue;
        }

        if (np > k) continue;

        dp[i][j][ns][np] += now;
        if (j == 0 && a) dp[i][1][ns][np] += now * (1LL << i);
      }
    }
  }
  mint ans = dp[0][1][1][k];
  cout << ans.val() << "\n";
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    solve();
  }
  return 0;
}
