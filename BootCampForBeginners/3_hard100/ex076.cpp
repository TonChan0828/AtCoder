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
  string s;
  cin >> s;
  int sz = s.size();
  ll ans = 0;
  rep(i, 0, (1 << sz - 1)) {
    ll d = 1;
    rrep(j, sz - 1, 1) {
      ans += (ll)(s[j] - '0') * d;
      // cout << (int)(s[j] - '0') * d << endl;
      if (i & (1 << j - 1)) {
        d = 1;
      } else {
        d *= 10;
      }
    }
    ans += (ll)(s[0] - '0') * d;
  }
  cout << ans << endl;
  return 0;
}
