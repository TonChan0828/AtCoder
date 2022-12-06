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
  int t, n, m;
  cin >> t >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  cin >> m;
  vector<int> b(m);
  rep(i, 0, m) cin >> b[i];

  int pos = -1;
  rep(i, 0, m) {
    while (pos < m) {
      // cout << pos << endl;
      ++pos;
      if (b[i] - t <= a[pos] && b[i] >= a[pos]) {
        break;
      } else if (b[i] < a[pos]) {
        cout << "no" << endl;
        return 0;
      }
    }
    if (pos >= n) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}
