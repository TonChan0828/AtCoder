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
  ll n, q;
  cin >> n >> q;
  vector<string> p(n);
  rep(i, 0, n) cin >> p[i];
  vector s(n + 1, vector<ll>(n + 1, 0));
  rep(i, 0, n) {
    rep(j, 0, n) {
      if (p[i][j] == 'B') s[i + 1][j + 1]++;
    }
  }

  rep(i, 0, n) {
    rep(j, 0, n) { s[i + 1][j + 1] += s[i + 1][j]; }
  }
  rep(i, 0, n) {
    rep(j, 0, n) { s[i + 1][j + 1] += s[i][j + 1]; }
  }

  auto f = [&](ll c, ll d) {
    ll res = s[c % n][d % n];
    res += s[n][n] * (c / n) * (d / n);
    res += s[n][d % n] * (c / n);
    res += s[c % n][n] * (d / n);
    return res;
  };

  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ++c, ++d;
    ll cnt = f(c, d) - f(c, b) - f(a, d) + f(a, b);

    printf("%lld\n", cnt);
  }
  return 0;
}
