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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  vector dp(n, vector(n, vector<mint>(n + 1, 0)));
  rep(i, 0, n) {
    rep(j, 0, i) dp[i][j][2] += 1;
    rep(j, 0, i) {
      rep(k, 0, n) {
        mint now = dp[i][j][k];
        if (now == 0) continue;
        rep(x, i + 1, n) {
          if (a[x] - a[i] == a[i] - a[j]) {
            dp[x][i][k + 1] += now;
          }
        }
      }
    }
  }

  vector<mint> ans(n + 1);
  ans[1] = n;
  rep(k, 2, n + 1) {
    rep(i, 0, n) { rep(j, 0, i) ans[k] += dp[i][j][k]; }
  }

  rep(i, 1, n + 1) { cout << ans[i].val() << " "; }
  cout << endl;
  return 0;
}
