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
  int k;
  string s, t;
  cin >> k >> s >> t;

  int n = s.size(), m = t.size();
  if (abs(n - m) > 1) {
    cout << "No" << endl;
    return 0;
  }

  bool ok1 = true, ok2 = true, ok3 = true;
  ;
  int j = 0;
  rep(i, 0, n) {
    rep(l, 0, 2) {
      // cout << s[i] << " " << t[j] << endl;
      if (s[i] == t[j]) break;
      ++j;
    }
    if (j >= m || abs(i - j) > 1) {
      ok1 = false;
      break;
    }
    ++j;
  }

  j = 0;
  rep(i, 0, m) {
    rep(l, 0, 2) {
      // cout << s[j] << " " << t[i] << endl;
      if (s[j] == t[i]) break;
      ++j;
    }
    if (j >= n || abs(i - j) > 1) {
      ok2 = false;
      break;
    }
    ++j;
  }

  if (n == m) {
    int cnt = 0;
    rep(i, 0, n) {
      if (s[i] != t[i]) ++cnt;
    }
    if (cnt > 1) ok3 = false;
  } else {
    ok3 = false;
  }

  if (ok1 || ok2 || ok3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
