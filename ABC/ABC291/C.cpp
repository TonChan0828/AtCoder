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
  string s;
  cin >> s;
  set<pair<int, int>> set;
  int x = n + 1, y = n + 1;
  rep(i, 0, n) {
    if (set.count({x, y})) {
      cout << "Yes" << endl;
      return 0;
    } else {
      set.insert({x, y});
    }
    if (s[i] == 'R') {
      ++x;
    } else if (s[i] == 'L') {
      --x;
    } else if (s[i] == 'U') {
      --y;
    } else if (s[i] == 'D') {
      ++y;
    } else {
    }
  }
  if (set.count({x, y})) {
    cout << "Yes" << endl;
    return 0;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
