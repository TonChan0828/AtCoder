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

const vector<string> tar = {"ABC", "?BC", "A?C", "AB?",
                            "??C", "?B?", "A??", "???"};
const int tz = tar.size();
int main() {
  string s;
  cin >> s;
  int sz = s.size();
  long double total = 1;
  rep(i, 0, sz) {
    if (s[i] == '?') total *= 3;
  }

  long double p = 0;
  rep(i, 0, sz - 2) {
    string tmp = s.substr(i, 3);
    cout << tmp << endl;
    rep(j, 0, tz) {
      if (tmp == tar[j]) ++p;
    }
  }
  printf("%.15lf\n", p / total);
  return 0;
}
