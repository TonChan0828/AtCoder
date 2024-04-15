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

using P = pair<ll, ll>;

int main() {
  ll l, r;
  cin >> l >> r;
  vector<P> ans;

  auto exp = [&](ll x) -> ll {
    ll res = 1LL;
    while (x % 2 == 0) {
      res *= 2LL;
      x /= 2LL;
    }
    return res;
  };

  while (l < r) {
    ll ex = exp(r);
    ll tmp = r / ex;
    tmp--;
    // cout << ex << " " << tmp << endl;
    while (ex * tmp < l) {
      ex /= 2LL;
      tmp = r / max(1LL, ex);
      --tmp;
    }
    ll le = ex * tmp;
    ans.push_back({le, r});
    r = le;
  }

  reverse(begin(ans), end(ans));
  cout << ans.size() << endl;
  ;
  for (P res : ans) {
    printf("%lld %lld\n", res.first, res.second);
  }
  return 0;
}
