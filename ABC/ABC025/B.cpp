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
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  rep(i, 0, n) {
    string s;
    int d;
    cin >> s >> d;
    int dist = 0;
    if (d < a) {
      dist = a;
    } else if (d > b) {
      dist = b;
    } else {
      dist = d;
    }
    if (s == "East") {
      ans += dist;
    } else {
      ans -= dist;
    }
  }
  if (ans > 0) {
    cout << "East " << ans << endl;
  } else if (ans < 0) {
    cout << "West " << 0 - ans << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
