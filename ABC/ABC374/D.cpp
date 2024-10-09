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
  double s, t;
  cin >> n >> s >> t;
  vector<double> a(n), b(n), c(n), d(n);
  rep(i, 0, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
  vector<double> l(n);
  rep(i, 0, n) {
    double tmp = abs(a[i] - c[i]) * abs(a[i] - c[i]) +
                 abs(b[i] - d[i]) * abs(b[i] - d[i]);
    l[i] = sqrt(tmp) / t;
  }

  vector<int> order(n);
  rep(i, 0, n) order[i] = i;
  double ans = 1001001001001;

  do {
    rep(i, 0, 1 << n) {
      double res = 0;
      int y = 0, x = 0;
      rep(j, 0, n) {
        if (i >> j & 1) {
          double tmp = abs(a[order[j]] - x) * abs(a[order[j]] - x) +
                       abs(b[order[j]] - y) * abs(b[order[j]] - y);
          res += sqrt(tmp) / s;
          x = c[order[j]], y = d[order[j]];
        } else {
          double tmp = abs(c[order[j]] - x) * abs(c[order[j]] - x) +
                       abs(d[order[j]] - y) * abs(d[order[j]] - y);
          res += sqrt(tmp) / s;
          x = a[order[j]], y = b[order[j]];
        }
        res += l[order[j]];
      }
      ans = min(ans, res);
    }
  } while (next_permutation(begin(order), end(order)));

  printf("%.10f\n", ans);
  return 0;
}
