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
  int n, k;
  cin >> n >> k;
  vector<double> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];

  vector flag(n, vector<bool>(n, true));
  int ans = 0;
  rep(i, 0, n - 1) {
    rep(j, i + 1, n) {
      if (!flag[i][j]) continue;
      int cnt = 2;
      vector<int> list;
      list.push_back(i);
      list.push_back(j);
      rep(l, j + 1, n) {
        if ((y[l] - y[i]) * (x[j] - x[i]) == (y[j] - y[i]) * (x[l] - x[i])) {
          ++cnt;
          list.push_back(l);
        }
      }
      rep(l, 0, cnt) { rep(m, l + 1, cnt) flag[list[l]][list[m]] = false; }
      if (cnt >= k) {
        // cout << i << " " << j << endl;
        ++ans;
      }
    }
  }
  if (k == 1) {
    cout << "Infinity" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
