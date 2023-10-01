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
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  bool prefix = true, suffix = true;

  rep(i, 0, n) {
    if (s[i] != t[i]) {
      prefix = false;
      break;
    }
  }

  rep(i, 0, n) {
    if (s[n - 1 - i] != t[m - 1 - i]) {
      suffix = false;
      break;
    }
  }
  int ans = 3;
  if (prefix && suffix)
    ans = 0;
  else if (prefix && !suffix)
    ans = 1;
  else if (!prefix && suffix)
    ans = 2;
  cout << ans << endl;
  return 0;
}
