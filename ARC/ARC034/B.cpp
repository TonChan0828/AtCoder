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

  vector<ll> ans;

  auto f = [&](ll x) {
    ll tmp = x;
    ll res = x;
    while (tmp > 0) {
      res += tmp % 10;
      tmp /= 10;
    }
    if (res == n) ans.push_back(x);
  };

  rep(i, 0, 180) {
    ll tar = max(0LL, n - (ll)i);
    f(tar);
  }
  reverse(begin(ans), end(ans));
  cout << ans.size() << "\n";
  for (ll x : ans) cout << x << "\n";
  return 0;
}
