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
  ll n, a, x, y;
  cin >> n >> a >> x >> y;

  map<ll, double> memo;
  auto f = [&](auto f, ll n) -> double {
    if (n == 0) return 0;
    if (memo.count(n)) return memo[n];
    double res = f(f, n / a) + x;
    double dice = 0;
    rep(b, 2, 7) { dice += f(f, n / b); }
    dice /= 5;
    dice += y * 6 / 5.0;
    res = min(res, dice);
    return memo[n] = res;
  };
  printf("%.10f\n", f(f, n));
  return 0;
}
