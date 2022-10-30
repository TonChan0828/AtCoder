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
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  ll r = 998244353;
  a %= r;
  b %= r;
  c %= r;
  d %= r;
  e %= r;
  f %= r;
  ll ta = 1, tb = 1;
  ta *= a;
  ta %= r;
  ta *= b;
  ta %= r;
  ta *= c;
  ta %= r;

  tb *= d;
  tb %= r;
  tb *= e;
  tb %= r;
  tb *= f;
  tb %= r;
  ll ans = ta - tb;
  ans %= r;
  if (ans < 0) {
    ans = r + ans;
    ans %= r;
  }
  cout << ans << endl;
  return 0;
}
