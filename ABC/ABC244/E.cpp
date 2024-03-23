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

using mint = modint998244353;

int main() {
  int n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  --s, --t, --x;
  vector g(n, vector<int>());
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector dp(k + 1, vector(n, vector<mint>(2, 0)));
  dp[0][s][0] = 1;
  rep(i, 0, k) {
    rep(j, 0, n) {
      rep(l, 0, 2) {
        if (dp[i][j][l].val() > 0) {
          for (int nxt : g[j]) {
            if (nxt == x) {
              dp[i + 1][nxt][(l + 1) % 2] += dp[i][j][l];
            } else {
              dp[i + 1][nxt][l] += dp[i][j][l];
            }
          }
        }
      }
    }
  }

  cout << dp[k][t][0].val() << endl;
  return 0;
}
