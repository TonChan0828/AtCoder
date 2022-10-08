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
  ll n;
  cin >> n;
  vector<ll> a;
  while (n > 0) {
    a.push_back(n % 10);
    n /= 10;
  }
  sort(a.begin(), a.end());
  int size = a.size();
  ll ans = 0;
  rep(i, 0, 1 << (size)) {
    ll x = 1, y = 1;
    ll tmpx = 0, tmpy = 0;
    rep(j, 0, size) {
      if (i & (1 << j)) {
        // if (x == 1 && a[j] == 0) break;
        tmpx += a[j] * x;
        x *= 10;
      } else {
        // if (y == 1 && a[j] == 0) break;
        tmpy += a[j] * y;
        y *= 10;
      }
    }
    ll tmp = tmpx * tmpy;
    // cout << tmpx << " " << tmpy << endl;
    chmax(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
