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
  int n, q;
  cin >> n >> q;
  vector<double> x(n), r(n), h(n);
  rep(i, 0, n) cin >> x[i] >> r[i] >> h[i];
  const double pi = acos(-1);

  auto f = [&](int t) -> double {
    double res = 0;
    rep(i, 0, n) {
      if (x[i] + h[i] <= t) continue;
      double l = (t <= x[i] ? h[i] : x[i] + h[i] - t);
      res += pi / 3 * r[i] * r[i] / h[i] / h[i] * l * l * l;
    }
    return res;
  };

  while (q--) {
    int a, b;
    cin >> a >> b;
    printf("%.10f\n", f(a) - f(b));
  }

  return 0;
}
