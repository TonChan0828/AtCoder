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
  cin >> n;
  vector a(n, vector<int>(n));
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, n) {
    rep(j, 0, n) { a[i][j] = s[i][j] - '0'; }
  }

  vector b = a;
  rrep(i, n - 1, 1) { b[0][i] = a[0][i - 1]; }
  rep(i, 0, n - 1) { b[n - 1][i] = a[n - 1][i + 1]; }
  rep(i, 0, n - 1) { b[i][0] = a[i + 1][0]; }
  rrep(i, n - 1, 1) { b[i][n - 1] = a[i - 1][n - 1]; }

  rep(i, 0, n) {
    rep(j, 0, n) { printf("%d", b[i][j]); }
    cout << "\n";
  }

  return 0;
}
