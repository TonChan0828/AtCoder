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
  vector<int> x(3), y(3);
  rep(i, 0, 3) cin >> x[i] >> y[i];
  if (x[0] == x[1]) {
    cout << x[2];
  } else if (x[1] == x[2]) {
    cout << x[0];
  } else if (x[0] == x[2]) {
    cout << x[1];
  }
  cout << " ";
  if (y[0] == y[1]) {
    cout << y[2];
  } else if (y[1] == y[2]) {
    cout << y[0];
  } else if (y[0] == y[2]) {
    cout << y[1];
  }
  cout << endl;
  return 0;
}
