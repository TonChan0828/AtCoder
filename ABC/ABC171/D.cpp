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
  // int n;
  // cin >> n;
  // map<ll, ll> mp;
  // ll sum = 0;
  // rep(i, 0, n) {
  //   ll a;
  //   cin >> a;
  //   ++mp[a];
  //   sum += a;
  // }
  // int q;
  // cin >> q;
  // // cout << sum << endl;
  // rep(i, 0, q) {
  //   ll b, c;
  //   cin >> b >> c;
  //   sum += (c - b) * mp[b];
  //   cout << sum << endl;
  //   mp[c] += mp[b];
  //   mp[b] = 0;
  // }

  int n;
  cin >> n;
  vector<ll> t(100001, 0);
  ll sum = 0;
  rep(i, 0, n) {
    int a;
    cin >> a;
    sum += a;
    ++t[a];
  }
  int q;
  cin >> q;
  rep(i, 0, q) {
    int b, c;
    cin >> b >> c;
    sum += (c - b) * t[b];
    cout << sum << endl;
    t[c] += t[b];
    t[b] = 0;
  }
  return 0;
}
