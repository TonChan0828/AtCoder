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
  int n;
  cin >> n;
  vector<ll> w(n);
  vector<int> x(n);
  rep(i, 0, n) cin >> w[i] >> x[i];
  ll ans = 0;

  rep(i, 0, n) {
    int diff = x[i];
    rep(j, 9, 18) {
      ll tmp = 0;
      rep(k, 0, n) {
        int time = (24 + j + x[k] - diff) % 24;
        if (time >= 9 && time < 18) tmp += w[k];
      }
      chmax(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
