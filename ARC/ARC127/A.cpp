#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

ll count(ll tar, ll n) {
  if (tar > n) return 0;
  ll sum = 0;
  ll tmp = tar;
  ll max = (tar + 1);
  do {
    sum += (min(max - 1, n) - tmp + 1);
    tmp *= 10;
    max *= 10;
    // cout << sum << endl;
  } while (tmp <= n);
  sum += count(tar * 10 + 1, n);
  return sum;
}

int main() {
  ll n;
  cin >> n;
  ll ans = count(1, n);
  cout << ans << endl;
  return 0;
}
