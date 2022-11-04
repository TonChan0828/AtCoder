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

ll f(ll x) {
  ll res = 0;
  if (x % 2 == 0) {
    res = x;
  }
  if ((x + 1) / 2 % 2 == 0) {
    res ^= 1;
  }
  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;

  cout << (f(a - 1) ^ f(b)) << endl;
  return 0;
}
