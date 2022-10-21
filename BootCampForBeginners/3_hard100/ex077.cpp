#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  vector<vector<int>> s(h, vector<int>(w, 0));
  rep(i, 0, h) {
    if (i < b) {
      rep(j, 0, a) s[i][j] = 1;
    } else {
      rep(j, a, w) s[i][j] = 1;
    }
  }
  rep(i, 0, h) {
    rep(j, 0, w) { cout << s[i][j]; }
    cout << endl;
  }
  return 0;
}
