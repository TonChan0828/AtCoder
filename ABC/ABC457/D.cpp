#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}
using P = pair<ll, ll>;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  auto check = [&](ll x) -> bool {
    ll cost = 0;
    rep(i, 0, n) {
      if (a[i] >= x) continue;
      ll diff = x - a[i];
      ll idx = i + 1;
      cost += (diff + idx - 1) / idx;
      if (cost > k) return false;
    }
    return cost <= k;
  };

  ll lo = *min_element(begin(a), end(a));
  ll hi = a[0] + k;
  while (lo < hi) {
    ll mid = (lo + hi + 1) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << endl;
}
