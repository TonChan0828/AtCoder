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
  string s;
  cin >> s;
  int sz = s.size();
  ll ans = 0;
  rep(i, 0, sz) {
    if (s[i] == '2' && s[i + 1] == '5') {
      ll cnt = 1;
      int t = i + 2;
      while (t < sz && s[t] == '2' && s[t + 1] == '5') {
        ++cnt;
        t += 2;
      }
      ans += cnt * (cnt + 1) / 2;
      // cout << cnt << endl;
      i = --t;
    }
  }

  cout << ans << endl;
  return 0;
}
