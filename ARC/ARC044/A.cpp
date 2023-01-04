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

  if (n == 1) {
    cout << "Not Prime" << endl;
    return 0;
  }
  bool ok = true;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Prime" << endl;
    return 0;
  }

  if (n % 2 == 0 || n % 5 == 0) {
    cout << "Not Prime" << endl;
    return 0;
  }
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  if (sum % 3 == 0) {
    cout << "Not Prime" << endl;
    return 0;
  }
  cout << "Prime" << endl;
  return 0;
}
