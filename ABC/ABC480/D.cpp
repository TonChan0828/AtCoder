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

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  // sum[i]: Aの先頭i項の和, pos[i]: i個のブロックの合計長, sum2[i]: ブロックi個分の和
  vector<ll> sum(n + 1, 0), pos(n + 1, 0), sum2(n + 1, 0);
  rep(i, 0, n) {
    sum[i + 1] = sum[i] + a[i];
    pos[i + 1] = pos[i] + i + 1;
    sum2[i + 1] = sum2[i] + sum[i + 1];
  }

  // Bの先頭x項の和
  auto f = [&](ll x) -> ll {
    int k = upper_bound(pos.begin(), pos.end(), x) - pos.begin() - 1;
    ll rem = x - pos[k];
    return sum2[k] + sum[rem];
  };

  rep(qi, 0, q) {
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << '\n';
  }
  return 0;
}
