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
  vector<string> c(h);
  rep(i, 0, h) cin >> c[i];

  vector<vector<int>> x(h, vector<int>(26)), y(w, vector<int>(26));
  rep(i, 0, h) {
    rep(j, 0, w) {
      x[i][c[i][j] - 'a']++;
      y[j][c[i][j] - 'a']++;
    }
  }
  int hc = h, wc = w;
  vector<bool> fx(h), fy(w);
  rep(q, 0, h + w) {
    vector<pair<int, int>> ux, uy;
    rep(i, 0, h) {
      if (fx[i]) continue;
      rep(j, 0, 26) {
        if (x[i][j] == wc && wc >= 2) ux.push_back({i, j});
      }
    }
    rep(i, 0, w) {
      if (fy[i]) continue;
      rep(j, 0, 26) {
        if (y[i][j] == hc && hc >= 2) uy.push_back({i, j});
      }
    }

    for (auto p : ux) {
      fx[p.first] = true;
      rep(i, 0, w) y[i][p.second]--;
      hc--;
    }
    for (auto p : uy) {
      fy[p.first] = true;
      rep(i, 0, h) x[i][p.second]--;
      wc--;
    }
  }
  cout << hc * wc << endl;
  return 0;
}
