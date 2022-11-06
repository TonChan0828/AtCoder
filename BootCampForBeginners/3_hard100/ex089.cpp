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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  ll r = 1000000007;
  vector<int> c(3, 0);
  ll ans = 1;
  rep(i, 0, n) {
    ll cnt = 0;
    rep(j, 0, 3) {
      if (c[j] == a[i]) {
        ++cnt;
        if (cnt == 1) {
          ++c[j];
        }
      }
    }
    // cout << cnt << endl;
    ans *= cnt;
    ans %= r;
  }
  cout << ans << endl;
  return 0;
}