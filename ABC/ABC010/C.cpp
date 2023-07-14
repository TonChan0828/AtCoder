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
  vector<int> tx(2), ty(2);
  int t, v;
  cin >> tx[0] >> ty[0] >> tx[1] >> ty[1] >> t >> v;
  double tv = t * v;
  // cout << tv << endl;
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  bool uwaki = false;

  rep(i, 0, n) {
    double t1 = abs(tx[0] - x[i]) * abs(tx[0] - x[i]) +
                abs(ty[0] - y[i]) * abs(ty[0] - y[i]);
    double t2 = abs(tx[1] - x[i]) * abs(tx[1] - x[i]) +
                abs(ty[1] - y[i]) * abs(ty[1] - y[i]);
    // cout << t1 << " " << t2 << endl;

    if (sqrt(t1) + sqrt(t2) <= tv) {
      uwaki = true;
      break;
    }
  }

  if (uwaki) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
