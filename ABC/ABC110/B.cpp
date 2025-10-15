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
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n), y(m);
  rep(i, 0, n) cin >> x[i];
  rep(i, 0, m) cin >> y[i];

  rep(z, X + 1, Y + 1) {
    bool ok = true;
    rep(i, 0, n) {
      if (z <= x[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;

    rep(i, 0, m) {
      if (y[i] < z) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "No War\n";
      return 0;
    }
  }

  cout << "War\n";
  return 0;
}
