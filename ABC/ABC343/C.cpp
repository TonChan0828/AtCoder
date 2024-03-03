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
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  ll k;
  cin >> k;
  ll ans = 0;
  rep(i, 1, 1e6 + 1) {
    ll t = i;
    ll x = t * t * t;
    if (x > k) break;
    vector<ll> num;
    ll tar = x;
    while (tar > 0) {
      num.push_back(tar % 10LL);
      tar /= 10LL;
    }
    int sz = num.size();
    bool ok = true;
    rep(j, 0, sz / 2) {
      if (num[j] != num[sz - 1 - j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = x;
      // cout << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
