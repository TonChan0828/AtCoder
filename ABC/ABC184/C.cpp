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

int solve() {
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  if (r1 == r2 && c1 == c2) return 0;
  if (r1 + c1 == r2 + c2) return 1;
  if (r1 - c1 == r2 - c2) return 1;
  if (abs(r1 - r2) + abs(c1 - c2) <= 3) return 1;
  if ((r1 + c1) % 2 == (r2 + c2) % 2) return 2;
  if (abs(r1 - r2) + abs(c1 - c2) <= 6) return 2;
  if (abs((r1 + c1) - (r2 + c2)) <= 3) return 2;
  if (abs((r1 - c1) - (r2 - c2)) <= 3) return 2;
  return 3;
}

int main() {
  cout << solve() << endl;

  return 0;
}
