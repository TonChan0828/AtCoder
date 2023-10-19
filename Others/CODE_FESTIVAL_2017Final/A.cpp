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
const string tar = "AKIHABARA";

int main() {
  string s;
  cin >> s;
  int sz = s.size();
  vector<bool> ch(tar.size());
  int pos = 0;
  rep(i, 0, sz) {
    bool ng = true;
    rep(j, pos, 9) {
      if (s[i] == tar[j]) {
        ch[j] = true;
        pos = j + 1;
        ng = false;
        break;
      }
    }
    if (ng) {
      cout << "NO" << endl;
      return 0;
    }
  }
  rep(i, 0, tar.size()) {
    if (!ch[i] && tar[i] != 'A') {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
