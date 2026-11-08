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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  if (n == 1) {
    cout << 0 << "\n";
    return 0;
  }
  rep(i, 0, n) {
    int ans = 1001001001;
    if (i != n - 1) {
      int cost = 0;
      cost = (a[i + 1] - a[i]) / 2;
      cost +=
          max(a[i] + cost - (a[0] + cost), (a[n - 1] - cost) - (a[i] + cost)) /
          2;
      ans = min(ans, cost);
    }
    if (i != 0) {
      int cost = 0;
      cost = (a[i] - a[i - 1]) / 2;
      cost += max((a[i] - cost) - (a[0] + cost),
                  (a[n - 1] - cost) - (a[i] - cost)) /
              2;
      ans = min(ans, cost);
    }
    cout << ans << "\n";
  }
  return 0;
}
