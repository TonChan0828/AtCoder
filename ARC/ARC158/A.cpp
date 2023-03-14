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
  int t;
  cin >> t;
  while (t--) {
    vector<ll> x(3);
    rep(i, 0, 3) cin >> x[i];

    ll a = x[0] + x[1] + x[2];
    if (a % 3 != 0) {
      cout << -1 << endl;
      continue;
    }
    a /= 3;
    if (a % 2 != x[0] % 2 || x[0] % 2 != x[1] % 2 || x[1] % 2 != x[2] % 2) {
      cout << -1 << endl;
      continue;
    }

    ll d = abs(x[0] - a) + abs(x[1] - a) + abs(x[2] - a);
    cout << d / 4 << endl;
  }
  return 0;
}
