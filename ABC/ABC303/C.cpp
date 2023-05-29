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
  int n, m, h, k;
  cin >> n >> m >> h >> k;
  string s;
  cin >> s;
  set<pair<int, int>> set;
  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    set.insert({x, y});
  }

  int x = 0, y = 0;
  rep(i, 0, n) {
    if (s[i] == 'R') {
      ++x;
    } else if (s[i] == 'L') {
      --x;
    } else if (s[i] == 'U') {
      ++y;
    } else {
      --y;
    }

    --h;
    if (h < 0) {
      cout << "No" << endl;
      return 0;
    }

    if (set.count({x, y})) {
      if (h < k) {
        h = k;
        set.erase({x, y});
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
