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
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  const int INF = 1001001001;
  vector g(n, vector<P>(n, P(INF, 0)));
  rep(i, 0, n) g[i][i] = P(0, 0);

  rep(i, 0, n) {
    string s;
    cin >> s;
    rep(j, 0, n) {
      if (s[j] == 'Y') g[i][j] = P(1, -a[j]);
    }
  }

  auto add = [&](P a, P b) {
    return P(a.first + b.first, a.second + b.second);
  };
  rep(k, 0, n) {
    rep(i, 0, n) {
      rep(j, 0, n) { g[i][j] = min(g[i][j], add(g[i][k], g[k][j])); }
    }
  }
  int q;
  cin >> q;
  rep(i, 0, q) {
    int s, t;
    cin >> s >> t;
    --s, --t;
    auto [dist, val] = g[s][t];
    if (dist == INF)
      cout << "Impossible" << endl;
    else
      printf("%d %lld\n", dist, a[s] - val);
  }

  return 0;
}
