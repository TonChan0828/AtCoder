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
  ll n;
  cin >> n;

  ll ans = 0;
  for (ll a = 2; a <= n; a *= 2) {
    ll tar = n / a;

    ll l = 1, r = 1e9;
    while (l + 1 < r) {
      ll m = (l + r) / 2LL;
      if (m * m <= tar) {
        l = m;
      } else {
        r = m;
      }
      // cout << l << " " << r << endl;
    }
    ll m = (l + r) / 2LL;
    ans += m / 2;
    if (m % 2) ++ans;
  }

  cout << ans << endl;
  return 0;
}
