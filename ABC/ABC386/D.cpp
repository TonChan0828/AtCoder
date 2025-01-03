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

  set<int> bx, by, wx, wy;
  vector<tuple<int, int, char>> xyc(m);
  vector<int> x(m), y(m);
  vector<char> c(m);
  rep(i, 0, m) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    xyc[i] = {x, y, c};
  }
  sort(begin(xyc), end(xyc));
  int mi = 1001001001;
  rep(i, 0, m) {
    int x = get<0>(xyc[i]), y = get<1>(xyc[i]);
    char c = get<2>(xyc[i]);
    // cout << x << " " << y << " " << c << endl;
    bool ng = false;
    if (c == 'B') {
      if (mi <= y) ng = true;
    } else {
      mi = min(mi, y);
    }

    if (ng) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
