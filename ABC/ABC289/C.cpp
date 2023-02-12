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
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  rep(i, 0, m) {
    int c;
    cin >> c;
    int tmp = 0;
    rep(j, 0, c) {
      int a;
      cin >> a;
      tmp |= 1 << (a - 1);
    }
    v[i] = tmp;
    // cout << v[i] << endl;
  }
  int target = 0;
  rep(i, 0, n) { target |= 1 << i; }
  // cout << target << endl;
  ll ans = 0;
  rep(i, 1, 1 << m) {
    int tmp = 0;
    rep(j, 0, m) {
      if (i & (1 << j)) {
        // cout << tmp << endl;
        tmp |= v[j];
      }
    }
    // cout << tmp << endl;
    if (target == tmp) ++ans;
  }
  cout << ans << endl;
  return 0;
}
