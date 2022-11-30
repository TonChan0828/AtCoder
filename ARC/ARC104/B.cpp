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
  string s;
  cin >> n >> s;
  vector<int> a(n + 1, 0), t(n + 1, 0), c(n + 1, 0), g(n + 1, 0);

  rep(i, 1, n + 1) {
    a[i] = a[i - 1];
    t[i] = t[i - 1];
    c[i] = c[i - 1];
    g[i] = g[i - 1];
    if (s[i - 1] == 'A') {
      ++a[i];
    } else if (s[i - 1] == 'T') {
      ++t[i];
    } else if (s[i - 1] == 'C') {
      ++c[i];
    } else {
      ++g[i];
    }
  }
  // rep(i, 0, n + 1) { cout << a[i] << t[i] << c[i] << g[i] << endl; }
  int cnt = 0;
  rep(i, 0, n) {
    rep(j, i + 1, n + 1) {
      int da = a[j] - a[i];
      int dt = t[j] - t[i];
      int dc = c[j] - c[i];
      int dg = g[j] - g[i];
      if (da == dt && dc == dg) {
        ++cnt;
        // cout << i << " " << j << endl;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
