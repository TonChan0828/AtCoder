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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(begin(a), end(a));

  while (Q--) {
    int x, y;
    cin >> x >> y;
    ll l = x, r = x + y + n;
    auto itl = lower_bound(begin(a), end(a), x);
    while (l + 1 < r) {
      int m = (l + r) / 2;
      auto itr = lower_bound(begin(a), end(a), m);
      int dif = itr - itl;
      if (m - x + 1 - dif <= y) {
        l = m;
      } else {
        r = m;
      }
      // cout << l << "  " << r << " " << dif << endl;
    }
    cout << l << "\n";
  }
  return 0;
}
