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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  int ma = *max_element(begin(a), end(a));
  vector<bool> num(ma + 1, true);
  vector<int> prime;
  num[0] = num[1] = false;
  rep(i, 0, ma + 1) {
    if (!num[i]) continue;
    for (int j = i + i; j <= ma; j += i) {
      num[j] = false;
    }
    prime.push_back(i);
  }

  ll ans = 0;
  ll zero = 0;
  map<vector<int>, ll> mp;
  map<int, vector<int>> primeOdd;

  auto f = [&](int x) {
    if (!primeOdd[x].empty()) return;
    vector<int> chOdd;
    int tar = x;
    for (int p : prime) {
      int cnt = 0;
      while (tar % p == 0) {
        ++cnt;
        tar /= p;
      }
      if (cnt % 2) chOdd.push_back(p);
      if (tar == 1) break;
    }
    chOdd.push_back(0);
    primeOdd[x] = chOdd;
    return;
  };

  rep(i, 0, n) {
    ll aa = a[i];
    if (aa == 0) {
      ans += i;
      zero++;
    } else {
      f(aa);
      ans += mp[primeOdd[aa]]++;
      ans += zero;
    }
    // cout << ans << endl;
  }

  cout << ans << endl;
  return 0;
}
