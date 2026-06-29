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
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  rep(i, 0, h) cin >> c[i];
  int si = 0, sj = 0, ei = h - 1, ej = w - 1;

  rep(i, 0, h) {
    bool ok = true;
    rep(j, 0, w) {
      if (c[i][j] != '.') {
        si = i;
        ok = false;
        break;
      }
    }
    if (!ok) break;
  }

  rrep(i, h - 1, 0) {
    bool ok = true;
    rep(j, 0, w) {
      if (c[i][j] != '.') {
        ei = i;
        ok = false;
        break;
      }
    }
    if (!ok) break;
  }

  rep(j, 0, w) {
    bool ok = true;

    rep(i, si, ei + 1) {
      if (c[i][j] != '.') {
        sj = j;
        ok = false;

        break;
      }
    }
    if (!ok) break;
  }
  rrep(j, w - 1, 0) {
    bool ok = true;

    rep(i, si, ei + 1) {
      if (c[i][j] != '.') {
        ej = j;
        ok = false;

        break;
      }
    }
    if (!ok) break;
  }
  // cout << si << ei << sj << ej << endl;
  rep(i, si, ei + 1) {
    rep(j, sj, ej + 1) cout << c[i][j];
    cout << endl;
  }
  return 0;
}
