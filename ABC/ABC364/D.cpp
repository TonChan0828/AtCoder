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
  vector<ll> a(n), b(q);
  vector<int> k(q);
  rep(i, 0, n) cin >> a[i];
  sort(begin(a), end(a));
  rep(i, 0, q) {
    cin >> b[i] >> k[i];
    ll l = -1, r = 1e9 + 1;
    ll ans = 0;
    while (l + 1 < r) {
      ll m = (l + r) / 2;
      // cout << l << " " << r << endl;
      auto lLow = lower_bound(begin(a), end(a), b[i] - m);
      auto rLow = upper_bound(begin(a), end(a), b[i] + m);
      int dist = rLow - lLow;

      if (dist >= k[i]) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << r << endl;
  }

  return 0;
}
