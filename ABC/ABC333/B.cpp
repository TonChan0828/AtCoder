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
  string s, t;
  cin >> s >> t;
  int ss, tt;
  ss = abs(s[0] - s[1]);
  if (s == "EA" || s == "AE") ss = 1;
  tt = abs(t[0] - t[1]);
  if (t == "EA" || t == "AE") tt = 1;
  string ans;
  if (ss == 1) {
    if (tt == 1) {
      ans = "Yes";
    } else {
      ans = "No";
    }
  } else {
    if (tt == 1) {
      ans = "No";
    } else {
      ans = "Yes";
    }
  }
  cout << ans << endl;
  return 0;
}
