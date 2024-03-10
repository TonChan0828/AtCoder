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
  int n, m, l, q;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  cin >> m;
  vector<ll> b(m);
  rep(i, 0, m) cin >> b[i];
  cin >> l;
  vector<ll> c(l);
  rep(i, 0, l) cin >> c[i];
  set<ll> s;
  rep(i, 0, n) {
    rep(j, 0, m) {
      rep(k, 0, l) { s.insert(a[i] + b[j] + c[k]); }
    }
  }

  cin >> q;
  rep(i, 0, q) {
    ll x;
    cin >> x;
    if (s.find(x) != s.end()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
