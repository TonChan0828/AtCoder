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
  string s;
  cin >> s;
  if (s.size() != 8) {
    cout << "No" << endl;
    return 0;
  }

  if (!(s[0] >= 'A' && s[0] <= 'Z')) {
    cout << "No" << endl;
    return 0;
  }
  if (!(s[7] >= 'A' && s[7] <= 'Z')) {
    cout << "No" << endl;
    return 0;
  }
  rep(i, 1, 7) {
    if (i == 1) {
      if (!(s[i] >= '1' && s[i] <= '9')) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (!(s[i] >= '0' && s[i] <= '9')) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
