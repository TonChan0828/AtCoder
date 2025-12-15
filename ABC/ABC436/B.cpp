#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;

  vector a(n, vector<int>(n));
  int r = 0, c = (n - 1) / 2;

  rep(i, 1, n * n + 1) {
    a[r][c] = i;
    if (a[(n + r - 1) % n][(c + 1) % n] == 0) {
      r = (n + r - 1) % n, c = (c + 1) % n;
    } else {
      r = (r + 1) % n, c = c;
    }
  }

  rep(i, 0, n) {
    rep(j, 0, n) cout << a[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
