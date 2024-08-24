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
  ll k;
  cin >> n >> k;
  vector<int> x(n), a(n);
  rep(i, 0, n) cin >> x[i], x[i]--;
  rep(i, 0, n) cin >> a[i];

  const int D = 60;
  vector d(D, vector<int>(n));
  d[0] = x;
  rep(i, 0, D - 1) {
    rep(v, 0, n) { d[i + 1][v] = d[i][d[i][v]]; }
  }

  vector<int> ans(n);
  rep(i, 0, n) {
    int v = i;
    rep(j, 0, D) {
      if (k >> j & 1) v = d[j][v];
    }
    ans[i] = a[v];
  }

  rep(i, 0, n) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
