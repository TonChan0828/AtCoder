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
  int ha, wa, hb, wb, hx, wx;
  cin >> ha >> wa;
  vector<string> a(ha);
  rep(i, 0, ha) cin >> a[i];
  cin >> hb >> wb;
  vector<string> b(hb);
  rep(i, 0, hb) cin >> b[i];
  cin >> hx >> wx;
  vector<vector<char>> x(hx + 21, vector<char>(wx + 21, '.'));
  vector<vector<int>> check(hx + 21, vector<int>(wx + 21, 0));
  vector<vector<int>> ac(ha, vector<int>(wa, 0));
  vector<vector<int>> bc(hb, vector<int>(wb, 0));

  rep(i, 0, hx) {
    rep(j, 0, wx) { cin >> x[10 + hx + i][10 + wx + j]; }
  }

  // rep(i, 0, hx + 20) {
  //   rep(j, 0, wx + 20) { printf("%d ", check[i][j]); }
  //   cout << "\n";
  // }

  rep(i, 0, 20 + hx) {
    rep(j, 0, 20 + wx) {
      auto tmp = check;
      bool ok = true;
      rep(k, 0, ha) {
        rep(l, 0, wa) {
          if (i + k > 20 + hx || j + l > 20 + wx) continue;
          if (a[k][l] == '#' && x[i + k][j + l] == '.') {
            ok = false;
            break;
          } else {
            if (a[k][l] == '#' && a[k][l] == x[i + k][j + l]) {
              tmp[i + k][j + l] = 1;
            }
          }
        }
      }
      if (ok) {
        aa = true;
        check = tmp;
        rep(k, 0, ha) {
          rep(l, 0, wa) {
            if (a[k][l] == '#') ac[k][l] = 1;
          }
        }
      }

      tmp = check;
      ok = true;
      rep(k, 0, hb) {
        rep(l, 0, wb) {
          if (i + k > 20 + hx || j + l > 20 + wx) continue;

          if (b[k][l] == '#' && x[i + k][j + l] == '.') {
            tmp[i + k][j + l] = 0;
            ok = false;
            break;
          } else {
            if (b[k][l] == '#' && b[k][l] == x[i + k][j + l]) {
              tmp[i + k][j + l] = 1;
            }
          }
        }
      }
      if (ok) {
        check = tmp;
        bb = true;
        rep(k, 0, hb) {
          rep(l, 0, wb) {
            if (b[k][l] == '#') bc[k][l] = 1;
          }
        }
      }
    }
  }

  // rep(i, 0, hx + 20) {
  // rep(j, 0, wx + 20) { printf("%d ", check[i][j]); }
  //   cout << "\n";
  // }

  rep(i, 0, ha) {
    rep(j, 0, wa) {
      if (a[i][j] == '#' && ac[i][j] == 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  rep(i, 0, hb) {
    rep(j, 0, wb) {
      if (b[i][j] == '#' && bc[i][j] == 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  rep(i, 0, 21 + hx) {
    rep(j, 0, 21 + wx) {
      if ((x[i][j] == '#' && !check[i][j])) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}
