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

int main() {
  ll n, k;
  cin >> n >> k;
  if (k % 10 == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  ll tar = k;
  while (tar <= n) {
    ++ans;
    tar *= 10;
  }
  ll tmp = k;
  tar = 0;
  while (tmp > 0) {
    tar *= 10;
    tar += tmp % 10;
    tmp /= 10;
  }
  if (tar < k) {
    cout << 0 << endl;
    return 0;
  } else if (tar == k) {
    cout << ans << endl;
    return 0;
  }
  // cout << tar << endl;
  while (tar <= n) {
    ++ans;
    tar *= 10;
  }
  cout << ans << endl;
  return 0;
}
