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
  char ans = 'T';
  int cntt = 0, cnta = 0;
  rep(i, 0, n) {
    if (s[i] == 'T') {
      ++cntt;
    } else {
      ++cnta;
    }
    if (cntt > cnta) {
      ans = 'T';
    }
    if (cnta > cntt) {
      ans = 'A';
    }
  }
  cout << ans << endl;
  return 0;
}
