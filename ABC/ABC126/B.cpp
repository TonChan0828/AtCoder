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
  string s;
  cin >> s;
  bool yymm = true, mmyy = true;
  if (s[0] == '0' && s[1] != '0') {
    mmyy = true;
  } else if (s[0] == '1' && (s[1] <= '2')) {
    mmyy = true;
  } else {
    mmyy = false;
  }

  if (s[2] == '0' && s[3] != '0') {
    yymm = true;
  } else if (s[2] == '1' && (s[3] <= '2')) {
    yymm = true;
  } else {
    yymm = false;
  }

  if (yymm && mmyy) {
    cout << "AMBIGUOUS\n";
  } else if (yymm) {
    cout << "YYMM\n";
  } else if (mmyy) {
    cout << "MMYY\n";
  } else {
    cout << "NA\n";
  }
  return 0;
}
