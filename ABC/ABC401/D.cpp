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
  int n, k;
  string s;
  cin >> n >> k >> s;

  rep(i, 0, n) {
    if (s[i] == 'o') {
      if (i) s[i - 1] = '.';
      if (i + 1 < n) s[i + 1] = '.';
    }
  }

  int x = k - count(begin(s), end(s), 'o');
  vector<pair<int, int>> ps;
  {
    int i = 0;
    while (i < n) {
      if (s[i] == '?') {
        int l = i;
        while (i < n && s[i] == '?') i++;
        int r = i;
        ps.emplace_back(l, r);
      } else {
        i++;
      }
    }
  }
  int mx = 0;
  for (auto [l, r] : ps) mx += (r - l + 1) / 2;
  if (x == 0) {
    for (auto [l, r] : ps) {
      rep(i, l, r) s[i] = '.';
    }
  } else if (x == mx) {
    for (auto [l, r] : ps) {
      if ((r - l) % 2 == 0) continue;
      rep(i, 0, r - l) { s[l + i] = "o."[i % 2]; }
    }
  }

  cout << s << endl;
  return 0;
}
