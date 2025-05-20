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
  int h, w, n;
  cin >> h >> w >> n;
  vector<set<int>> x(h), y(w);
  rep(i, 0, n) {
    int xx, yy;
    cin >> xx >> yy;
    --xx, --yy;
    x[xx].insert(yy);
    y[yy].insert(xx);
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int xx;
      cin >> xx;
      --xx;
      cout << x[xx].size() << "\n";

      for (int t : x[xx]) {
        y[t].erase(xx);
      }
      x[xx].clear();
    } else {
      int yy;
      cin >> yy;
      --yy;
      cout << y[yy].size() << "\n";

      for (int t : y[yy]) {
        x[t].erase(yy);
      }
      y[yy].clear();
    }
  }
  return 0;
}
