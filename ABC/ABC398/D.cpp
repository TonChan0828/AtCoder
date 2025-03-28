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
  int n, r, c;
  string s;
  cin >> n >> r >> c >> s;

  int sr = 0, sc = 0;
  set<pair<int, int>> st;
  st.insert({sr, sc});
  for (char ch : s) {
    if (ch == 'N') {
      r++, sr++;
    } else if (ch == 'W') {
      c++, sc++;
    } else if (ch == 'S') {
      r--, sr--;
    } else {
      c--, sc--;
    }
    st.insert({sr, sc});
    if (st.find({r, c}) == st.end()) {
      cout << "0";
    } else {
      cout << "1";
    }
  }
  cout << endl;
  return 0;
}
