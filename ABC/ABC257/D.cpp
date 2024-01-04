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
  int n;
  cin >> n;
  vector<ll> x(n), y(n), p(n);
  rep(i, 0, n) cin >> x[i] >> y[i] >> p[i];
  vector s(n, vector<ll>(n));
  rep(i, 0, n) {
    rep(j, 0, n) s[i][j] =
        (llabs(x[i] - x[j]) + llabs(y[i] - y[j]) + p[i] - 1) / p[i];
  }
  rep(k, 0, n) {
    rep(i, 0, n) {
      rep(j, 0, n) { s[i][j] = min(s[i][j], max(s[i][k], s[k][j])); }
    }
  }

  ll ans = 101010101010;
  rep(i, 0, n) {
    ll res = 0;
    rep(j, 0, n) { res = max(res, s[i][j]); }
    ans = min(ans, res);
  }
  cout << ans << endl;
  return 0;
}
