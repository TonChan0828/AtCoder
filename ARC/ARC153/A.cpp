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
  ll n;
  cin >> n;
  --n;
  vector<int> v(6, 0);
  rep(i, 0, 6) {
    v[5 - i] = n % 10;
    n /= 10;
  }
  cout << v[0] + 1 << v[0] + 1 << v[1] << v[2] << v[3] << v[3] << v[4] << v[5]
       << v[4] << endl;
  return 0;
}
