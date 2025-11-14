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
  int n;
  cin >> n;
  vector<ll> w(n), h(n), b(n);
  rep(i, 0, n) cin >> w[i] >> h[i] >> b[i];

  vector<ll> dp{0}, prev;
  rep(i, 0, n) {
    swap(dp, prev);
    const auto M = size(prev);
    dp.resize(M + w[i]);
    rep(j, 0, M) {
      dp[j] = max(dp[j], prev[j] + h[i]);
      dp[j + w[i]] = max(dp[j + w[i]], prev[j] + b[i]);
    }
  }

  cout << ranges::max(dp | views::drop(size(dp) / 2)) << endl;
  return 0;
}
