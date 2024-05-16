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

int main() {
  const ll mod = 1e8;

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  sort(begin(a), end(a));
  vector<ll> sum(n, 0);
  rep(i, 0, n) {
    if (i) sum[i] = sum[i - 1];
    sum[i] += a[i];
  }

  ll ans = 0;
  rep(i, 0, n - 1) {
    auto itr = lower_bound(begin(a) + i + 1, end(a), mod - a[i]);
    int dist = itr - (begin(a) + i);
    int pos = i + dist;
    // cout << " " << pos << endl;
    if (i + 1 != pos) ans += (sum[pos - 1] - sum[i]) + a[i] * (ll(pos - i - 1));
    // cout << ans << endl;
    if (pos < n)
      ans += ((sum[n - 1] - sum[pos - 1]) + (a[i] * (ll)(n - pos))) -
             (ll)1e8 * (ll)(n - pos);
    // cout << ans << endl;
  }

  cout << ans << endl;
  return 0;
}
