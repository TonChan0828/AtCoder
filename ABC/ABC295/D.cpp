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
  int sz = s.size();

  vector<vector<int>> t(sz + 1, vector<int>(10, 0));
  rep(i, 0, sz) {
    t[i][s[i] - '0'] = (t[i][s[i] - '0'] + 1) % 2;
    if (i == sz - 1) break;
    rep(j, 0, 10) t[i + 1][j] = t[i][j];
  }

  vector<ll> cnt(1024, 0);
  ++cnt[0];
  rep(i, 0, sz) {
    int tmp = 0;
    rep(j, 0, 10) { tmp += (t[i][j] << j); }
    ++cnt[tmp];
  }
  ll ans = 0;
  rep(i, 0, 1024) { ans += (cnt[i] * (cnt[i] - 1)) / 2; }

  cout << ans << endl;

  return 0;
}
