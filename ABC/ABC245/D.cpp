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

  vector<int> a(n + 1), b(m + 1, 0), c(n + m + 1);
  rep(i, 0, n + 1) cin >> a[i];
  rep(i, 0, n + m + 1) cin >> c[i];

  rrep(i, m, 0) {
    b[i] = c[i + n] / a[n];
    rep(j, 0, n + 1) c[i + j] -= b[i] * a[j];
  }
  rep(i, 0, m + 1) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
  return 0;
}
