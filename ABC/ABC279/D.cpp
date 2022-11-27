#include <bits/stdc++.h>
using namespace std;
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
  ll a, b;
  cin >> a >> b;
  ll l = 0, r = a / b;

  auto f = [&](ll n) -> double {
    return (double)a / sqrt(n + 1) + (double)b * n;
  };

  while (r - l > 2) {
    ll m1 = (l * 2 + r) / 3;
    ll m2 = (l + r * 2) / 3;
    if (f(m1) > f(m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }

  double ans = a;
  for (ll i = l; i <= r; ++i) {
    ans = min(ans, f(i));
  }
  printf("%.6lf\n", ans);
  return 0;
}
