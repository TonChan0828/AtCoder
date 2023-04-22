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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  ll ans = ((ll)2 << 30);

  rep(i, 1, (1 << n)) {
    ll xt = 0;
    ll tmp = 0;
    rep(j, 0, n) {
      tmp |= a[j];
      if (i & (1 << j)) {
        xt ^= tmp;
        tmp = 0;
      }
    }
    xt ^= tmp;
    ans = min(ans, xt);
  }

  cout << ans << endl;
  return 0;
}
