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
  vector<string> a(n);
  rep(i, 0, n) cin >> a[i];

  auto f = [&](int x, int y, int p) -> char {
    switch (p) {
      case 0:
        return a[n - 1 - x][y];
        break;
      case 1:
        return a[n - 1 - y][n - 1 - x];
        break;
      case 2:
        return a[x][n - 1 - y];
        break;
      case 3:
        return a[y][x];
        break;

      default:
        break;
    }
    return a[y][x];
  };

  rep(i, 0, n) {
    rep(j, 0, n) {
      int t = 0;
      if (i < n / 2) {
        if (j < n / 2) {
          t = min(i, j);
        } else {
          t = min(i, n - 1 - j);
        }
      } else {
        if (j < n / 2) {
          t = min(n - 1 - i, j);
        } else {
          t = min(n - 1 - i, n - 1 - j);
        }
      }
      cout << f(j, i, t % 4);
    }
    cout << "\n";
  }
  return 0;
}
