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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

const ll INF = 10010010010;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> ss(n);
  rep(i, 0, n) ss[i] = s[i] - '0';
  vector<ll> c(n);
  rep(i, 0, n) cin >> c[i];

  vector dp(n, vector(2, vector<ll>(2, INF)));
  rep(i, 0, 2) {
    if (ss[0] == i) {
      dp[0][0][i] = 0;
    } else {
      dp[0][0][i] = c[0];
    }
  }

  rep(i, 1, n) {
    rep(j, 0, 2) {
      // 文字が一致しない時
      dp[i][0][j] = dp[i - 1][0][(j + 1) % 2] + ((ss[i] == j) ? 0 : c[i]);

      // 文字が一致する時
      dp[i][1][j] = min(dp[i - 1][1][(j + 1) % 2] + ((ss[i] == j) ? 0 : c[i]),
                        dp[i - 1][0][j] + ((ss[i] == j) ? 0 : c[i]));
    }
  }
  cout << min(dp[n - 1][1][0], dp[n - 1][1][1]) << endl;
  return 0;
}
