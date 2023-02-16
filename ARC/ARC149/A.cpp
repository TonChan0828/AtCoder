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
  int n, m;
  cin >> n >> m;
  pair<int, int> ans = {0, 0};  // first:digit, second:number
  rep(i, 1, 10) {
    int tmp = i;
    rep(j, 0, n) {
      tmp %= m;
      if (tmp == 0) {
        if (ans.first < j) {
          ans = {j, i};
          // printf("%d %d\n", j + 1, i);

        } else if (ans.first == j) {
          if (ans.second <= i) {
            ans = {j, i};
            // printf("%d %d\n", j + 1, i);
          }
        }
      }
      tmp *= 10;
      tmp += i;
      // cout << tmp << endl;
    }
  }
  if (ans.second == 0) {
    cout << -1 << endl;
  } else {
    rep(i, 0, ans.first + 1) { cout << ans.second; }
    cout << endl;
  }
  return 0;
}
