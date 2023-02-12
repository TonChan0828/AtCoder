#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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

  if (m == 0) {
    rep(i, 0, n) {
      if (i != 0) cout << " ";
      cout << i + 1;
    }
    cout << endl;
    return 0;
  }

  vector<int> a(m);
  rep(i, 0, m) cin >> a[i];
  int pos = 1;
  int tar = 0;
  while (pos <= n) {
    if (pos != a[tar] || m == 0) {
      cout << pos << " ";
      ++pos;
    } else {
      int end = pos;
      while (tar < m && a[tar] + 1 == a[tar + 1]) ++tar;
      rrep(i, a[tar] + 1, end) cout << i << " ";
      pos = a[tar] + 2;
      ++tar;
      // cout << pos << endl;
    }
  }
  cout << endl;
  return 0;
}
