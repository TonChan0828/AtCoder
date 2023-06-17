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

using mint = modint998244353;

int main() {
  ll n, m;
  cin >> n >> m;
  if (n > 60) {
    cout << 0 << "\n";
    return 0;
  }

  vector<mint> ta(62);
  rep(i, 0, 62) {
    ta[i] = max(0ll, min(m, (1ll << (i + 1)) - 1) - (1ll << i) + 1);
    // printf("%d ", ta[i]);
  }
  // cout << endl;

  vector<vector<mint>> dp(n + 1, vector<mint>(63, 0));
  dp[0][0] = 1;
  rep(i, 0, n) {
    rep(j, 0, 62) {
      rep(k, 0, j) { dp[i + 1][j] += dp[i][k] * ta[j - 1]; }
    }
  }

  mint ans = 0;
  rep(i, 0, 62) ans += dp[n][i];
  cout << ans.val() << endl;

  return 0;
}
