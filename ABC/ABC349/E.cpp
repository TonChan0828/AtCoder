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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  using vi = vector<int>;
  using vvi = vector<vi>;
  vector a(3, vector<int>(3));
  rep(i, 0, 3) rep(j, 0, 3) cin >> a[i][j];

  auto win = [&](vvi b) -> bool {
    rep(ri, 0, 2) {
      rep(i, 0, 3) {
        bool ok = true;
        rep(j, 0, 3) if (b[i][j] != 1) ok = false;
        if (ok) return true;
      }
      if (b[0][0] == 1 && b[1][1] == 1 && b[2][2] == 1) return true;
      vvi old = b;
      rep(i, 0, 3) rep(j, 0, 3) b[i][j] = old[2 - j][i];
    }
    return false;
  };

  auto f = [&](auto f, vvi b) -> bool {
    bool end = true;
    rep(i, 0, 3) rep(j, 0, 3) if (b[i][j] == 0) end = false;
    if (end) {
      ll s = 0;
      rep(i, 0, 3) rep(j, 0, 3) s += a[i][j] * b[i][j];
      return s > 0;
    }

    rep(i, 0, 3) rep(j, 0, 3) if (b[i][j] == 0) {
      vvi nb = b;
      nb[i][j] = 1;
      if (win(nb)) return true;
      rep(ni, 0, 3) rep(nj, 0, 3) nb[ni][nj] = -nb[ni][nj];
      if (!f(f, nb)) return true;
    }
    return false;
  };

  if (f(f, vvi(3, vi(3, 0)))) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
  return 0;
}
