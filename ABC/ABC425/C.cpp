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
  int n, Q;
  cin >> n >> Q;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> sum(n + 1);
  rep(i, 0, n) sum[i + 1] = sum[i] + a[i];

  int st = 0;
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int c;
      cin >> c;
      st = (st + c) % n;
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      int lt = (st + l) % n, rt = (st + r) % n;
      if (lt < rt) {
        cout << sum[rt] - sum[lt] << "\n";
      } else {
        cout << (sum[n] - sum[lt]) + (sum[rt] - sum[0]) << "\n";
      }
    }
  }
  return 0;
}
