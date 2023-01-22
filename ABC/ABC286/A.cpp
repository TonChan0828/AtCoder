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
  int n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  --p, --q, --r, --s;
  int cntp = 0, cntr = 0;
  rep(i, 0, n) {
    if (i != 0) {
      cout << " ";
    }
    if (i >= p && i <= q) {
      cout << a[r + cntr];
      ++cntr;
    } else if (i >= r && i <= s) {
      cout << a[p + cntp];
      ++cntp;
    } else {
      cout << a[i];
    }
  }
  return 0;
}
