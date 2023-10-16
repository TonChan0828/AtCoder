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
struct Edge {
  int to, b, c;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n);
  rep(i, 0, m) {
    int u, v, b, c;
    cin >> u >> v >> b >> c;
    --u, --v;
    g[u].push_back((Edge){v, b, c});
  }

  auto f = [&](double x) {
    const double INF = 1e18;
    vector<double> dp(n, -INF);
    dp[0] = 0;
    rep(i, 0, n) {
      for (auto e : g[i]) {
        chmax(dp[e.to], dp[i] + e.b - e.c * x);
      }
    }
    return dp[n - 1] >= 0;
  };

  double ac = 0, wa = 1e4;
  rep(i, 0, 50) {
    double wj = (ac + wa) / 2;
    if (f(wj))
      ac = wj;
    else
      wa = wj;
  }

  printf("%.10f\n", ac);

  return 0;
}
