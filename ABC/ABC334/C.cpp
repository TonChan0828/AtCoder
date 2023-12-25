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
  int n, k;
  cin >> n >> k;
  vector<ll> a(k);

  rep(i, 0, k) { cin >> a[i]; }
  vector<int> b(k + 1), c(k + 1);

  int ans = 0;
  if (k % 2) {
    ans = 10101010;
    rep(i, 0, k) {
      if (i == 0) continue;
      b[i] = b[i - 1];
      if (i % 2) b[i] += a[i] - a[i - 1];
    }
    rrep(i, k - 1, 0) {
      if (i == k - 1) continue;
      c[i] = c[i + 1];
      if (i % 2) c[i] += a[i + 1] - a[i];
    }

    rep(i, 0, k) chmin(ans, b[i] + c[i]);
  } else {
    rep(i, 0, k / 2) ans += a[i * 2 + 1] - a[i * 2];
  }

  cout << ans << endl;
  return 0;
}
