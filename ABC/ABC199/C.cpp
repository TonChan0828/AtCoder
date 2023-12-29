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
  cin >> n;
  vector s(2, vector<char>(n));
  rep(i, 0, 2) { rep(j, 0, n) cin >> s[i][j]; }
  cin >> q;
  int rev = 0;
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    --a, --b;
    if (t == 1) {
      swap(s[(rev + a / n) % 2][a % n], s[(rev + b / n) % 2][b % n]);
    } else {
      rev = (rev + 1) % 2;
    }
  }
  rep(i, 0, 2) {
    rep(j, 0, n) { cout << s[(rev + i) % 2][j]; }
  }
  cout << endl;
  return 0;
}
