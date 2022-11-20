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
  int n;
  cin >> n;
  vector<vector<ll>> a(n + 1);
  rep(i, 1, n + 1) {
    ll tmp;
    cin >> tmp;
    a[i] = {tmp, -1, -1};
  }
  ll k = -1;
  ll l = -1;
  int q;
  cin >> q;
  ll total = 0;
  rep(i, 0, q) {
    int p;
    cin >> p;
    if (p == 1) {
      ll x;
      cin >> x;
      k = x;
      l = i;
    } else if (p == 2) {
      int iq;
      ll x;
      cin >> iq >> x;
      if (a[iq][1] == k && a[iq][2] == l) {
        a[iq] = {a[iq][0] + x, k, l};
      } else {
        a[iq] = {k + x, k, l};
      }
    } else {
      int iq;
      cin >> iq;
      if (a[iq][1] == k && a[iq][2] == l) {
        cout << a[iq][0] << endl;
      } else {
        cout << k << endl;
        ;
      }
    }
  }
  return 0;
}
