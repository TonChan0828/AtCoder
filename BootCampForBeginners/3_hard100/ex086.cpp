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
  vector<string> s(2);
  cin >> n >> s[0] >> s[1];
  ll r = pow(10, 9) + 7;
  int size = s[0].size();

  ll ans = 1;
  rep(i, 0, size) {
    if (i == 0) {
      if (s[0][i] == s[1][i]) {
        ans *= 3;
      } else {
        ans *= 6;
        ++i;
      }
    } else {
      if (s[0][i] == s[1][i]) {
        if (s[0][i - 1] == s[1][i - 1]) {
          ans *= 2;
        }
      } else {
        if (s[0][i - 1] == s[1][i - 1]) {
          ans *= 2;
        } else {
          ans *= 3;
        }
        ++i;
      }
    }
    ans %= r;
  }
  cout << ans << endl;
  return 0;
}
