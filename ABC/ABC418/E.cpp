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

struct Frac {
  int a, b;
  Frac(int _a = 0, int _b = 1) : a(_a), b(_b) {
    if (b < 0) a = -a, b = -b;
    if (b == 0) a = 1;
    int g = gcd(abs(a), b);
    a /= g;
    b /= g;
  }
  bool operator<(const Frac &f) const { return (ll)a * f.b < (ll)f.a * b; }
  ll toll() const { return a * ll(1e9) + b; }
};

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];

  auto calc = [&](bool len = false) {
    ll res = 0;
    vector<pair<ll, int>> ps;
    rep(i, 0, n) rep(j, 0, i) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      Frac f(dy, dx);
      pair<ll, int> p(f.toll(), abs(dx) + abs(dy));
      if (!len) p.second = 0;
      ps.push_back(p);
    }
    sort(begin(ps), end(ps));
    int now = 0;
    rep(i, 1, ps.size()) {
      if (ps[i] != ps[i - 1]) now = 0;
      res += now;
      now++;
    }
    return res;
  };

  ll ans = calc() - calc(true) / 2;
  cout << ans << endl;

  return 0;
}
