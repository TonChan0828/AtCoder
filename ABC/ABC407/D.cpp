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
  int h, w;
  cin >> h >> w;
  vector a(h, vector<ll>(w));
  ll ans = 0;
  rep(i, 0, h) rep(j, 0, w) {
    cin >> a[i][j];
    ans ^= a[i][j];
  }

  vector v(h, vector<bool>(w, false));
  auto f = [&](auto f, int i, int j, ll res) -> void {
    ans = max(ans, res);
    if (i == h - 1 && j == w - 1) {
      // cout << "   " << res << endl;

      // rep(x, 0, h) {
      //   rep(y, 0, w) {
      //     if (v[x][y]) {
      //       cout << 1;
      //     } else {
      //       cout << 0;
      //     }
      //   }
      //   cout << "\n";
      // }
      // cout << "\n";
      return;
    }
    // cout << i << " " << j << endl;

    if (v[i][j] == false) {
      if (i < h - 1 && v[i + 1][j] == false) {
        v[i][j] = true, v[i + 1][j] = true;
        res ^= a[i][j], res ^= a[i + 1][j];
        if (j < w - 1) {
          // cout << " " << 1 << endl;
          f(f, i, j + 1, res);
        } else {
          // cout << " " << 2 << endl;
          f(f, i + 1, 0, res);
        }
        v[i][j] = false, v[i + 1][j] = false;
        res ^= a[i][j], res ^= a[i + 1][j];
      }

      if (j < w - 1 && v[i][j + 1] == false) {
        v[i][j] = true, v[i][j + 1] = true;
        res ^= a[i][j], res ^= a[i][j + 1];
        // cout << " " << 3 << endl;
        f(f, i, j + 1, res);
        v[i][j] = false, v[i][j + 1] = false;
        res ^= a[i][j], res ^= a[i][j + 1];
      }
    }

    if (j < w - 1) {
      // cout << " " << 4 << endl;
      f(f, i, j + 1, res);
    } else {
      // cout << " " << 5 << endl;
      f(f, i + 1, 0, res);
    }
  };

  f(f, 0, 0, ans);
  cout << ans << endl;
  return 0;
}
