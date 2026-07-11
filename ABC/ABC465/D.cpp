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
  int T;
  cin >> T;
  while (T--) {
    ll x, y, k;
    cin >> x >> y >> k;

    map<ll, int> mp;
    mp[x] = 1;
    int cnt = 1;
    while (x > 0) {
      x /= k;
      mp[x] = ++cnt;
    }
    int ans = 0;
    if (mp[y] > 0) {
      ans = mp[y];
    } else {
      while (y > 0) {
        y /= k;
        ++ans;
        if (mp[y] > 0) {
          ans += mp[y];
          break;
        }
      }
    }
    cout << ans - 1 << "\n";
  }
  return 0;
}
