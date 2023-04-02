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
  ll n, m;
  cin >> n >> m;
  ll ans = LLONG_MAX;
  rep(i, 1, min(n + 1, (ll)1000001)) {
    ll tmp = 0;
    if (m % i == 0) {
      tmp = m / i;
    } else {
      tmp = m / i + 1;
    }
    if (tmp <= n) {
      ans = min(ans, tmp * i);
    }
  }
  if (ans == LLONG_MAX) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
