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
  string s;
  cin >> n >> s;
  int mid = n / 2;
  if (n % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  if (s[mid] != 'b') {
    cout << -1 << endl;
    return 0;
  }
  rep(i, 0, mid) {
    if (i % 3 == 0) {
      if (s[mid - i] != 'b' || s[mid + i] != 'b') {
        // cout << 0 << endl;
        cout << -1 << endl;
        return 0;
      }
    } else if (i % 3 == 1) {
      if (s[mid - i] != 'a' || s[mid + i] != 'c') {
        // cout << i << endl;
        cout << -1 << endl;
        return 0;
      }
    } else {
      if (s[mid - i] != 'c' || s[mid + i] != 'a') {
        // cout << 2 << endl;
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << mid << endl;

  return 0;
}
