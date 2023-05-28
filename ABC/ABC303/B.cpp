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
  vector<vector<int>> a(m, vector<int>(n));
  rep(i, 0, m) {
    rep(j, 0, n) { cin >> a[i][j]; }
  }

  set<pair<int, int>> set;
  rep(i, 0, m) {
    rep(j, 0, n - 1) {
      set.insert({a[i][j], a[i][j + 1]});
      set.insert({a[i][j + 1], a[i][j]});
    }
  }
  cout << (n * (n - 1) / 2) - (set.size() / 2) << endl;
  return 0;
}
