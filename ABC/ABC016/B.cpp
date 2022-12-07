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
  vector<string> x(n);
  rep(i, 0, n) cin >> x[i];
  int cnt = 0;
  rep(i, 0, n) {
    rep(j, 0, 9) {
      if (x[i][j] == 'x') ++cnt;
      if (x[i][j] == 'o') {
        if (i == 0) {
          ++cnt;
        } else if (x[i - 1][j] != 'o') {
          ++cnt;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
