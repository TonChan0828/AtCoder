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
  ll c;
  cin >> n >> c;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<ll> sum(n + 1, 0);
  rep(i, 0, n) sum[i + 1] = sum[i] + a[i];
  ll res = sum[n];
  int l = 0;
  rep(r, 1, n + 1) {
    ll d = sum[r] - sum[l];
    res = max(res, sum[n] - d + (d * c));
    if (c > 0) {
      if (d < 0) {
        l = r;
      }
    } else {
      if (d > 0) {
        l = r;
      }
    }
  }
  cout << res << endl;
  return 0;
}
