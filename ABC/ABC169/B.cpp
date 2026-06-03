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
  vector<ll> a(n);
  bool zero = false;
  rep(i, 0, n) {
    cin >> a[i];
    if (a[i] == 0) zero = true;
  }

  if (zero) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  rep(i, 0, n) {
    ll tar = 1000000000000000000 / ans;
    // cout << i << " " << tar << endl;
    if (a[i] > tar) {
      ans = -1;
      break;
    }
    ans *= a[i];
    if (ans > 1000000000000000000) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
