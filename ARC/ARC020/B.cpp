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
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  vector<vector<int>> p(2, vector<int>(11));
  rep(i, 0, n) {
    cin >> a[i];
    ++p[i % 2][a[i]];
  }

  int ans = INT_MAX;

  rep(i, 1, 11) {
    rep(j, 1, 11) {
      if (i == j) continue;
      int tmp = (n - p[0][i] - p[1][j]) * c;
      ans = min(ans, tmp);
    }
  }

  cout << ans << endl;
  return 0;
}
