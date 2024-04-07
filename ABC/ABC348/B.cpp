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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  rep(i, 0, n) {
    ll ma = 0;
    int ans = i;
    rep(j, 0, n) {
      if (i == j) continue;
      ll tmp = abs(x[i] - x[j]) * abs(x[i] - x[j]) +
               abs(y[i] - y[j]) * abs(y[i] - y[j]);
      if (tmp > ma) {
        ma = tmp;
        ans = j;
      }
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
