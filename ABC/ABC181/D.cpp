#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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

  int sz = s.size();
  bool ans = false;
  if (sz == 1) {
    if (s[0] == '8') {
      ans = true;
    }
  } else if (sz == 2) {
    if (stoi(s) % 8 == 0) {
      ans = true;
    }
    swap(s[0], s[1]);
    if (!ans && stoi(s) % 8 == 0) {
      ans = true;
    }
  } else {
    map<int, int> mp;
    rep(i, 0, sz) { ++mp[s[i] - '0']; }
    for (int i = 112; i < 1000; i += 8) {
      map<int, int> tar;
      int tmp = i;
      rep(j, 0, 3) {
        tar[tmp % 10]++;
        tmp /= 10;
      }
      bool ok = true;
      for (auto m : tar) {
        if (mp[m.first] < m.second) ok = false;
      }
      if (ok) ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
