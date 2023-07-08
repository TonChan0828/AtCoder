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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  int l = a[0], r = a[1];
  sort(a.begin() + 2, a.end());
  // rep(i, 0, n) printf("%d ", a[i]);
  // cout << "\n";
  int ans = INT_MAX;
  for (int i = 2; i < n - m + 1; ++i) {
    int lp = max(0, l - a[i]);
    int rp = max(0, a[i + m - 1] - r);
    // cout << lp + rp << endl;
    ans = min(ans, lp + rp);
  }
  cout << ans << endl;

  return 0;
}
