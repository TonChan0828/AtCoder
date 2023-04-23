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
  int n;
  string s;
  cin >> n >> s;
  int ans = -1;
  int cnt = 0;
  rep(i, 0, n) {
    if (s[i] == 'o') ++cnt;
    if (s[i] == '-') {
      if (cnt > 0) ans = max(ans, cnt);
      cnt = 0;
    }
  }
  cnt = 0;
  rrep(i, n - 1, 0) {
    if (s[i] == 'o') ++cnt;
    if (s[i] == '-') {
      if (cnt > 0) ans = max(ans, cnt);
      cnt = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
