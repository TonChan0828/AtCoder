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
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];

  rep(i, 0, n) {
    rep(j, 0, n) {
      if (i == j) continue;
      string tar = s[i] + s[j];
      // cout << tar << endl;
      int sz = tar.size();
      bool ok = true;
      rep(k, 0, sz / 2) {
        if (tar[k] != tar[sz - 1 - k]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}