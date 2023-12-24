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
  ll a, m, l, r;
  cin >> a >> m >> l >> r;

  ll ans = 0;

  if (a < l) {
    ll x = a + ((l - a) / m) * m;
    if (x < l) x += m;
    if (x <= r) ans = (r - x) / m + 1;
  } else if (a == l || a == r) {
    ans = (r - l) / m + 1;
  } else if (l < a && a < r) {
    ans = 1;
    ans += (r - a) / m;
    ans += (a - l) / m;
  } else {
    ll x = a - ((a - r) / m) * m;
    if (x > r) x -= m;
    if (x >= l) ans = (x - l) / m + 1;
  }

  cout << ans << endl;
  return 0;
}
