#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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

ll modpow(ll a, ll b, ll mod = 4) {
  ll res = 1;
  for (a %= mod; b; a = a * a % mod, b >>= 1) {
    if (b & 1) res = res * a % mod;
  }
  return res;
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  b = 4 + modpow(b, c, 4);
  ll ans = modpow(a, b, 10);
  cout << ans << endl;
  return 0;
}
