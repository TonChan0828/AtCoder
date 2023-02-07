#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> dp(n, 1000000010);
  dp[0] = 0LL;
  rep(i, 0, n - 1) {
    dp[i + 1] = min(dp[i + 1], dp[i] + llabs(a[i + 1] - a[i]));
    if (i < n - 2) {
      dp[i + 2] = min(dp[i + 2], dp[i] + llabs(a[i + 2] - a[i]));
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}
