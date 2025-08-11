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
  string s;
  cin >> s;
  int sz = s.size();
  double ans = 0;
  rep(i, 0, sz - 2) {
    rep(j, i + 2, sz) {
      if (s[i] != 't' || s[j] != 't') continue;
      double res = count(begin(s) + i, begin(s) + j + 1, 't') - 2;
      // cout << i << " " << j << " " << res << " " << j - i - 1 << endl;
      res /= (double)j - i - 1;
      ans = max(ans, res);
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
