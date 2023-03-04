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
  ll n;
  cin >> n;
  map<ll, ll> num;
  rep(i, 0, n) {
    int a;
    cin >> a;
    num[a]++;
  }
  ll ans = n * (n - 1) * (n - 2) / 6;
  for (auto x : num) {
    // cout << x.first << " " << x.second << endl;
    if (x.second < 2) continue;
    ans -= (x.second * (x.second - 1) / 2) * (n - x.second);
    ans -= (x.second * (x.second - 1) * (x.second - 2)) / 6;
    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
