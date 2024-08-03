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

using P = pair<int, int>;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  const int INF = 1001001001;
  vector dp(x + 1, vector<int>(n + 1, INF));
  dp[0][0] = 0;

  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    vector old(x + 1, vector<int>(n + 1, INF));
    swap(dp, old);
    rep(j, 0, x + 1) {
      rep(k, 0, n) {
        int now = old[j][k];
        if (now == INF) continue;
        chmin(dp[j][k], now);
        if (j + a <= x) chmin(dp[j + a][k + 1], now + b);
      }
    }
  }

  int ans = 0;
  rep(j, 0, x + 1) {
    rep(k, 0, n + 1) {
      if (dp[j][k] <= y) {
        ans = max(ans, k);
      }
    }
  }

  if (ans < n) ++ans;
  cout << ans << endl;
  return 0;
}
