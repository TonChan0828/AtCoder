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
  int n;
  cin >> n;
  vector<string> w(n);
  rep(i, 0, n) cin >> w[i];

  set<string> s;
  rep(i, 0, n) {
    bool check = true;
    if (s.find(w[i]) != s.end()) {
      check = false;
    }
    s.insert(w[i]);
    if (i != 0) {
      if (w[i - 1].back() != w[i][0]) {
        check = false;
      }
    }

    if (check) continue;
    if (i % 2) {
      cout << "WIN" << endl;
      return 0;
    } else {
      cout << "LOSE" << endl;
      return 0;
    }
  }
  cout << "DRAW" << endl;
  return 0;
}
