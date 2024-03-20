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

const ll INF = 1e18;

struct D {
  ll val;
  int col;
  D(ll val = -INF, int col = -1) : val(val), col(col) {}
};

struct Top2 {
  D a, b;
  Top2(D a = D(), D b = D(-INF, -2)) : a(a), b(b) {}
  void operator<=(D d) {
    if (b.val < d.val) {
      swap(b, d);
      if (a.val < b.val) swap(a, b);
    }
    if (a.col == b.col) b = d;
  }

  void operator<=(Top2 x) {
    *this <= x.a;
    *this <= x.b;
  }

  ll get(int c) {
    if (a.col == c) {
      return b.val;
    } else {
      return a.val;
    }
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  vector<ll> v(n);
  rep(i, 0, n) cin >> c[i] >> v[i];

  vector<Top2> dp(k + 1);
  dp[0] = Top2(D(0, -1));

  rep(i, 0, n) {
    vector<Top2> old(k + 1);
    swap(old, dp);
    rep(j, 0, k + 1) {
      if (j < k) dp[j + 1] <= old[j];
      dp[j] <= D(old[j].get(c[i]) + v[i], c[i]);
    }
  }

  ll ans = dp[k].a.val;
  if (ans < 0) ans = -1;
  cout << ans << endl;

  return 0;
}
