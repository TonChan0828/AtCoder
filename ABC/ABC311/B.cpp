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
  int n, d;
  cin >> n >> d;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<int> cnt(d, 0);
  rep(i, 0, n) {
    rep(j, 0, d) {
      if (s[i][j] == 'o') ++cnt[j];
    }
  }
  int res = 0;
  int tmp = 0;
  rep(i, 0, d) {
    if (cnt[i] == n)
      ++tmp;
    else
      tmp = 0;
    res = max(res, tmp);
  }
  cout << res << endl;
  return 0;
}
