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
  vector<int> a(n + 1);
  vector<int> cnt(2 * n + 2, 0);
  rep(i, 1, n + 1) cin >> a[i];
  cout << 0 << endl;
  rep(i, 1, n + 1) {
    int pa = cnt[a[i]];
    // cout << pa << endl;
    rep(j, 0, 2) {
      cnt[2 * i + j] = pa + 1;
      cout << cnt[2 * i + j] << endl;
    }
  }
  return 0;
}
