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

const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), z(n);
  rep(i, 0, n) cin >> x[i] >> y[i] >> z[i];
  int n2 = 1 << n;
  vector<vector<int>> dp(n2, vector<int>(n, INF));

  vector<vector<int>> dist(n, vector<int>(n));
  rep(i, 0, n) {
    rep(j, 0, n) {
      int now = abs(x[i] - x[j]);
      now += abs(y[i] - y[j]);
      now += max(0, z[j] - z[i]);
      dist[i][j] = now;
    }
  }

  rep(i, 1, n) { dp[1 << i][i] = dist[0][i]; }
  rep(i, 0, n2) {
    rep(j, 0, n) {
      if (~i >> j & 1) continue;
      rep(k, 0, n) {
        if (i >> k & 1) continue;
        chmin(dp[i | 1 << k][k], dp[i][j] + dist[j][k]);
      }
    }
  }
  // rep(i, 0, n2) {
  //   rep(j, 0, n) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  cout << dp[n2 - 1][0] << endl;
  return 0;
}
