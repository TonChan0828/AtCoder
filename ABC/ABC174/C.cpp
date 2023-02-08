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

int main() {
  ll k;
  cin >> k;
  ll ans = 0;
  ll tar = 0;
  set<ll> s;
  do {
    tar *= 10;
    tar += 7;
    tar %= k;
    if (s.count(tar)) {
      cout << -1 << endl;
      return 0;
    }
    s.insert(tar);
    ++ans;
  } while (tar != 0);

  cout << ans << endl;
  return 0;
}
