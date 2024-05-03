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
  int n;
  cin >> n;
  n *= 2;
  vector a(n - 1, vector<ll>(n));
  rep(i, 0, n - 1) rep(j, i + 1, n) cin >> a[i][j];

  auto f = [&](auto f, int pos, set<int> s, ll now) -> ll {
    if (s.size() == n) return now;
    while (s.contains(pos)) ++pos;
    ll res = 0;
    s.insert(pos);
    rep(pa, pos + 1, n) {
      if (s.contains(pa)) continue;

      s.insert(pa);
      res = max(res, f(f, pos + 1, s, now ^ a[pos][pa]));
      s.erase(pa);
    }
    return res;
  };

  ll ans = 0;
  set<int> t;
  t.insert(0);
  rep(i, 1, n) {
    t.insert(i);
    ans = max(ans, f(f, 1, t, a[0][i]));
    t.erase(i);
  }
  cout << ans << endl;
  return 0;
}
