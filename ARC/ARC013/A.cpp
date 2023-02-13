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
  vector<int> d(3), t(3);
  rep(i, 0, 3) cin >> d[i];
  rep(i, 0, 3) cin >> t[i];

  auto f = [&]() -> int {
    int tmp = 1;
    rep(i, 0, 3) { tmp *= d[i] / t[i]; }
    return tmp;
  };

  int ans = 0;
  ans = max(ans, f());
  swap(t[0], t[1]);
  ans = max(ans, f());
  swap(t[0], t[2]);
  ans = max(ans, f());
  swap(t[0], t[1]);
  ans = max(ans, f());
  swap(t[0], t[2]);
  ans = max(ans, f());
  swap(t[0], t[1]);
  ans = max(ans, f());
  cout << ans << endl;
  return 0;
}
