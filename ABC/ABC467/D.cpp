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

// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V {
  ll x, y;
  V(ll x = 0, ll y = 0) : x(x), y(y) {}
  V& operator+=(const V& v) {
    x += v.x;
    y += v.y;
    return *this;
  }
  V operator+(const V& v) const { return V(*this) += v; }
  V& operator-=(const V& v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }
  V operator-(const V& v) const { return V(*this) -= v; }
  V& operator*=(ll s) {
    x *= s;
    y *= s;
    return *this;
  }
  V operator*(ll s) const { return V(*this) *= s; }
  ll dot(const V& v) const { return x * v.x + y * v.y; }
  ll cross(const V& v) const { return x * v.y - v.x * y; }
  ll norm2() const { return x * x + y * y; }
  V rotate90() const { return V(y, -x); }
};
istream& operator>>(istream& is, V& v) {
  is >> v.x >> v.y;
  return is;
}
ostream& operator<<(ostream& os, const V& v) {
  os << "(" << v.x << "," << v.y << ")";
  return os;
}

bool solve() {
  V p, q, r, s;
  cin >> p >> q >> r >> s;
  V a = p + q, b = r + s;
  V v = (p - q).rotate90(), w = (r - s).rotate90();
  if (v.cross(w) != 0) return true;
  if (v.cross(b - a) == 0) return true;
  return false;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    if (solve())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
