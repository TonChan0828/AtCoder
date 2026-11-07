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
  int h, w, n, Q;
  cin >> h >> w >> n >> Q;
  vector<int> r(n), c(n);
  rep(i, 0, n) cin >> r[i] >> c[i];
  sort(begin(r), end(r));
  sort(begin(c), end(c));

  rep(qi, 0, Q) {
    int q;
    cin >> q;
    if (q == 1) {
      int u, d;
      cin >> u >> d;
      auto itu = lower_bound(begin(r), end(r), u);
      auto itd = upper_bound(begin(r), end(r), d);
      cout << itd - itu << "\n";
    } else {
      int l, r;
      cin >> l >> r;
      auto itl = lower_bound(begin(c), end(c), l);
      auto itr = upper_bound(begin(c), end(c), r);
      cout << itr - itl << "\n";
    }
  }
  return 0;
}
