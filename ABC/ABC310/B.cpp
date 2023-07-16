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
  int n, m;
  cin >> n >> m;
  vector<int> p(n), c(n);
  vector<vector<int>> f(n, vector<int>(101010, 0));
  rep(i, 0, n) {
    cin >> p[i];
    cin >> c[i];
    rep(j, 0, c[i]) {
      int tmp;
      cin >> tmp;
      f[i][tmp] = 1;
    }
  }

  rep(i, 0, n) {
    rep(j, 0, n) {
      if (i == j) continue;
      if (p[i] < p[j]) continue;
      if (c[i] > c[j]) continue;

      bool ok = true;
      rep(k, 0, 101) {
        if (f[i][k]) {
          if (!f[j][k]) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        if (c[i] == c[j] && p[i] > p[j]) {
          cout << "Yes" << endl;
          return 0;
        }
        if (c[i] < c[j]) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
