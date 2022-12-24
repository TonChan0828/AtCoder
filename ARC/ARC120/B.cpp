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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  ll mod = 998244353;
  ll ans = 1;

  rep(k, 0, h + w - 1) {
    int r = 0, b = 0;
    rep(i, max(0, k - w + 1), min(k + 1, h)) {
      int j = k - i;
      if (s[i][j] == 'R') ++r;
      if (s[i][j] == 'B') ++b;
    }
    // cout << r << " " << b << endl;
    if (r && b) {
      ans = 0;
      break;
    } else if (!r && !b) {
      ans = (ans * 2) % mod;
    }
    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
