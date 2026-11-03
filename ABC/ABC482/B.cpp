#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  vector<string> s(5);
  rep(i, 0, 5) cin >> s[i];
  int ans = 5;
  rep(i, 0, 5) {
    int cnt = 0;
    rep(j, 0, 5) {
      if (s[i][j] == '.') ++cnt;
    }
    ans = min(ans, cnt);
  }
  rep(j, 0, 5) {
    int cnt = 0;
    rep(i, 0, 5) {
      if (s[i][j] == '.') ++cnt;
    }
    ans = min(ans, cnt);
  }
  int cnt = 0;
  rep(i, 0, 5) {
    if (s[i][i] == '.') ++cnt;
  }
  ans = min(ans, cnt);
  cnt = 0;
  rep(i, 0, 5) {
    if (s[i][4 - i] == '.') ++cnt;
  }
  ans = min(ans, cnt);

  cout << ans << endl;
  return 0;
}
