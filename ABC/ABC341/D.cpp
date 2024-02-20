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
  ll n, m, k;
  cin >> n >> m >> k;
  ll nm = lcm(n, m);
  ll l = 0, r = __LONG_LONG_MAX__;
  while (l <= r) {
    ll mid = (l + r) / 2LL;
    ll cnt = mid / n + mid / m - mid / nm * 2LL;
    if (mid % nm != 0 && (mid % n == 0LL || mid % m == 0LL)) {
      if (cnt == k) {
        cout << mid << endl;
        return 0;
      }
    }
    if (cnt >= k) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << (l + r) / 2;
  return 0;
}
