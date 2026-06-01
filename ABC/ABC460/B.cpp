#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<ll> x(2), y(2), r(2);
    rep(i, 0, 2) cin >> x[i] >> y[i] >> r[i];

    ll xx = x[0] - x[1], yy = y[0] - y[1], rp = r[0] + r[1], rm = r[0] - r[1];
    ll xy = xx * xx + yy * yy;
    if (xy <= rp * rp && xy >= rm * rm) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
