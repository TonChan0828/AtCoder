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

void solve() {
  ll k;
  cin >> k;
  ll x = 9;
  int sz = 1;
  while (x < k) {
    k -= x;
    sz++;
    x *= 9;
  }

  int l = 0;
  ll res = 0;
  while (sz--) {
    res *= 10;
    x /= 9;
    rep(i, 0, 10) {
      if (i == l) continue;
      if (k <= x) {
        cout << i << " " << k << " " << x << endl;
        l = i;
        res += i;
        break;
      }
      k -= x;
    }
  }

  printf("%lld\n", res);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
