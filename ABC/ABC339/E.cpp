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
int op(int a, int b) { return max(a, b); }
int e() { return 0; }

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  const int M = 500005;
  segtree<int, op, e> dp(M);

  rep(i, 0, n) {
    int l = max(0, a[i] - d), r = min(M, a[i] + d + 1);
    int now = dp.prod(l, r) + 1;
    dp.set(a[i], now);
  }

  int ans = dp.prod(0, M);
  cout << ans << endl;
  return 0;
}
