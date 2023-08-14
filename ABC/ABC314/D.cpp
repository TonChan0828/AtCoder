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
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<pair<char, int>> res(n);
  rep(i, 0, n) res[i] = {s[i], 0};

  int big = -1, small = -1;
  rep(i, 0, q) {
    int t, x;
    char c;
    cin >> t >> x >> c;
    if (t == 1) {
      res[--x] = {c, i};
    } else if (t == 2) {
      small = i;
    } else {
      big = i;
    }
  }
  string ans = "";
  rep(i, 0, n) {
    if (res[i].second > max(big, small)) {
      ans.push_back(res[i].first);
      continue;
    }

    if (big > small) {
      ans.push_back(toupper(res[i].first));
    } else {
      ans.push_back(tolower(res[i].first));
    }
  }
  cout << ans << endl;
  return 0;
}
