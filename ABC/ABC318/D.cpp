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
  vector d(n, vector<ll>(n, 0));
  rep(i, 0, n) { rep(j, i + 1, n) cin >> d[i][j]; }
  vector<ll> dp(1 << n, 0LL);
  rep(b, 0, (1 << n) - 1) {
    int l = -1;
    rep(i, 0, n) {
      if (!(b >> i & 1)) {
        l = i;
        break;
      }
    }
    rep(i, 0, n) {
      if (!(b >> i & 1)) {
        int nb = b | (1 << l) | (1 << i);
        dp[nb] = max(dp[nb], dp[b] + d[l][i]);
      }
    }
  }
  cout << dp.back() << endl;
  return 0;
}
