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
  string a[3][10];
  int h[3], w[3];
  rep(q, 0, 3) {
    cin >> h[q] >> w[q];
    rep(i, 0, h[q]) cin >> a[q][i];
  }

  rep(h0, 1, 20) {
    rep(w0, 1, 20) {
      rep(h1, 1, 20) {
        rep(w1, 1, 20) {
          vector<vector<char>> tmp(30, vector<char>(31, '.'));

          rep(i, 0, h[0]) {
            rep(j, 0, w[0]) {
              if (a[0][i][j] == '#') tmp[i + h0][j + w0] = '#';
            }
          }
          rep(i, 0, h[1]) {
            rep(j, 0, w[1]) {
              if (a[1][i][j] == '#') tmp[i + h1][j + w1] = '#';
            }
          }

          bool flag = true;
          rep(i, 0, 30) {
            rep(j, 0, 30) {
              if ((0 <= (i - 10)) && ((i - 10) < h[2]) && (0 <= (j - 10)) &&
                  ((j - 10 < w[2]))) {
                if (tmp[i][j] != a[2][i - 10][j - 10]) flag = false;
              } else {
                if (tmp[i][j] != '.') flag = false;
              }
            }
          }
          if (flag) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
