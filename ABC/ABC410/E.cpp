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
  int n, h, m;
  cin >> n >> h >> m;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  vector<vector<int>> dp(n + 1, vector<int>(h + 1, -1));
  dp[0][h] = m;
  rep(i, 0, n) {
    rrep(j, h, 0) {
      if (dp[i][j] == -1) continue;
      if (j - a[i] >= 0) {
        chmax(dp[i + 1][j - a[i]], dp[i][j]);
      }
      if (dp[i][j] - b[i] >= 0) {
        chmax(dp[i + 1][j], dp[i][j] - b[i]);
      }
    }
  }

  int ans = 0;
  rep(i, 1, n + 1) {
    rep(j, 0, h + 1) {
      if (dp[i][j] != -1) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
