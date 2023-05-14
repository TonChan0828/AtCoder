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
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  ll n;
  cin >> n;
  int sz = s.size();
  ll ans = 0;
  rep(i, 0, sz) {
    if (s[i] == '1') {
      ans |= (1LL << i);
    }
  }

  if (ans > n) {
    cout << -1 << endl;
    return 0;
  }

  rrep(i, sz - 1, 0) {
    if (s[i] == '?') {
      ll tmp = 1LL << i;
      if ((ans | tmp) <= n) ans |= tmp;
    }
  }

  cout << ans << endl;

  return 0;
}
