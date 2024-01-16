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
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<int> height(n, 0), rHeight(n, 0);
  height[0] = 1;
  rep(i, 1, n) { height[i] = min(height[i - 1] + 1, a[i]); }
  rHeight[n - 1] = 1;
  rrep(i, n - 2, 0) { rHeight[i] = min(rHeight[i + 1] + 1, a[i]); }
  // rep(i, 0, n) cout << height[i] << " ";
  // cout << endl;
  // rep(i, 0, n) cout << rHeight[i] << " ";
  // cout << endl;

  int ans = 0;
  rep(i, 0, n) { ans = max(ans, min(height[i], rHeight[i])); }
  cout << ans << endl;
  return 0;
}
