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
  ll t;
  cin >> n >> t;
  string s;
  cin >> s;
  vector<ll> x(n);
  rep(i, 0, n) cin >> x[i];
  vector<ll> l, r;
  rep(i, 0, n) {
    if (s[i] == '0') {
      l.push_back(x[i]);

    } else {
      r.push_back(x[i]);
    }
  }
  sort(begin(l), end(l));
  sort(begin(r), end(r));

  ll ans = 0;
  for (auto a : r) {
    auto itrL = lower_bound(begin(l), end(l), a);
    auto itrR = upper_bound(begin(l), end(l), a + 2LL * t);
    ll d = itrR - itrL;
    // cout << a << " " << d << endl;
    ans += d;
  }
  cout << ans << endl;
  return 0;
}
