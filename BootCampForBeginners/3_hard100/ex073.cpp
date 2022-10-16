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
  cin >> n;
  int ans = n;
  rep(i, 0, n + 1) {
    int c = 0;
    int t = i;
    while (t > 0) {
      c += t % 6;
      t /= 6;
    }
    t = n - i;
    while (t > 0) {
      c += t % 9;
      t /= 9;
    }
    if (ans > c) ans = c;
  }
  cout << ans << endl;
  return 0;
}
