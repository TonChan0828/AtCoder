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

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<vector<int>> as(11);
  rep(i, 0, n) as[to_string(a[i]).size()].push_back(a[i] % m);

  ll ans = 0;
  ll ten = 1;
  rep(b, 0, 11) {
    auto& na = as[b];
    sort(begin(na), end(na));

    auto count = [&](int r) {
      return upper_bound(begin(na), end(na), r) -
             lower_bound(begin(na), end(na), r);
    };

    rep(i, 0, n) {
      ll r = (m - ten * a[i] % m) % m;
      ans += count(r);
    }
    ten *= 10;
    ten %= m;
  }

  cout << ans << endl;
  return 0;
}
