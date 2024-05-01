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
  int n;
  cin >> n;
  vector<vector<int>> xs(2), ys(2);
  rep(i, 0, n) {
    int X, Y;
    cin >> X >> Y;
    int x = X + Y, y = X - Y;
    xs[x % 2].push_back(x);
    ys[x % 2].push_back(y);
  }

  ll ans = 0;
  auto f = [](vector<int> v) -> ll {
    int n = v.size();
    sort(begin(v), end(v));
    ll res = 0;
    rep(i, 0, n) {
      ll co = i - (n - i - 1);
      res += co * v[i];
    }
    return res / 2;
  };
  rep(i, 0, 2) ans += f(xs[i]) + f(ys[i]);
  cout << ans << endl;
}
