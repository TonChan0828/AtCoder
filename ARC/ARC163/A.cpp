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
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    bool ok = false;

    rep(i, 0, n - 1) {
      bool ok2 = false;
      vector<string> tmp(2);
      tmp[0] = s.substr(0, i + 1);
      tmp[1] = s.substr(i + 1, n - i - 1);
      vector<string> tar = tmp;
      sort(tar.begin(), tar.end());
      // cout << tmp[0] << " " << tmp[1] << endl;
      if (tmp[0] < tmp[1]) ok2 = true;
      if (ok2) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
