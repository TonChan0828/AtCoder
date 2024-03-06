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

const int sum = 7 * 7 * 7 * 3;

int main() {
  vector<int> v(3);
  rep(i, 0, 3) cin >> v[i];

  auto f = [&](auto a, auto b, auto c) -> bool {
    // rep(i, 0, 3) cout << a[i] << " " << b[i] << " " << c[i] << " ";
    // cout << endl;
    vector<int> vt = {sum, 0, 0};
    int x0, x1, y0, y1, z0, z1;

    // V1
    x0 = max({a[0], a[1], a[2]}), x1 = min({a[0], a[1], a[2]}) + 7;
    y0 = max({b[0], b[1], b[2]}), y1 = min({b[0], b[1], b[2]}) + 7;
    z0 = max({c[0], c[1], c[2]}), z1 = min({c[0], c[1], c[2]}) + 7;
    if (x0 < x1 && y0 < y1 && z0 < z1) {
      vt[2] = (x1 - x0) * (y1 - y0) * (z1 - z0);
    }
    vt[0] -= vt[2] * 3;

    // V2
    rep(i, 0, 2) {
      rep(j, i + 1, 3) {
        x0 = max(a[i], a[j]), x1 = min(a[i], a[j]) + 7;
        y0 = max(b[i], b[j]), y1 = min(b[i], b[j]) + 7;
        z0 = max(c[i], c[j]), z1 = min(c[i], c[j]) + 7;
        if (x0 < x1 && y0 < y1 && z0 < z1) {
          vt[1] += (x1 - x0) * (y1 - y0) * (z1 - z0) - vt[2];
        }
        // cout << " " << vt[1] << endl;
      }
    }
    vt[0] -= vt[1] * 2;

    bool ok = true;
    rep(i, 0, 3) {
      // cout << vt[i] << endl;
      if (v[i] != vt[i]) ok = false;
    }
    return ok;
  };

  vector<int> a(3, 0), b(3, 0), c(3, 0);

  rep(a1, -7, 8) {
    a[1] = a1;
    rep(b1, -7, 8) {
      b[1] = b1;
      rep(c1, -7, 8) {
        c[1] = c1;
        rep(a2, -7, 8) {
          a[2] = a2;
          rep(b2, -7, 8) {
            b[2] = b2;
            rep(c2, -7, 8) {
              c[2] = c2;
              if (f(a, b, c)) {
                cout << "Yes" << endl;
                printf("0 0 0 %d %d %d %d %d %d\n", a1, b1, c1, a2, b2, c2);
                return 0;
              }
            }
          }
        }
      }
    }
  }

  // b[1] = c[0] = 6;
  // f(a, b, c);

  cout << "No" << endl;
  return 0;
}
