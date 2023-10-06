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

const ll INF = 100100100100;

int main() {
  int n, k, p;
  cin >> n >> k >> p;
  vector<ll> c(n);
  vector a(n, vector<int>(k));
  rep(i, 0, n) {
    cin >> c[i];
    rep(j, 0, k) cin >> a[i][j];
  }
  int score = 0;
  rep(i, 0, k) {
    score *= 10;
    score += p;
  }
  vector dp(n + 1, vector<ll>(score + 1, INF));
  dp[0][0] = 0;
  rep(i, 0, n) {
    rep(j, 0, score + 1) {
      if (dp[i][j] == INF) continue;
      chmin(dp[i + 1][j], dp[i][j]);
      // cout << i << " " << j << endl;
      int now = j;
      int d = 1;
      int tar = 0;
      rep(kk, 0, k) {
        int x = now % 10;
        tar += min(p, x + a[i][kk]) * d;
        d *= 10;
        now /= 10;
      }
      chmin(dp[i + 1][tar], dp[i][j] + c[i]);
      // cout << tar << " " << dp[i + 1][tar] << endl;
    }
  }

  // rep(i, 0, n + 1) {
  //   rep(j, 0, score + 1) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }

  if (dp[n][score] == INF) {
    cout << -1 << endl;
  } else {
    cout << dp[n][score] << endl;
  }
  return 0;
}
