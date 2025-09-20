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
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector s(3, vector<ll>(n + 1));
  rep(k, 0, 3) {
    rep(i, 0, n) {
      ll x = a[i];
      rep(j, 0, k) x *= i;
      s[k][i + 1] = s[k][i] + x;
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    ll ans = 0;
    ans -= s[2][r] - s[2][l];
    ans += (s[1][r] - s[1][l]) * (l - 1 + r);
    ans -= (s[0][r] - s[0][l]) * (ll(l - 1) * r);
    cout << ans << endl;
  }
  return 0;
}
