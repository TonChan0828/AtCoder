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

using ull = unsigned long long;

int main() {
  int n;
  ull x;
  string s;
  cin >> n >> x >> s;

  string d;
  while (x) {
    d += '0' + (x & 1);
    x >>= 1;
  }
  reverse(begin(d), end(d));
  for (char c : s) {
    if (c == 'U') {
      d.pop_back();
    }
    if (c == 'L') {
      d += '0';
    }
    if (c == 'R') {
      d += '1';
    }
  }
  x = 0;
  for (char c : d) {
    x = x << 1 | (c - '0');
  }
  cout << x << endl;
  return 0;
}
