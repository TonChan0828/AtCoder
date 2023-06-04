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
  int n;
  cin >> n;
  if (n <= 1e3 - 1) {
    cout << n << endl;
  } else if (n <= 1e4 - 1) {
    cout << n - n % 10 << endl;
  } else if (n <= 1e5 - 1) {
    cout << n - n % 100 << endl;
  } else if (n <= 1e6 - 1) {
    cout << n - n % 1000 << endl;
  } else if (n <= 1e7 - 1) {
    cout << n - n % 10000 << endl;
  } else if (n <= 1e8 - 1) {
    cout << n - n % 100000 << endl;
  } else {
    cout << n - n % 1000000 << endl;
  }

  return 0;
}
