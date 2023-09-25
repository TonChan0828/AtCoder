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
  string s;
  int t, sz;
  cin >> s >> t;
  sz = s.size();
  int cnt = 0;
  int x = 0, y = 0;
  map<char, pair<int, int>> m;
  m['L'] = {-1, 0};
  m['R'] = {1, 0};
  m['U'] = {0, -1};
  m['D'] = {0, 1};
  rep(i, 0, sz) {
    if (s[i] == '?') {
      ++cnt;
      continue;
    }
    x += m[s[i]].first, y += m[s[i]].second;
  }
  int ans = abs(x) + abs(y);
  if (t == 1) {
    ans = abs(ans + cnt);
  } else {
    rep(i, 0, cnt) { ans = abs(ans - 1); }
  }
  cout << ans << endl;
  return 0;
}
