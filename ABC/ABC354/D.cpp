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
  ll m = 1e9;
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  // a += m, b += m, c += m, d += m;
  const vector<vector<ll>> ru = {
      {0, 0, 0, 0, 0}, {0, 2, 3, 3, 4}, {0, 3, 6, 7, 8}};
  const vector<vector<ll>> rd = {
      {0, 0, 0, 0, 0}, {0, 1, 3, 4, 4}, {0, 3, 6, 7, 8}};
  const vector<vector<ll>> lu = {
      {0, 0, 0, 0, 0}, {0, 1, 1, 2, 4}, {0, 1, 2, 5, 8}};
  const vector<vector<ll>> ld = {
      {0, 0, 0, 0, 0}, {0, 0, 1, 3, 4}, {0, 1, 2, 5, 8}};

  ll a4 = (a + 4) / 4, b2 = (b + 2) / 2, c4 = c / 4, d2 = d / 2;
  ll am = a4 * 4, bm = b2 * 2, cm = c4 * 4, dm = d2 * 2;
  ll da = llabs(a - am), db = llabs(b - bm), dc = llabs(c - cm),
     dd = llabs(d - dm);

  ll ans = 0;
  ans += 8LL * (c4 - a4) * (d2 - b2);
  // cout << "1 " << ans << endl;

  ans += 4LL * dd * (c4 - a4);
  // cout << "2 " << ans << endl;

  ans += 4LL * db * (c4 - a4);
  // cout << "3 " << ans << endl;

  ans += ru[2][dc] * (d2 - b2);
  // cout << "4 " << ans << endl;

  ans += lu[2][da] * (d2 - b2);
  // cout << "5 " << ans << endl;

  // 右上
  ans += ru[dd][dc];
  // cout << "ru " << ans << endl;

  // 左上
  ans += lu[dd][da];
  // cout << "lu " << ans << endl;

  // 右下
  ans += rd[db][dc];
  // cout << "rd " << ans << endl;

  // 左下
  ans += ld[db][da];
  // cout << "ld " << ans << endl;

  cout << ans << endl;

  return 0;
}
