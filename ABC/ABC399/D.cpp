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

using P = pair<int, int>;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    rep(i, 0, 2 * n) {
      cin >> a[i];
      --a[i];
    }

    vector<vector<int>> is(n);
    rep(i, 0, 2 * n) is[a[i]].push_back(i);

    set<P> cand;
    rep(i, 0, 2 * n - 1) {
      int x = a[i], y = a[i + 1];
      if (x == y) continue;
      if (x > y) swap(x, y);
      cand.emplace(x, y);
    }

    int ans = 0;

    for (auto [x, y] : cand) {
      int xl = is[x][0], xr = is[x][1];
      int yl = is[y][0], yr = is[y][1];
      if (xl + 1 == xr) continue;
      if (yl + 1 == yr) continue;

      if (abs(xl - yl) == 1 && abs(xr - yr) == 1) ++ans;
    }

    cout << ans << endl;
  }
  return 0;
}
