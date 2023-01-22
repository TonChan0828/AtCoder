#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];
  vector<vector<bool>> dp(n + 1, vector<bool>(20001, false));
  dp[0][0] = true;
  rep(i, 0, n) {
    rep(j, 0, 10001) {
      if (dp[i][j]) {
        rep(k, 0, b[i] + 1) { dp[i + 1][j + a[i] * k] = true; }
      }
    }
  }
  if (dp[n][x]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
