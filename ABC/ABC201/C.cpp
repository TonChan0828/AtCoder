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
  int ok = 0;
  int ng = 0;
  rep(i, 0, 10) {
    if (s[i] == 'o') ++ok;
    if (s[i] == 'x') ++ng;
  }
  // if (ok > 4) {
  //   cout << 0 << endl;
  //   return 0;
  // }
  if (ng == 10) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  rep(i, 0, 10000) {
    int tmp = i;
    map<int, int> m;
    rep(j, 0, 4) {
      int d = tmp % 10;
      if (s[d] == 'x') {
        m.clear();
        break;
      } else if (s[d] == 'o') {
        m[d]++;
      }
      tmp /= 10;
    }
    if (m.size() == ok) {
      ++ans;
      // cout << i << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
