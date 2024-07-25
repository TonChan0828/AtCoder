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
  ll n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  --n;

  for (int keta = 1;; ++keta) {
    int l = (keta + 1) / 2;
    ll num = 9;
    rep(i, 0, l - 1) num *= 10;
    if (n > num) {
      n -= num;
      continue;
    }

    n += num / 9 - 1;
    string s = to_string(n);
    string rs = s;
    reverse(begin(rs), end(rs));
    if (keta % 2 == 1) s.pop_back();
    s += rs;
    cout << s << endl;
    return 0;
  }
  return 0;
}
